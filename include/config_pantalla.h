#pragma once
// ============================================================
// config_pantalla.h — Configuración de LovyanGFX para la
// pantalla LCD IPS 1.47" con driver ST7789 / GC9107.
//
// La pantalla chica de 172x320 suele usar GC9107 o ST7789V3.
// LovyanGFX detecta ambos automáticamente si usás auto-detect,
// pero para ESP32-C6 es más seguro fijar el driver.
//
// Pines a verificar con tu módulo específico:
//   - Algunos módulos usan SPI2 (FSPI) en C6
//   - El touch capacitivo (CST816S) va por I2C
// ============================================================

#include <LovyanGFX.hpp>

// ------------------------------------------------------------
// Pines — ajustar según el PCB del módulo
// Estos son los pines más comunes en módulos ESP32-C6 + 1.47" IPS
// ------------------------------------------------------------
#define PIN_TFT_MOSI   6
#define PIN_TFT_SCLK   4
#define PIN_TFT_CS     14
#define PIN_TFT_DC     15
#define PIN_TFT_RST    21
#define PIN_TFT_BL     22   // backlight; -1 si no hay control

// Touch capacitivo CST816S por I2C
#define PIN_TOUCH_SDA  2
#define PIN_TOUCH_SCL  3
#define PIN_TOUCH_INT  1    // interrupción (opcional)
#define TOUCH_I2C_ADDR 0x15

// ------------------------------------------------------------
// Clase de configuración LovyanGFX
// Driver: ST7789 (compatible GC9107 en modo ST7789)
// ------------------------------------------------------------
class LGFX_Piquetero : public lgfx::LGFX_Device {
    lgfx::Panel_ST7789   _panel;
    lgfx::Bus_SPI        _bus;
    lgfx::Light_PWM      _luz;

public:
    LGFX_Piquetero() {
        // --- Bus SPI ---
        {
            auto cfg = _bus.config();
            cfg.spi_host    = SPI2_HOST;   // FSPI en ESP32-C6
            cfg.spi_mode    = 0;
            cfg.freq_write  = 40000000;    // 40 MHz — bajar a 20M si hay glitches
            cfg.freq_read   = 16000000;
            cfg.spi_3wire   = false;
            cfg.use_lock    = true;
            cfg.dma_channel = AUTO;
            cfg.pin_mosi    = PIN_TFT_MOSI;
            cfg.pin_miso    = -1;          // solo escritura
            cfg.pin_sclk    = PIN_TFT_SCLK;
            cfg.pin_dc      = PIN_TFT_DC;
            _bus.config(cfg);
            _panel.setBus(&_bus);
        }

        // --- Panel ST7789 (172x320) ---
        {
            auto cfg = _panel.config();
            cfg.pin_cs           = PIN_TFT_CS;
            cfg.pin_rst          = PIN_TFT_RST;
            cfg.pin_busy         = -1;
            cfg.panel_width      = 172;
            cfg.panel_height     = 320;
            // Offsets de memoria — típicos para 172x320 en ST7789
            cfg.offset_x         = 34;
            cfg.offset_y         = 0;
            cfg.offset_rotation  = 0;
            cfg.dummy_read_pixel = 8;
            cfg.dummy_read_bits  = 1;
            cfg.readable         = false;
            cfg.invert           = true;   // IPS suele necesitar inversión
            cfg.rgb_order        = false;
            cfg.dlen_16bit       = false;
            cfg.bus_shared       = false;
            _panel.config(cfg);
        }

        // --- Backlight PWM ---
        if (PIN_TFT_BL >= 0) {
            auto cfg = _luz.config();
            cfg.pin_bl      = PIN_TFT_BL;
            cfg.invert      = false;
            cfg.freq        = 1000;
            cfg.pwm_channel = 7;
            _luz.config(cfg);
            _panel.setLight(&_luz);
        }

        setPanel(&_panel);
    }
};

// Instancia global — se usa en pantalla.h
extern LGFX_Piquetero pantalla;
