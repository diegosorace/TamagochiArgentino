// ============================================================
// pantalla.cpp — Renderizado en LovyanGFX + touch CST816S
// ============================================================

#include "pantalla.h"
#include "sprites.h"
#include <Wire.h>

// Instancia global de la pantalla (declarada extern en config_pantalla.h)
LGFX_Piquetero pantalla;

// ------------------------------------------------------------
// Touch CST816S — registros básicos por I2C
// ------------------------------------------------------------
static const uint8_t CST816S_FINGER_NUM = 0x02;
static const uint8_t CST816S_XPOS_H     = 0x03;
static const uint8_t CST816S_YPOS_H     = 0x05;

bool Pantalla::_leerTouchRaw(int16_t& tx, int16_t& ty) {
    Wire.beginTransmission(TOUCH_I2C_ADDR);
    Wire.write(CST816S_FINGER_NUM);
    if (Wire.endTransmission(false) != 0) return false;

    Wire.requestFrom((uint8_t)TOUCH_I2C_ADDR, (uint8_t)7);
    if (Wire.available() < 7) return false;

    uint8_t fingers = Wire.read();  // registro 0x02
    Wire.read();                    // 0x03 high X
    uint8_t xH = Wire.read() & 0x0F;
    uint8_t xL = Wire.read();       // 0x04 low X
    Wire.read();                    // 0x05 high Y
    uint8_t yH = Wire.read() & 0x0F;
    uint8_t yL = Wire.read();       // 0x06 low Y

    if (fingers == 0) return false;

    tx = ((int16_t)xH << 8) | xL;
    ty = ((int16_t)yH << 8) | yL;
    return true;
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
// Inicialización
// ------------------------------------------------------------

void Pantalla::iniciar() {
    // I2C para touch
    Wire.begin(PIN_TOUCH_SDA, PIN_TOUCH_SCL);
    Wire.setClock(400000);

    // Pantalla
    pantalla.init();
    pantalla.setRotation(0);    // portrait
    pantalla.setBrightness(200);
    pantalla.fillScreen(COLOR_FONDO);

    _dibujarFondo();
    _dibujarBotones();
}

// ------------------------------------------------------------
// Dibujar todo (primer render o tras cambio total)
// ------------------------------------------------------------

void Pantalla::dibujarTodo(const Piquetero& piq) {
    pantalla.fillScreen(COLOR_FONDO);
    _dibujarFondo();
    _dibujarSprite(piq.estado());
    actualizarBarras(piq.stats());
    _dibujarBotones();
}

// ------------------------------------------------------------
// Actualizar solo el sprite (animación idle)
// ------------------------------------------------------------

void Pantalla::actualizarSprite(const Piquetero& piq) {
    // Alternar frames idle cada 600ms
    if (millis() - _ultimoFrame > 600) {
        _frameIdle = !_frameIdle;
        _ultimoFrame = millis();
    }
    // Limpiar área del sprite antes de redibujar
    pantalla.fillRect(SPRITE_X - 4, SPRITE_Y - 4,
                      SPRITE_W + 8, SPRITE_H + 8, COLOR_FONDO);
    _dibujarSprite(piq.estado(), _frameIdle == 1);
}

// ------------------------------------------------------------
// Actualizar barras de stats
// ------------------------------------------------------------

void Pantalla::actualizarBarras(const Stats& stats) {
    _dibujarBarra(BARRA_X, BARRA_Y_HAMBRE,  BARRA_W, BARRA_H,
                  stats.hambre,  COLOR_BARRA_HAMBRE,  "Hambre");
    _dibujarBarra(BARRA_X, BARRA_Y_ANIMO,   BARRA_W, BARRA_H,
                  stats.animo,   COLOR_BARRA_ANIMO,   "Animo ");
    _dibujarBarra(BARRA_X, BARRA_Y_ENERGIA, BARRA_W, BARRA_H,
                  stats.energia, COLOR_BARRA_ENERGIA, "Energi");
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
    int16_t bx;
    const char* txt;
    switch (id) {
        case BTN_ALIMENTAR: bx = BOTON_1_X; txt = "Comer";  break;
        case BTN_JUGAR:     bx = BOTON_2_X; txt = "Jugar";  break;
        case BTN_DORMIR:    bx = BOTON_3_X; txt = "Dormir"; break;
        default: return;
    }
    _dibujarBoton(bx, BOTON_Y, BOTON_W, BOTON_H, txt, COLOR_BOTON_PRESS);
}

void Pantalla::restaurarBoton(int id) {
    int16_t bx;
    const char* txt;
    switch (id) {
        case BTN_ALIMENTAR: bx = BOTON_1_X; txt = "Comer";  break;
        case BTN_JUGAR:     bx = BOTON_2_X; txt = "Jugar";  break;
        case BTN_DORMIR:    bx = BOTON_3_X; txt = "Dormir"; break;
        default: return;
    }
    _dibujarBoton(bx, BOTON_Y, BOTON_W, BOTON_H, txt, COLOR_BOTON);
}

// ------------------------------------------------------------
// Mensaje de feedback
// ------------------------------------------------------------

void Pantalla::mostrarMensaje(const char* msg, uint16_t color) {
    // Zona de mensaje entre sprite y barras
    pantalla.fillRect(0, 155, ANCHO, 20, COLOR_FONDO);
    pantalla.setTextColor(color);
    pantalla.setTextSize(1);
    pantalla.setCursor((ANCHO - strlen(msg) * 6) / 2, 158);
    pantalla.print(msg);
}

void Pantalla::limpiarMensaje() {
    pantalla.fillRect(0, 155, ANCHO, 20, COLOR_FONDO);
}

// ------------------------------------------------------------
// Privados — dibujo
// ------------------------------------------------------------

void Pantalla::_dibujarFondo() {
    // Título arriba
    pantalla.setTextColor(0xFFE0);  // amarillo
    pantalla.setTextSize(1);
    pantalla.setCursor(30, 8);
    pantalla.print("TAMAGOTCHI ARGENTINO");

    // Subtítulo
    pantalla.setTextColor(0x8410);  // gris
    pantalla.setCursor(52, 20);
    pantalla.print("El Piquetero");

    // Línea separadora
    pantalla.drawLine(0, 30, ANCHO, 30, 0x4208);

    // Etiqueta de stats
    pantalla.setTextColor(0xAD75);
    pantalla.setCursor(BARRA_X, 168);
    pantalla.print("Stats:");
}

void Pantalla::_dibujarSprite(EstadoPiquetero estado, bool frame2) {
    const uint16_t (*sprite)[SPRITE_W] = nullptr;

    switch (estado) {
        case EstadoPiquetero::FELIZ:
            sprite = frame2 ? SPRITE_FELIZ_2 : SPRITE_FELIZ_1;
            break;
        case EstadoPiquetero::ENOJADO:
            sprite = SPRITE_ENOJADO;
            break;
        case EstadoPiquetero::TRISTE:
            sprite = SPRITE_TRISTE;
            break;
        case EstadoPiquetero::MUERTO:
            sprite = SPRITE_MUERTO;
            break;
        case EstadoPiquetero::COMIENDO:
            sprite = SPRITE_COMIENDO;
            break;
        case EstadoPiquetero::DURMIENDO:
            sprite = SPRITE_DURMIENDO;
            break;
        default:
            sprite = SPRITE_FELIZ_1;
            break;
    }

    if (sprite) _dibujarSpritePixel(sprite, SPRITE_X, SPRITE_Y);
}

void Pantalla::_dibujarSpritePixel(const uint16_t sprite[SPRITE_H][SPRITE_W],
                                   int16_t px, int16_t py) {
    // Escala 3x para que el sprite de 32x32 ocupe ~96x96 px
    // y sea visible en la pantalla de 172px de ancho
    const uint8_t escala = 3;

    for (int y = 0; y < SPRITE_H; y++) {
        for (int x = 0; x < SPRITE_W; x++) {
            uint16_t color = pgm_read_word(&sprite[y][x]);
            if (color == TRANSPARENTE) continue;
            pantalla.fillRect(px + x * escala, py + y * escala,
                              escala, escala, color);
        }
    }
}

void Pantalla::_dibujarBarra(int16_t x, int16_t y, int16_t w, int16_t h,
                              uint8_t valor, uint16_t color,
                              const char* etiqueta) {
    // Etiqueta
    pantalla.setTextColor(0xC618);
    pantalla.setTextSize(1);
    pantalla.setCursor(x, y - 1);
    pantalla.print(etiqueta);
    pantalla.print(":");

    int16_t barX = x + 46;
    int16_t barW = w - 46;

    // Fondo de la barra
    pantalla.fillRoundRect(barX, y, barW, h, 3, COLOR_BARRA_FONDO);

    // Relleno proporcional al valor
    int16_t relleno = (int16_t)((long)barW * valor / 100);
    if (relleno > 0) {
        // Color de alerta si está muy bajo
        uint16_t colorBarra = (valor < 30) ? COLOR_ALERTA : color;
        pantalla.fillRoundRect(barX, y, relleno, h, 3, colorBarra);
    }

    // Borde
    pantalla.drawRoundRect(barX, y, barW, h, 3, 0x8410);

    // Número
    pantalla.setTextColor(0xFFFF);
    pantalla.setCursor(barX + barW + 3, y);
    pantalla.printf("%3d", valor);
}

void Pantalla::_dibujarBotones() {
    _dibujarBoton(BOTON_1_X, BOTON_Y, BOTON_W, BOTON_H, "Comer",  COLOR_BOTON);
    _dibujarBoton(BOTON_2_X, BOTON_Y, BOTON_W, BOTON_H, "Jugar",  COLOR_BOTON);
    _dibujarBoton(BOTON_3_X, BOTON_Y, BOTON_W, BOTON_H, "Dormir", COLOR_BOTON);
}

void Pantalla::_dibujarBoton(int16_t x, int16_t y, int16_t w, int16_t h,
                              const char* texto, uint16_t colorFondo) {
    pantalla.fillRoundRect(x, y, w, h, 6, colorFondo);
    pantalla.drawRoundRect(x, y, w, h, 6, 0x8410);

    pantalla.setTextColor(COLOR_BOTON_TEXTO);
    pantalla.setTextSize(1);
    // Centrar texto en el botón
    int16_t tx = x + (w - (int16_t)(strlen(texto) * 6)) / 2;
    int16_t ty = y + (h - 8) / 2;
    pantalla.setCursor(tx, ty);
    pantalla.print(texto);
}
