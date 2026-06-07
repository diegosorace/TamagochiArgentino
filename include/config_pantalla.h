#pragma once
// ============================================================
// config_pantalla.h — Pines y configuración de la pantalla
// Basado en el proyecto JARVIS (código funcionando en tu hardware)
//
// Driver: ST7789 via Arduino_GFX_Library
// Touch:  AXS5106L via I2C
// ============================================================

#include <Arduino_GFX_Library.h>
#include <Wire.h>

// ------------------------------------------------------------
// Pines de pantalla (confirmados por tu código JARVIS)
// ------------------------------------------------------------
#define PIN_BL      23   // Backlight
#define PIN_SCK     1
#define PIN_MOSI    2
#define PIN_CS      14
#define PIN_DC      15
#define PIN_RST     22

// ------------------------------------------------------------
// Pines de touch AXS5106L (I2C)
// ------------------------------------------------------------
#define PIN_TOUCH_SDA  18
#define PIN_TOUCH_SCL  19
#define PIN_TOUCH_RST  20
#define PIN_TOUCH_INT  21
#define TOUCH_I2C_ADDR 0x3B   // Dirección estándar AXS5106L

// ------------------------------------------------------------
// Instancias de bus y pantalla (definidas en pantalla.cpp)
// ------------------------------------------------------------
extern Arduino_DataBus* bus;
extern Arduino_GFX*     gfx;

// ------------------------------------------------------------
// Secuencia de init de registros — CRÍTICA para esta pantalla
// (copiada exacta del proyecto JARVIS que ya funciona)
// ------------------------------------------------------------
inline void lcd_reg_init() {
    static const uint8_t op1[] = { BEGIN_WRITE, WRITE_COMMAND_8, 0x11, END_WRITE };
    bus->batchOperation(op1, sizeof(op1));
    delay(120);

    static const uint8_t op2[] = {
        BEGIN_WRITE,
        WRITE_C8_D16, 0xDF, 0x98, 0x53,
        WRITE_C8_D8,  0xB2, 0x23,
        WRITE_COMMAND_8, 0xB7, WRITE_BYTES, 4, 0x00, 0x47, 0x00, 0x6F,
        END_WRITE
    };
    bus->batchOperation(op2, sizeof(op2));
    yield();

    static const uint8_t op3[] = {
        BEGIN_WRITE,
        WRITE_COMMAND_8, 0xBB, WRITE_BYTES, 6, 0x1C, 0x1A, 0x55, 0x73, 0x63, 0xF0,
        WRITE_C8_D16, 0xC0, 0x44, 0xA4,
        WRITE_C8_D8,  0xC1, 0x16,
        END_WRITE
    };
    bus->batchOperation(op3, sizeof(op3));
    yield();

    static const uint8_t op4[] = {
        BEGIN_WRITE,
        WRITE_COMMAND_8, 0x21,  // Inversión de color ON
        WRITE_COMMAND_8, 0x29,  // Display ON
        END_WRITE
    };
    bus->batchOperation(op4, sizeof(op4));
}
