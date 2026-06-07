#pragma once
// ============================================================
// pantalla.h — Interfaz de renderizado (Arduino_GFX)
// ============================================================

#include <Arduino.h>
#include "config_pantalla.h"
#include "piquetero.h"

// ------------------------------------------------------------
// Colores UI (RGB565)
// ------------------------------------------------------------
#define COLOR_FONDO         0x0841
#define COLOR_BARRA_HAMBRE  0xFD20   // naranja
#define COLOR_BARRA_ANIMO   0x07E0   // verde
#define COLOR_BARRA_ENERGIA 0x001F   // azul
#define COLOR_BARRA_FONDO   0x4208
#define COLOR_BOTON         0x2965
#define COLOR_BOTON_TEXTO   0xFFFF
#define COLOR_BOTON_PRESS   0x5DEF
#define COLOR_TEXTO         0xFFFF
#define COLOR_ALERTA        0xF800
#define COLOR_OK            0x07E0

// ------------------------------------------------------------
// Dimensiones y layout
// ------------------------------------------------------------
#define ANCHO  172
#define ALTO   320

#define SPRITE_W    32
#define SPRITE_H    32
#define ESCALA      3    // el sprite 32x32 se dibuja a 3px/pixel → ~96x96

#define SPRITE_X   ((ANCHO - SPRITE_W * ESCALA) / 2)   // centrado
#define SPRITE_Y   35

#define BARRA_X         10
#define BARRA_W         (ANCHO - 20)
#define BARRA_H         12
#define BARRA_Y_HAMBRE  190
#define BARRA_Y_ANIMO   215
#define BARRA_Y_ENERGIA 240

#define BOTON_Y   268
#define BOTON_H   44
#define BOTON_W   50
#define BOTON_1_X 6
#define BOTON_2_X 61
#define BOTON_3_X 116

#define BTN_NINGUNO   -1
#define BTN_ALIMENTAR  0
#define BTN_JUGAR      1
#define BTN_DORMIR     2

// Transparencia: magenta en RGB565
#define TRANSPARENTE 0xF81F

// ------------------------------------------------------------
// Clase Pantalla
// ------------------------------------------------------------
class Pantalla {
public:
    void iniciar();
    void dibujarTodo(const Piquetero& piq);
    void actualizarSprite(const Piquetero& piq);
    void actualizarBarras(const Stats& stats);

    int  leerBoton();
    void destacarBoton(int id);
    void restaurarBoton(int id);

    void mostrarMensaje(const char* msg, uint16_t color = COLOR_TEXTO);
    void limpiarMensaje();

private:
    uint8_t       _frameIdle    = 0;
    unsigned long _ultimoFrame  = 0;

    void _dibujarFondo();
    void _dibujarSprite(EstadoPiquetero estado, bool frame2 = false);
    void _dibujarSpriteData(const uint16_t sprite[][SPRITE_W], int16_t px, int16_t py);
    void _dibujarBarra(int16_t x, int16_t y, int16_t w, int16_t h,
                       uint8_t valor, uint16_t color, const char* etiqueta);
    void _dibujarBotones();
    void _dibujarBoton(int16_t x, int16_t y, int16_t w, int16_t h,
                       const char* texto, uint16_t colorFondo);

    // Touch AXS5106L por I2C
    bool _leerTouchRaw(int16_t& tx, int16_t& ty);
    bool _tocandoBoton(int16_t tx, int16_t ty, int id);
};
