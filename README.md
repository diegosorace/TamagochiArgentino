# 🇦🇷 Tamagotchi Argentino — El Piquetero

Un Tamagotchi para ESP32-C6 con pantalla táctil LCD IPS 1.47" (172×320px), protagonizado por un piquetero pixelart con toda la actitud del conurbano bonaerense.

---

## Hardware confirmado

| Componente | Detalle |
|---|---|
| Microcontrolador | ESP32-C6 (devkitc-1) |
| Pantalla | LCD IPS 1.47" — 172×320px |
| Driver de pantalla | **ST7789** — `Arduino_GFX_Library` |
| Touch | **AXS5106L** capacitivo (I2C) |
| Framework | Arduino via PlatformIO |

---

## Pines (verificados en hardware real)

### Pantalla (SPI)

| Señal | GPIO |
|---|---|
| MOSI | 2 |
| SCK | 1 |
| CS | 14 |
| DC | 15 |
| RST | 22 |
| Backlight | 23 |

### Touch AXS5106L (I2C)

| Señal | GPIO |
|---|---|
| SDA | 18 |
| SCL | 19 |
| RST | 20 |
| INT | 21 |

Todos los pines se definen en `include/config_pantalla.h`.

---

## Librería gráfica

Se usa **Arduino_GFX_Library** (igual que el proyecto JARVIS que ya funciona en el mismo hardware). La configuración de la pantalla incluye la secuencia de init de registros custom (`lcd_reg_init()`) y el offset de columnas en 34.

```cpp
Arduino_DataBus* bus = new Arduino_HWSPI(PIN_DC, PIN_CS, PIN_SCK, PIN_MOSI);
Arduino_GFX* gfx = new Arduino_ST7789(bus, PIN_RST, 0, false, 172, 320, 34, 0, 34, 0);
```

---

## Mecánicas del juego

El Piquetero tiene 3 stats que bajan con el tiempo:

| Stat | Color | Acción |
|---|---|---|
| 🍖 Hambre | Naranja | "Comer" (+30) |
| ✊ Ánimo | Verde | "Jugar" (+25) |
| 😴 Energía | Azul | "Dormir" (+40) |

### Estados visuales

| Estado | Condición |
|---|---|
| Feliz (idle animado) | Stats mínimo > 66% |
| Enojado (brazos arriba) | Stats mínimo 33–66% |
| Triste (tirado) | Stats mínimo < 33% |
| Muerto (XX en ojos) | Cualquier stat = 0 |
| Comiendo | 2s tras pulsar "Comer" |
| Durmiendo | 2s tras pulsar "Dormir" |

Tocar cualquier botón resucita al piquetero muerto.

---

## Estructura del proyecto

```
TamagochiArgentino/
├── platformio.ini          ← Arduino_GFX_Library, ESP32-C6
├── include/
│   ├── config_pantalla.h   ← Pines, init de registros, instancias GFX
│   ├── sprites.h           ← Arrays uint16_t RGB565 (32x32px, 6 sprites)
│   ├── piquetero.h         ← Lógica del Tamagotchi
│   └── pantalla.h          ← Interfaz de renderizado y touch
└── src/
    ├── main.cpp            ← setup() + loop()
    ├── piquetero.cpp       ← Stats, estados, acciones
    └── pantalla.cpp        ← Arduino_GFX + AXS5106L I2C
```

---

## Cómo compilar y subir

```bash
git clone https://github.com/diegosorace/TamagochiArgentino.git
cd TamagochiArgentino
git checkout claude/modest-pascal-J0I4w

# Compilar y subir
pio run -t upload --upload-port /dev/ttyUSB0   # Linux/Mac
pio run -t upload --upload-port COM3            # Windows

# Monitor serie
pio device monitor -b 115200
```

---

## Próximas features

- **WiFi**: dólar blue, clima y resultados de fútbol afectan los stats
- **Más personajes**: el Mate, el León, el Dólar Blue
- **Evolución**: el piquetero mejora si lo cuidás bien durante X días
- **Persistencia**: guardar stats en NVS al apagar

---

## Licencia

MIT — La cultura argentina es de todos.
