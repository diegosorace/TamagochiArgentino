// ============================================================
// pantalla.cpp — Renderizado con Arduino_GFX + touch AXS5106L
// ============================================================

#include "pantalla.h"
#include "sprites.h"

// ------------------------------------------------------------
// Instancias globales del bus y pantalla (declaradas extern en config_pantalla.h)
// Misma configuración que el proyecto JARVIS
// ------------------------------------------------------------
Arduino_DataBus* bus = new Arduino_HWSPI(PIN_DC, PIN_CS, PIN_SCK, PIN_MOSI);

Arduino_GFX* gfx = new Arduino_ST7789(
    bus, PIN_RST,
    0,      // rotation
    false,  // IPS
    172,    // width
    320,    // height
    34,     // col_offset1 (confirmado en JARVIS)
    0,      // row_offset1
    34,     // col_offset2
    0       // row_offset2
);

// ------------------------------------------------------------
// Touch AXS5106L — protocolo I2C
// Registros: [0]=gesture, [1]=count, [2]=xH, [3]=xL, [4]=yH, [5]=yL
// ------------------------------------------------------------
bool Pantalla::_leerTouchRaw(int16_t& tx, int16_t& ty) {
    Wire.beginTransmission(TOUCH_I2C_ADDR);
    Wire.write(0x00);
    if (Wire.endTransmission(false) != 0) return false;

    Wire.requestFrom((uint8_t)TOUCH_I2C_ADDR, (uint8_t)6);
    if (Wire.available() < 6) return false;

    uint8_t buf[6];
    for (int i = 0; i < 6; i++) buf[i] = Wire.read();

    uint8_t count = buf[1] & 0x0F;
    if (count == 0) return false;

    tx = ((int16_t)(buf[2] & 0x0F) << 8) | buf[3];
    ty = ((int16_t)(buf[4] & 0x0F) << 8) | buf[5];
    return (tx < ANCHO && ty < ALTO);
}

bool Pantalla::_tocandoBoton(int16_t tx, int16_t ty, int id) {
    int16_t bx;
    switch (id) {
        case BTN_ALIMENTAR: bx = BOTON_1_X; break;
        case BTN_JUGAR:     bx = BOTON_2_X; break;
        case BTN_DORMIR:    bx = BOTON_3_X; break;
        default: return false;
    }
    return (tx >= bx && tx <= bx + BOTON_W &&
            ty >= BOTON_Y && ty <= BOTON_Y + BOTON_H);
}

// ------------------------------------------------------------
// Inicialización (igual que JARVIS)
// ------------------------------------------------------------
void Pantalla::iniciar() {
    Wire.begin(PIN_TOUCH_SDA, PIN_TOUCH_SCL);
    Wire.setClock(400000);

    // Reset del touch
    pinMode(PIN_TOUCH_RST, OUTPUT);
    digitalWrite(PIN_TOUCH_RST, LOW);
    delay(10);
    digitalWrite(PIN_TOUCH_RST, HIGH);
    delay(50);

    // Pantalla
    if (!gfx->begin()) {
        Serial.println("ERROR: no se pudo iniciar la pantalla");
        while (1);
    }
    lcd_reg_init();

    // Backlight
    pinMode(PIN_BL, OUTPUT);
    digitalWrite(PIN_BL, HIGH);

    gfx->fillScreen(COLOR_FONDO);
    gfx->invertDisplay(true);  // igual que JARVIS

    _dibujarFondo();
    _dibujarBotones();
}

// ------------------------------------------------------------
// Render completo
// ------------------------------------------------------------
void Pantalla::dibujarTodo(const Piquetero& piq) {
    gfx->fillScreen(COLOR_FONDO);
    _dibujarFondo();
    _dibujarSprite(piq.estado());
    actualizarBarras(piq.stats());
    _dibujarBotones();
}

// ------------------------------------------------------------
// Animación idle del sprite
// ------------------------------------------------------------
void Pantalla::actualizarSprite(const Piquetero& piq) {
    if (millis() - _ultimoFrame > 600) {
        _frameIdle = !_frameIdle;
        _ultimoFrame = millis();
    }
    // Limpiar área del sprite
    gfx->fillRect(SPRITE_X - 2, SPRITE_Y - 2,
                  SPRITE_W * ESCALA + 4, SPRITE_H * ESCALA + 4, COLOR_FONDO);
    _dibujarSprite(piq.estado(), _frameIdle == 1);
}

// ------------------------------------------------------------
// Barras de stats
// ------------------------------------------------------------
void Pantalla::actualizarBarras(const Stats& stats) {
    _dibujarBarra(BARRA_X, BARRA_Y_HAMBRE,  BARRA_W, BARRA_H,
                  stats.hambre,  COLOR_BARRA_HAMBRE,  "Hambre");
    _dibujarBarra(BARRA_X, BARRA_Y_ANIMO,   BARRA_W, BARRA_H,
                  stats.animo,   COLOR_BARRA_ANIMO,   "Animo");
    _dibujarBarra(BARRA_X, BARRA_Y_ENERGIA, BARRA_W, BARRA_H,
                  stats.energia, COLOR_BARRA_ENERGIA, "Energ");
}

// ------------------------------------------------------------
// Touch
// ------------------------------------------------------------
int Pantalla::leerBoton() {
    int16_t tx, ty;
    if (!_leerTouchRaw(tx, ty)) return BTN_NINGUNO;
    for (int i = 0; i < 3; i++) {
        if (_tocandoBoton(tx, ty, i)) return i;
    }
    return BTN_NINGUNO;
}

void Pantalla::destacarBoton(int id) {
    int16_t bx; const char* txt;
    switch (id) {
        case BTN_ALIMENTAR: bx = BOTON_1_X; txt = "Comer";  break;
        case BTN_JUGAR:     bx = BOTON_2_X; txt = "Jugar";  break;
        case BTN_DORMIR:    bx = BOTON_3_X; txt = "Dormir"; break;
        default: return;
    }
    _dibujarBoton(bx, BOTON_Y, BOTON_W, BOTON_H, txt, COLOR_BOTON_PRESS);
}

void Pantalla::restaurarBoton(int id) {
    int16_t bx; const char* txt;
    switch (id) {
        case BTN_ALIMENTAR: bx = BOTON_1_X; txt = "Comer";  break;
        case BTN_JUGAR:     bx = BOTON_2_X; txt = "Jugar";  break;
        case BTN_DORMIR:    bx = BOTON_3_X; txt = "Dormir"; break;
        default: return;
    }
    _dibujarBoton(bx, BOTON_Y, BOTON_W, BOTON_H, txt, COLOR_BOTON);
}

// ------------------------------------------------------------
// Mensajes
// ------------------------------------------------------------
void Pantalla::mostrarMensaje(const char* msg, uint16_t color) {
    gfx->fillRect(0, 163, ANCHO, 20, COLOR_FONDO);
    gfx->setTextColor(color);
    gfx->setTextSize(1);
    int16_t cx = (ANCHO - (int16_t)(strlen(msg) * 6)) / 2;
    gfx->setCursor(max((int16_t)0, cx), 166);
    gfx->print(msg);
}

void Pantalla::limpiarMensaje() {
    gfx->fillRect(0, 163, ANCHO, 20, COLOR_FONDO);
}

// ------------------------------------------------------------
// Privados — fondo y encabezado
// ------------------------------------------------------------
void Pantalla::_dibujarFondo() {
    gfx->setTextColor(0xFFE0);   // amarillo
    gfx->setTextSize(1);
    gfx->setCursor(18, 8);
    gfx->print("TAMAGOTCHI ARGENTINO");

    gfx->setTextColor(0x8410);   // gris
    gfx->setCursor(52, 20);
    gfx->print("El Piquetero");

    gfx->drawLine(0, 30, ANCHO, 30, 0x4208);

    gfx->setTextColor(0xAD75);
    gfx->setCursor(BARRA_X, 178);
    gfx->print("Stats:");
}

// ------------------------------------------------------------
// Selector de sprite según estado
// ------------------------------------------------------------
void Pantalla::_dibujarSprite(EstadoPiquetero estado, bool frame2) {
    const uint16_t (*sprite)[SPRITE_W] = nullptr;
    switch (estado) {
        case EstadoPiquetero::FELIZ:      sprite = frame2 ? SPRITE_FELIZ_2 : SPRITE_FELIZ_1; break;
        case EstadoPiquetero::ENOJADO:    sprite = SPRITE_ENOJADO;   break;
        case EstadoPiquetero::TRISTE:     sprite = SPRITE_TRISTE;    break;
        case EstadoPiquetero::MUERTO:     sprite = SPRITE_MUERTO;    break;
        case EstadoPiquetero::COMIENDO:   sprite = SPRITE_COMIENDO;  break;
        case EstadoPiquetero::DURMIENDO:  sprite = SPRITE_DURMIENDO; break;
        default:                          sprite = SPRITE_FELIZ_1;   break;
    }
    if (sprite) _dibujarSpriteData(sprite, SPRITE_X, SPRITE_Y);
}

// ------------------------------------------------------------
// Dibuja un sprite 32x32 escalado a ESCALA px por pixel
// Salta píxeles transparentes (magenta 0xF81F)
// ------------------------------------------------------------
void Pantalla::_dibujarSpriteData(const uint16_t sprite[][SPRITE_W],
                                  int16_t px, int16_t py) {
    for (int y = 0; y < SPRITE_H; y++) {
        for (int x = 0; x < SPRITE_W; x++) {
            uint16_t color = sprite[y][x];
            if (color == TRANSPARENTE) continue;
            gfx->fillRect(px + x * ESCALA, py + y * ESCALA,
                          ESCALA, ESCALA, color);
        }
    }
}

// ------------------------------------------------------------
// Barra de stat con etiqueta y número
// ------------------------------------------------------------
void Pantalla::_dibujarBarra(int16_t x, int16_t y, int16_t w, int16_t h,
                              uint8_t valor, uint16_t color,
                              const char* etiqueta) {
    gfx->setTextColor(0xC618);
    gfx->setTextSize(1);
    gfx->setCursor(x, y);
    gfx->print(etiqueta);
    gfx->print(":");

    int16_t barX = x + 40;
    int16_t barW = w - 52;

    gfx->fillRoundRect(barX, y, barW, h, 3, COLOR_BARRA_FONDO);

    int16_t relleno = (int16_t)((long)barW * valor / 100);
    if (relleno > 0) {
        uint16_t c = (valor < 30) ? COLOR_ALERTA : color;
        gfx->fillRoundRect(barX, y, relleno, h, 3, c);
    }
    gfx->drawRoundRect(barX, y, barW, h, 3, 0x8410);

    gfx->setTextColor(0xFFFF);
    char buf[5];
    snprintf(buf, sizeof(buf), "%3d", valor);
    gfx->setCursor(barX + barW + 3, y);
    gfx->print(buf);
}

// ------------------------------------------------------------
// Botones táctiles
// ------------------------------------------------------------
void Pantalla::_dibujarBotones() {
    _dibujarBoton(BOTON_1_X, BOTON_Y, BOTON_W, BOTON_H, "Comer",  COLOR_BOTON);
    _dibujarBoton(BOTON_2_X, BOTON_Y, BOTON_W, BOTON_H, "Jugar",  COLOR_BOTON);
    _dibujarBoton(BOTON_3_X, BOTON_Y, BOTON_W, BOTON_H, "Dormir", COLOR_BOTON);
}

void Pantalla::_dibujarBoton(int16_t x, int16_t y, int16_t w, int16_t h,
                              const char* texto, uint16_t colorFondo) {
    gfx->fillRoundRect(x, y, w, h, 6, colorFondo);
    gfx->drawRoundRect(x, y, w, h, 6, 0x8410);
    gfx->setTextColor(COLOR_BOTON_TEXTO);
    gfx->setTextSize(1);
    int16_t tx = x + (w - (int16_t)(strlen(texto) * 6)) / 2;
    int16_t ty = y + (h - 8) / 2;
    gfx->setCursor(tx, ty);
    gfx->print(texto);
}
