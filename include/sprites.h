#pragma once
// ============================================================
// sprites.h — Sprites del Piquetero en pixelart 32x32
//
// Formato: uint16_t RGB565 (nativo de ST7789/LovyanGFX)
// Transparencia: 0xF81F (magenta) = píxel transparente
//
// Paleta del Piquetero:
//   - Piel:       0xFD20  (naranja cálido)
//   - Camisa:     0x0400  (verde piquetero)
//   - Pantalón:   0x3186  (gris oscuro)
//   - Pañuelo:    0xF800  (rojo)
//   - Pelo/barba: 0x2945  (marrón oscuro)
//   - Choripán:   0xFD40  (pan dorado)
//   - Fondo:      0xF81F  (transparente — magenta)
// ============================================================

#include <stdint.h>

#define SPRITE_W    32
#define SPRITE_H    32
#define TRANSPARENTE 0xF81F

// Abreviaturas de colores para legibilidad del sprite
#define _T  0xF81F  // transparente
#define _P  0xFD20  // piel
#define _V  0x0400  // verde camisa
#define _G  0x3186  // gris pantalón
#define _R  0xF800  // rojo pañuelo
#define _M  0x2945  // marrón (pelo/barba)
#define _B  0x0000  // negro (ojos, contorno)
#define _C  0xFD40  // choripán/pan
#define _S  0xFFE0  // amarillo (fuego/festejo)
#define _W  0xFFFF  // blanco

// ============================================================
// SPRITE: Piquetero feliz (idle frame 1)
// ============================================================
const uint16_t SPRITE_FELIZ_1[SPRITE_H][SPRITE_W] PROGMEM = {
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_P,_P,_P,_P,_B,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_B,_B,_B,_P,_P,_B,_B,_B,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_P,_P,_P,_P,_B,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_M,_M,_M,_M,_M,_M,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_R,_R,_R,_R,_R,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_R,_R,_R,_R,_R,_R,_R,_R,_R,_R,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_P,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_P,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_P,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_P,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_P,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_P,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_P,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_G,_G,_G,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_B,_B,_B,_T,_T,_T,_T,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
};

// ============================================================
// SPRITE: Piquetero feliz (idle frame 2 — leve movimiento)
// ============================================================
const uint16_t SPRITE_FELIZ_2[SPRITE_H][SPRITE_W] PROGMEM = {
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_P,_P,_P,_P,_B,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_B,_B,_B,_P,_P,_B,_B,_B,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_P,_P,_P,_P,_B,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_M,_M,_M,_M,_M,_M,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_R,_R,_R,_R,_R,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_R,_R,_R,_R,_R,_R,_R,_R,_R,_R,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_P,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_P,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_P,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_P,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_P,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_B,_B,_B,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
};

// ============================================================
// SPRITE: Piquetero enojado (estado medio)
// ============================================================
const uint16_t SPRITE_ENOJADO[SPRITE_H][SPRITE_W] PROGMEM = {
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // cejas enojadas (inclinadas hacia adentro)
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_B,_B,_P,_P,_P,_P,_P,_B,_B,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_P,_P,_P,_P,_B,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // ojos fruncidos
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_B,_P,_P,_P,_B,_B,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // boca recta (enojado)
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_B,_B,_B,_B,_B,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_R,_R,_R,_R,_R,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_R,_R,_R,_R,_R,_R,_R,_R,_R,_R,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // brazos levantados (protesta)
    {_T,_T,_T,_T,_P,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_P,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_P,_P,_P,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_P,_P,_P,_T,_T,_T,_T,_T,_T},
    {_T,_T,_P,_P,_P,_P,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_P,_P,_P,_T,_T,_T,_T,_T},
    {_T,_T,_T,_P,_P,_P,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_P,_P,_P,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_P,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_P,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_B,_B,_B,_T,_T,_T,_T,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
};

// ============================================================
// SPRITE: Piquetero triste (tirado en el piso)
// ============================================================
const uint16_t SPRITE_TRISTE[SPRITE_H][SPRITE_W] PROGMEM = {
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // Cabeza de lado (tirado)
    {_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_P,_P,_B,_P,_P,_B,_P,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // ojos mirando hacia abajo (triste)
    {_T,_T,_T,_T,_M,_P,_B,_B,_B,_B,_B,_B,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // boca hacia abajo (triste)
    {_T,_T,_T,_T,_M,_P,_B,_P,_P,_P,_P,_P,_B,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_P,_P,_B,_B,_B,_B,_B,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_M,_P,_P,_R,_R,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_M,_M,_R,_R,_R,_R,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // cuerpo extendido (tirado)
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
};

// ============================================================
// SPRITE: Piquetero muerto (XX en los ojos)
// ============================================================
const uint16_t SPRITE_MUERTO[SPRITE_H][SPRITE_W] PROGMEM = {
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // Cabeza de lado (muerto, igual que triste pero con XX)
    {_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // ojos XX
    {_T,_T,_T,_T,_M,_P,_B,_P,_B,_P,_B,_P,_B,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_P,_P,_B,_P,_P,_P,_B,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_P,_B,_P,_B,_P,_B,_P,_B,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // boca recta
    {_T,_T,_T,_T,_M,_P,_P,_P,_B,_B,_B,_B,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_M,_P,_P,_R,_R,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_M,_M,_R,_R,_R,_R,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // cuerpo extendido
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // estrellitas de muerto
    {_T,_S,_T,_S,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_S,_T,_S,_T,_T,_T,_T,_T,_T},
    {_S,_T,_S,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_S,_T,_S,_T,_T,_T,_T,_T,_T,_T},
    {_T,_S,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_S,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
};

// ============================================================
// SPRITE: Piquetero comiendo (choripán en mano)
// ============================================================
const uint16_t SPRITE_COMIENDO[SPRITE_H][SPRITE_W] PROGMEM = {
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // ojos entrecerrados (disfrutando)
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_B,_P,_P,_P,_B,_B,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // boca abierta (comiendo)
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_B,_B,_B,_B,_B,_B,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_B,_W,_W,_W,_W,_W,_W,_B,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_P,_P,_P,_B,_B,_B,_B,_B,_B,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_M,_M,_P,_P,_R,_R,_R,_R,_R,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_R,_R,_R,_R,_R,_R,_R,_R,_R,_R,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_P,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // brazo izquierdo levantado con choripán
    {_C,_C,_C,_C,_C,_P,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_C,_C,_P,_P,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_P,_P,_P,_P,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_P,_P,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_P,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_P,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_G,_G,_T,_T,_T,_T,_G,_G,_G,_T,_T,_T,_T,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_B,_B,_B,_T,_T,_T,_T,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
};

// ============================================================
// SPRITE: Piquetero durmiendo (Zzz)
// ============================================================
const uint16_t SPRITE_DURMIENDO[SPRITE_H][SPRITE_W] PROGMEM = {
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // Zzz flotando
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // Cabeza de lado (durmiendo)
    {_T,_T,_T,_T,_T,_M,_M,_M,_M,_M,_M,_M,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_M,_P,_P,_P,_P,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // ojos cerrados
    {_T,_T,_T,_T,_M,_P,_B,_B,_P,_P,_B,_B,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_P,_P,_P,_P,_P,_P,_P,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // boca chica (dormido)
    {_T,_T,_T,_T,_M,_P,_P,_P,_B,_B,_B,_P,_P,_P,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_M,_M,_P,_P,_R,_R,_P,_P,_P,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_M,_M,_R,_R,_R,_R,_M,_M,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    // cuerpo extendido
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_V,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_G,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_B,_B,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
    {_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T,_T},
};

// Limpieza de macros para no contaminar otros headers
#undef _T
#undef _P
#undef _V
#undef _G
#undef _R
#undef _M
#undef _B
#undef _C
#undef _S
#undef _W
