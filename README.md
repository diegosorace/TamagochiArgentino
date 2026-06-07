# 🇦🇷 Tamagotchi Argentino — El Piquetero

Un Tamagotchi para ESP32-C6 con pantalla táctil LCD IPS 1.47" (172×320px), protagonizado por un piquetero pixelart con toda la actitud del conurbano bonaerense.

---

## Hardware

| Componente | Detalle |
|---|---|
| Microcontrolador | ESP32-C6 (devkitc-1) |
| Pantalla | LCD IPS 1.47" — 172×320px |
| Driver de pantalla | **ST7789** (compatible GC9107 en modo ST7789) |
| Touch | CST816S capacitivo (I2C, addr `0x15`) |
| Framework | Arduino via PlatformIO |
| Librería gráfica | [LovyanGFX](https://github.com/lovyan03/LovyanGFX) |

### ¿Por qué ST7789 y no GC9107?

La pantalla de 172×320 es un formato poco común que usan módulos económicos chinos. El IC puede ser GC9107 o ST7789V3 según el fabricante. LovyanGFX con el driver `Panel_ST7789` funciona con ambos porque:

- GC9107 responde al mismo set de comandos que ST7789 en su modo de compatibilidad.
- Si el panel no enciende o muestra colores incorrectos, probar con `invert = false` y ajustar `offset_x` a `0` o `34`.

---

## Pines de conexión

> ⚠️ Estos pines son los más comunes para módulos ESP32-C6 + pantalla 1.47". **Verificar con el esquemático de tu módulo específico** — algunos integran todo en una misma placa y los pines están fijos.

### Pantalla (SPI)

| Señal | Pin ESP32-C6 | Definido en |
|---|---|---|
| MOSI | GPIO 6 | `PIN_TFT_MOSI` |
| SCLK | GPIO 4 | `PIN_TFT_SCLK` |
| CS | GPIO 14 | `PIN_TFT_CS` |
| DC | GPIO 15 | `PIN_TFT_DC` |
| RST | GPIO 21 | `PIN_TFT_RST` |
| BL (backlight) | GPIO 22 | `PIN_TFT_BL` |

### Touch CST816S (I2C)

| Señal | Pin ESP32-C6 | Definido en |
|---|---|---|
| SDA | GPIO 2 | `PIN_TOUCH_SDA` |
| SCL | GPIO 3 | `PIN_TOUCH_SCL` |
| INT | GPIO 1 | `PIN_TOUCH_INT` |

Cambiar los pines en `include/config_pantalla.h`.

---

## Mecánicas del juego

El Piquetero tiene 3 stats que bajan con el tiempo (1 punto por minuto en modo normal):

| Stat | Color | Acción para subir |
|---|---|---|
| 🍖 **Hambre** | Naranja | Botón "Comer" (+30, choripán) |
| ✊ **Ánimo** | Verde | Botón "Jugar" (+25, picar calle) |
| 😴 **Energía** | Azul | Botón "Dormir" (+40, siesta obrera) |

### Estados visuales

| Estado | Condición |
|---|---|
| Feliz (idle animado) | Todos los stats > 66% |
| Enojado (brazos arriba) | Stats más bajo entre 33–66% |
| Triste (tirado) | Stats más bajo < 33% |
| Muerto (XX en ojos) | Cualquier stat llega a 0 |
| Comiendo | Durante 2s tras pulsar "Comer" |
| Durmiendo | Durante 2s tras pulsar "Dormir" |

Para resucitar al piquetero muerto: tocar cualquier botón.

---

## Estructura del proyecto

```
TamagochiArgentino/
├── platformio.ini          ← Configuración PlatformIO
├── include/
│   ├── config_pantalla.h   ← Clase LGFX_Piquetero (pines + driver ST7789)
│   ├── sprites.h           ← Arrays uint16_t RGB565 de los sprites
│   ├── piquetero.h         ← Interfaz de lógica (stats, estados, acciones)
│   └── pantalla.h          ← Interfaz de renderizado y touch
└── src/
    ├── main.cpp            ← setup() + loop() (orquestación)
    ├── piquetero.cpp       ← Lógica del Tamagotchi
    └── pantalla.cpp        ← Renderizado LovyanGFX + touch CST816S
```

---

## Cómo compilar y subir

```bash
# Instalar PlatformIO CLI si no lo tenés
pip install platformio

# Compilar
pio run

# Compilar y subir (reemplazar /dev/ttyUSB0 con tu puerto)
pio run -t upload --upload-port /dev/ttyUSB0

# Monitor serie
pio device monitor -b 115200
```

En Arduino IDE: instalar la librería `LovyanGFX` desde el gestor de librerías y copiar los archivos de `src/` e `include/` a tu sketch.

---

## Ajuste fino de la pantalla

Si la imagen se ve desplazada o con colores incorrectos, en `include/config_pantalla.h` modificar:

```cpp
cfg.offset_x  = 34;   // probar 0 o 34 según módulo
cfg.offset_y  = 0;
cfg.invert    = true;  // probar false si los colores están invertidos
```

Para cambiar la velocidad de decremento de stats (más rápido = más difícil), en `include/piquetero.h`:

```cpp
#define DECREMENTO_HAMBRE   2   // puntos por minuto
#define DECREMENTO_ANIMO    1
#define DECREMENTO_ENERGIA  1
```

---

## Próximas features (arquitectura preparada)

- **WiFi**: dólar blue, clima y resultados de River/Boca afectan los stats
- **Más personajes**: el Mate, el León, el Dólar Blue
- **Evolución**: el piquetero mejora si lo cuidás bien durante X días
- **Sonido**: buzzer para eventos importantes
- **Persistencia**: guardar stats en NVS al apagar

---

## Licencia

MIT — Usalo, modificalo, distribuilo. La cultura argentina es de todos.
