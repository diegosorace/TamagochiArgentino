// ============================================================
// piquetero.cpp — Implementación de la lógica del Tamagotchi
// ============================================================

#include "piquetero.h"

Piquetero::Piquetero()
    : _estado(EstadoPiquetero::FELIZ)
    , _estadoCambio(false)
    , _statsCambio(false)
    , _animando(false)
    , _ultimoDecremento(0)
    , _finAnimacion(0)
{
    // El piquetero nace con ganas de picar
    _stats.hambre  = 80;
    _stats.animo   = 90;
    _stats.energia = 75;
}

void Piquetero::actualizar() {
    _estadoCambio = false;
    _statsCambio  = false;

    // Si está muerto no hace nada
    if (_estado == EstadoPiquetero::MUERTO) return;

    // Terminar animación de acción
    if (_animando && millis() >= _finAnimacion) {
        _animando = true;  // se apaga en _recalcularEstado
        _animando = false;
        _recalcularEstado();
    }

    // Decrementar stats cada INTERVALO_DECREMENTO_MS
    if (millis() - _ultimoDecremento >= INTERVALO_DECREMENTO_MS) {
        _ultimoDecremento = millis();
        _aplicarDecremento();
        _statsCambio = true;
        _recalcularEstado();
    }
}

void Piquetero::alimentar() {
    if (_estado == EstadoPiquetero::MUERTO) return;

    _stats.hambre = min((int)_stats.hambre + AUMENTO_ALIMENTAR, STAT_MAX);
    _clampStats();
    _statsCambio = true;

    // Inicia animación de comer
    _animando    = true;
    _finAnimacion = millis() + DURACION_ANIMACION_MS;
    EstadoPiquetero anterior = _estado;
    _estado = EstadoPiquetero::COMIENDO;
    _estadoCambio = (anterior != _estado);
}

void Piquetero::jugar() {
    if (_estado == EstadoPiquetero::MUERTO) return;

    _stats.animo  = min((int)_stats.animo  + AUMENTO_JUGAR_ANIMO,  STAT_MAX);
    _stats.hambre = max((int)_stats.hambre + AUMENTO_JUGAR_HAMBRE, STAT_MIN);
    _clampStats();
    _statsCambio = true;
    _recalcularEstado();
}

void Piquetero::dormir() {
    if (_estado == EstadoPiquetero::MUERTO) return;

    _stats.energia = min((int)_stats.energia + AUMENTO_DORMIR,       STAT_MAX);
    _stats.animo   = max((int)_stats.animo   + AUMENTO_DORMIR_ANIMO, STAT_MIN);
    _clampStats();
    _statsCambio = true;

    // Inicia animación de dormir
    _animando     = true;
    _finAnimacion = millis() + DURACION_ANIMACION_MS;
    EstadoPiquetero anterior = _estado;
    _estado = EstadoPiquetero::DURMIENDO;
    _estadoCambio = (anterior != _estado);
}

void Piquetero::resucitar() {
    _stats.hambre  = 50;
    _stats.animo   = 50;
    _stats.energia = 50;
    _animando      = false;
    _ultimoDecremento = millis();
    _recalcularEstado();
}

// ------------------------------------------------------------
// Privados
// ------------------------------------------------------------

void Piquetero::_aplicarDecremento() {
    // Baja los stats; se clampea después
    int h = (int)_stats.hambre  - DECREMENTO_HAMBRE;
    int a = (int)_stats.animo   - DECREMENTO_ANIMO;
    int e = (int)_stats.energia - DECREMENTO_ENERGIA;

    _stats.hambre  = (uint8_t)max(h, STAT_MIN);
    _stats.animo   = (uint8_t)max(a, STAT_MIN);
    _stats.energia = (uint8_t)max(e, STAT_MIN);
}

void Piquetero::_recalcularEstado() {
    if (_animando) return; // no interrumpir animación de acción

    EstadoPiquetero nuevo;

    if (_stats.hambre == 0 || _stats.animo == 0 || _stats.energia == 0) {
        nuevo = EstadoPiquetero::MUERTO;
    } else {
        uint8_t minStat = _stats.minimo();
        if      (minStat > UMBRAL_FELIZ)   nuevo = EstadoPiquetero::FELIZ;
        else if (minStat > UMBRAL_ENOJADO) nuevo = EstadoPiquetero::ENOJADO;
        else                               nuevo = EstadoPiquetero::TRISTE;
    }

    _estadoCambio = (nuevo != _estado);
    _estado = nuevo;
}

void Piquetero::_clampStats() {
    _stats.hambre  = constrain(_stats.hambre,  STAT_MIN, STAT_MAX);
    _stats.animo   = constrain(_stats.animo,   STAT_MIN, STAT_MAX);
    _stats.energia = constrain(_stats.energia, STAT_MIN, STAT_MAX);
}
