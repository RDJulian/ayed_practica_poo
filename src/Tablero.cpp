#include "Tablero.hpp"
#include <iostream>

Tablero::Tablero(char ficha_jugador_1, char ficha_jugador_2) {
    this->ficha_jugador_1 = ficha_jugador_1;
    this->ficha_jugador_2 = ficha_jugador_2;
    es_turno_jugador_1 = true;
    /* Uso memoria dinámica para que las celdas del tablero
     * sean "las mismas" que las de las líneas. */
    for (int i = 0; i < TAMANIO_TABLERO; ++i) {
        for (int j = 0; j < TAMANIO_TABLERO; ++j) {
            tablero[i][j] = new Celda();
        }
    }
    // Combinaciónes de líneas ganadoras.
    lineas[0] = Linea(tablero[0][0], tablero[0][1], tablero[0][2]);
    lineas[1] = Linea(tablero[1][0], tablero[1][1], tablero[1][2]);
    lineas[2] = Linea(tablero[2][0], tablero[2][1], tablero[2][2]);
    lineas[3] = Linea(tablero[0][0], tablero[1][0], tablero[2][0]);
    lineas[4] = Linea(tablero[0][1], tablero[1][1], tablero[2][1]);
    lineas[5] = Linea(tablero[0][2], tablero[1][2], tablero[2][2]);
    lineas[6] = Linea(tablero[0][0], tablero[1][1], tablero[2][2]);
    lineas[7] = Linea(tablero[0][2], tablero[1][1], tablero[2][0]);
}

bool Tablero::es_jugada_valida(size_t i, size_t j) {
    // Delegación: Tablero delega a la celda si está ocupada.
    return i < TAMANIO_TABLERO
           && j < TAMANIO_TABLERO
           && !tablero[i][j]->es_celda_ocupada()
           && !hay_ganador();
}

void Tablero::colocar_ficha(size_t i, size_t j) {
    if (es_jugada_valida(i, j)) {
        int ficha = (es_turno_jugador_1 ? JUGADOR_1 : JUGADOR_2);
        tablero[i][j]->colocar_ficha(ficha);
        es_turno_jugador_1 = !es_turno_jugador_1;
    } else {
        // Se podría lanzar una excepción acá.
        std::cout << "La jugada no es válida." << std::endl;
    }
}

bool Tablero::hay_ganador() {
    return obtener_ganador() != FICHA_VACIO;
}

char Tablero::obtener_ganador() {
    char ganador = FICHA_VACIO;
    size_t i = 0;
    // Delegación: Tablero delega a las líneas determinar si alguien ganó.
    while (ganador == FICHA_VACIO && i < CANTIDAD_LINEAS_GANADORAS) {
        if (lineas[i].es_linea_ganadora()) {
            // Si es el turno del jugador 1, pero perdió, el ganador es el jugador 2.
            ganador = (es_turno_jugador_1 ? ficha_jugador_2 : ficha_jugador_1);
        }
        i++;
    }
    return ganador;
}

void Tablero::reiniciar_tablero() {
    for (int i = 0; i < TAMANIO_TABLERO; i++) {
        for (int j = 0; j < TAMANIO_TABLERO; j++) {
            // Delegación.
            tablero[i][j]->colocar_ficha(VACIO);
        }
    }
}

void Tablero::mostrar() {
    for (int i = 0; i < TAMANIO_TABLERO; ++i) {
        for (int j = 0; j < TAMANIO_TABLERO; ++j) {
            // Delegación.
            tablero[i][j]->mostrar(FICHA_VACIO, ficha_jugador_1, ficha_jugador_2);
            std::cout << "  ";
        }
        std::cout << std::endl;
    }
}

Tablero::~Tablero() {
    for (int i = 0; i < TAMANIO_TABLERO; ++i) {
        for (int j = 0; j < TAMANIO_TABLERO; ++j) {
            delete tablero[i][j];
        }
    }
}
