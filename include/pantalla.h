#pragma once
// ============================================================
// pantalla.h — Interfaz de renderizado (LovyanGFX)
// Separa toda la lógica de dibujo del loop principal.
// ============================================================

#include <Arduino.h>
#include "config_pantalla.h"
#include "piquetero.h"

// ------------------------------------------------------------
// Colores de la UI (RGB565)
// ------------------------------------------------------------
#define COLOR_FONDO         0x0841   // gris muy oscuro
#define COLOR_BARRA_HAMBRE  0xFD20   // naranja
#define COLOR_BARRA_ANIMO   0x07E0   // verde
#define COLOR_BARRA_ENERGIA 0x001F   // azul
#define COLOR_BARRA_FONDO   0x4208   // gris medio
#define COLOR_BOTON         0x2965   // azul grisáceo
#define COLOR_BOTON_TEXTO   0xFFFF   // blanco
#define COLOR_BOTON_PRESS   0x5DEF   // azul claro (feedback táctil)
#define COLOR_TEXTO         0xFFFF
#define COLOR_ALERTA        0xF800   // rojo (stat crítico)
#define COLOR_OK            0x07E0   // verde

// ------------------------------------------------------------
// Dimensiones de la pantalla (se define en platformio.ini)
// pero alias locales para legibilidad
// ------------------------------------------------------------
#define ANCHO  PANTALLA_ANCHO   // 172
#define ALTO   PANTALLA_ALTO    // 320

// Zona del sprite (centrado horizontalmente)
#define SPRITE_X   ((ANCHO - 32) / 2)   // 70
#define SPRITE_Y   40

// Zona de barras de stats
#define BARRA_X        10
#define BARRA_W        (ANCHO - 20)
#define BARRA_H        12
#define BARRA_Y_HAMBRE  180
#define BARRA_Y_ANIMO   205
#define BARRA_Y_ENERGIA 230

// Zona de botones (3 botones en la parte inferior)
#define BOTON_Y     260
#define BOTON_H     48
#define BOTON_W     50
#define BOTON_1_X   6
#define BOTON_2_X   61
#define BOTON_3_X   116

// IDs de botones para detección táctil
#define BTN_NINGUNO   -1
#define BTN_ALIMENTAR  0
#define BTN_JUGAR      1
#define BTN_DORMIR     2

// ------------------------------------------------------------
// Clase de pantalla
// ------------------------------------------------------------
class Pantalla {
public:
    void iniciar();
    void dibujarTodo(const Piquetero& piq);

    // Dibuja solo lo que cambió (optimización)
    void actualizarSprite(const Piquetero& piq);
    void actualizarBarras(const Stats& stats);

    // Touch
    int leerBoton();           // BTN_* o BTN_NINGUNO
    void destacarBoton(int id);
    void restaurarBoton(int id);

    // Mensajes de acción (feedback visual)
    void mostrarMensaje(const char* msg, uint16_t color = COLOR_TEXTO);
    void limpiarMensaje();

private:
    // Frame de animación idle (alterna entre dos)
    uint8_t _frameIdle = 0;
    unsigned long _ultimoFrame = 0;

    void _dibujarFondo();
    void _dibujarSprite(EstadoPiquetero estado, bool frame2 = false);
    void _dibujarBarra(int16_t x, int16_t y, int16_t w, int16_t h,
                       uint8_t valor, uint16_t color, const char* etiqueta);
    void _dibujarBotones();
    void _dibujarBoton(int16_t x, int16_t y, int16_t w, int16_t h,
                       const char* texto, uint16_t colorFondo);
    void _dibujarSpritePixel(const uint16_t sprite[32][32], int16_t px, int16_t py);

    // Touch capacitivo CST816S por I2C
    bool _leerTouchRaw(int16_t& tx, int16_t& ty);
    bool _tocandoBoton(int16_t tx, int16_t ty, int id);
};
