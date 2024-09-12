#ifndef TABLERO_HPP
#define TABLERO_HPP

#include "Celda.hpp"
#include "Linea.hpp"
#include <cstddef>

const char FICHA_VACIO = '-';
const size_t TAMANIO_TABLERO = 3;
const size_t CANTIDAD_LINEAS_GANADORAS = 8;

class Tablero {
private:
    Celda* tablero[TAMANIO_TABLERO][TAMANIO_TABLERO];
    Linea lineas[CANTIDAD_LINEAS_GANADORAS];
    char ficha_jugador_1;
    char ficha_jugador_2;
    bool es_turno_jugador_1;

public:
    // Constructor.
    Tablero(char ficha_jugador_1, char ficha_jugador_2);

    // PRE: -
    // POST: Devuelve true si la jugada es válida, esto es:
    // 1. Los índices son correctos (0, 1 o 2).
    // 2. La celda no está ocupada.
    // 3. La partida no terminó.
    bool es_jugada_valida(size_t i, size_t j);

    // PRE: La jugada debe ser válida.
    // POST: Coloca la ficha en la celda deseada.
    void colocar_ficha(size_t i, size_t j);

    // PRE: -
    // POST: Devuelve true si hay algún ganador.
    bool hay_ganador();

    // PRE: -
    // POST: Devuelve la ficha del jugador ganador.
    // Si hay empate o la partida aún no terminó, devuelve la ficha vacía '-'.
    char obtener_ganador();

    // PRE: -
    // POST: Reinicia el tablero, poniendo todas las fichas en vacío.
    void reiniciar_tablero();

    // PRE: -
    // POST: Muestra el tablero por pantalla.
    void mostrar();

    // Destructor.
    ~Tablero();
};

#endif
