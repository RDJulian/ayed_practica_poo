#include "Celda.hpp"
#include <iostream>

Celda::Celda() {
    ficha = VACIO;
}

bool Celda::es_celda_ocupada() {
    return ficha != VACIO;
}

void Celda::colocar_ficha(int ficha) {
    if (ficha == VACIO || ficha == JUGADOR_1 || ficha == JUGADOR_2) {
        this->ficha = ficha;
    } else {
        // Se podría lanzar una excepción acá.
        std::cout << "La ficha no es válida." << std::endl;
    }
}

bool Celda::es_igual(Celda celda) {
    return ficha == celda.ficha;
}

void Celda::mostrar(char ficha_vacio, char ficha_jugador_1, char ficha_jugador_2) {
    char ficha;
    if (this->ficha == VACIO) {
        ficha = ficha_vacio;
    } else {
        ficha = (this->ficha == JUGADOR_1 ? ficha_jugador_1 : ficha_jugador_2);
    }
    std::cout << ficha;
}
