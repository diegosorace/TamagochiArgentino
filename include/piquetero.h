#pragma once
// ============================================================
// piquetero.h — Lógica del Tamagotchi
// El Piquetero tiene hambre, ánimo y energía. Si cualquier
// stat llega a 0, se va al paro permanente (muere).
// ============================================================

#include <Arduino.h>

// ------------------------------------------------------------
// Constantes del juego
// ------------------------------------------------------------
#define STAT_MAX          100
#define STAT_MIN          0

// Cuánto baja cada stat por unidad de tiempo
#define DECREMENTO_HAMBRE     2    // puntos por minuto
#define DECREMENTO_ANIMO      1
#define DECREMENTO_ENERGIA    1

// Cuánto sube cada acción
#define AUMENTO_ALIMENTAR     30
#define AUMENTO_JUGAR_ANIMO   25
#define AUMENTO_JUGAR_HAMBRE  (-5)  // jugar cansa y da hambre
#define AUMENTO_DORMIR        40
#define AUMENTO_DORMIR_ANIMO  (-10) // dormir aburre un poco

// Intervalo de decremento en milisegundos (1 minuto real)
#define INTERVALO_DECREMENTO_MS  60000UL

// Umbrales para cambio de estado visual
#define UMBRAL_FELIZ    66   // stats > 66% = feliz
#define UMBRAL_ENOJADO  33   // stats 33-66% = enojado
                             // stats < 33% = triste

// Duración de animación de acción (ms)
#define DURACION_ANIMACION_MS  2000

// ------------------------------------------------------------
// Estados del Piquetero
// ------------------------------------------------------------
enum class EstadoPiquetero {
    FELIZ,
    ENOJADO,
    TRISTE,
    MUERTO,
    COMIENDO,
    DURMIENDO,
    FESTEJANDO   // para futura implementación (cortando la calle)
};

// ------------------------------------------------------------
// Estructura de stats
// ------------------------------------------------------------
struct Stats {
    uint8_t hambre;   // 0 = muerto de hambre, 100 = lleno
    uint8_t animo;    // 0 = deprimido, 100 = piqueando fuerte
    uint8_t energia;  // 0 = k.o., 100 = activo

    // Devuelve el stat más bajo (el crítico)
    uint8_t minimo() const {
        return min(hambre, min(animo, energia));
    }
};

// ------------------------------------------------------------
// Clase principal del Piquetero
// ------------------------------------------------------------
class Piquetero {
public:
    Piquetero();

    void actualizar();                  // llamar en loop()
    void alimentar();
    void jugar();
    void dormir();
    void resucitar();                   // reiniciar tras muerte

    EstadoPiquetero estado() const      { return _estado; }
    const Stats&    stats() const       { return _stats; }
    bool            estadoCambio() const { return _estadoCambio; }
    bool            animacionActiva() const { return _animando; }

    // Para saber si hay que redibujar la barra de stats
    bool statsCambiaron() const         { return _statsCambio; }

private:
    Stats           _stats;
    EstadoPiquetero _estado;
    bool            _estadoCambio;  // true el frame en que cambia
    bool            _statsCambio;
    bool            _animando;

    unsigned long   _ultimoDecremento;
    unsigned long   _finAnimacion;

    void _recalcularEstado();
    void _aplicarDecremento();
    void _clampStats();
};
