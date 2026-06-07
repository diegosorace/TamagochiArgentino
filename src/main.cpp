// ============================================================
// main.cpp — Loop principal del Tamagotchi Argentino
//
// Arquitectura:
//   Piquetero  → lógica y stats
//   Pantalla   → renderizado y touch
//   main.cpp   → orquestación (setup/loop)
// ============================================================

#include <Arduino.h>
#include "piquetero.h"
#include "pantalla.h"

// ------------------------------------------------------------
// Objetos globales
// ------------------------------------------------------------
Piquetero  elPiquetero;
Pantalla   laPantalla;

// ------------------------------------------------------------
// Estado del loop
// ------------------------------------------------------------
static int           botonPresionado = BTN_NINGUNO;
static unsigned long tiempoBoton     = 0;
static unsigned long tiempoMensaje   = 0;
static bool          mensajeVisible  = false;
static unsigned long ultimoRedibujo  = 0;

// Frases aleatorias al picar acciones
static const char* frasesAlimentar[] = {
    "!Choripan!",
    "Dale macho",
    "Rica la grasa",
    "De parrilla!",
};
static const char* frasesJugar[] = {
    "!A cortar!",
    "!Piquete!",
    "Nadie pasa",
    "!Aguante!",
};
static const char* frasesDormir[] = {
    "...zzZZZ...",
    "Siesta obrera",
    "!A descansar!",
    "Sueño digno",
};

// ------------------------------------------------------------
// setup()
// ------------------------------------------------------------
void setup() {
    Serial.begin(115200);
    Serial.println("=== Tamagotchi Argentino v1.0 ===");
    Serial.println("Iniciando al Piquetero...");

    laPantalla.iniciar();
    laPantalla.dibujarTodo(elPiquetero);

    Serial.println("Listo para picar.");
}

// ------------------------------------------------------------
// loop()
// ------------------------------------------------------------
void loop() {
    unsigned long ahora = millis();

    // 1. Actualizar lógica del piquetero
    elPiquetero.actualizar();

    // 2. Si el estado cambió, redibujar todo
    if (elPiquetero.estadoCambio()) {
        laPantalla.dibujarTodo(elPiquetero);

        if (elPiquetero.estado() == EstadoPiquetero::MUERTO) {
            laPantalla.mostrarMensaje("PARO TOTAL - R.I.P.", COLOR_ALERTA);
            mensajeVisible = true;
            tiempoMensaje  = ahora + 99999999UL; // permanente
        }
        ultimoRedibujo = ahora;
        return;
    }

    // 3. Actualizar barras si los stats cambiaron
    if (elPiquetero.statsCambiaron()) {
        laPantalla.actualizarBarras(elPiquetero.stats());
    }

    // 4. Animar sprite idle (cada ~100ms)
    if (ahora - ultimoRedibujo > 100) {
        laPantalla.actualizarSprite(elPiquetero);
        ultimoRedibujo = ahora;
    }

    // 5. Limpiar mensaje temporal
    if (mensajeVisible && ahora > tiempoMensaje) {
        laPantalla.limpiarMensaje();
        mensajeVisible = false;
    }

    // 6. Si el piquetero murió, chequear toque para resucitar
    if (elPiquetero.estado() == EstadoPiquetero::MUERTO) {
        int boton = laPantalla.leerBoton();
        if (boton != BTN_NINGUNO) {
            elPiquetero.resucitar();
            laPantalla.dibujarTodo(elPiquetero);
            laPantalla.mostrarMensaje("!El piquetero resucito!", COLOR_OK);
            mensajeVisible = true;
            tiempoMensaje  = ahora + 2000;
        }
        return;
    }

    // 7. Leer touch para acciones
    int boton = laPantalla.leerBoton();

    if (boton != BTN_NINGUNO && botonPresionado == BTN_NINGUNO) {
        // Nuevo toque
        botonPresionado = boton;
        tiempoBoton     = ahora;
        laPantalla.destacarBoton(boton);

        // Ejecutar acción
        const char* frase = nullptr;
        switch (boton) {
            case BTN_ALIMENTAR:
                elPiquetero.alimentar();
                frase = frasesAlimentar[random(4)];
                break;
            case BTN_JUGAR:
                elPiquetero.jugar();
                frase = frasesJugar[random(4)];
                break;
            case BTN_DORMIR:
                elPiquetero.dormir();
                frase = frasesDormir[random(4)];
                break;
        }

        if (frase) {
            laPantalla.mostrarMensaje(frase, 0xFFE0);
            mensajeVisible = true;
            tiempoMensaje  = ahora + 2000;
        }

        // Redibujar barras inmediatamente tras la acción
        laPantalla.actualizarBarras(elPiquetero.stats());
        laPantalla.actualizarSprite(elPiquetero);

        Serial.printf("[Accion] Boton %d | H:%d A:%d E:%d\n",
            boton,
            elPiquetero.stats().hambre,
            elPiquetero.stats().animo,
            elPiquetero.stats().energia);
    }

    // Soltar botón tras 150ms (feedback visual)
    if (botonPresionado != BTN_NINGUNO && ahora - tiempoBoton > 150) {
        laPantalla.restaurarBoton(botonPresionado);
        botonPresionado = BTN_NINGUNO;
    }

    // Pequeña pausa para no saturar el I2C
    delay(20);
}
