#include "Linea.hpp"

Linea::Linea() {
    celdas[0] = nullptr;
    celdas[1] = nullptr;
    celdas[2] = nullptr;
}

Linea::Linea(Celda* celda_1, Celda* celda_2, Celda* celda_3) {
    celdas[0] = celda_1;
    celdas[1] = celda_2;
    celdas[2] = celda_3;
}

bool Linea::es_linea_ganadora() {
    // Delegación.
    return celdas[0]->es_celda_ocupada()
           && celdas[0]->es_igual(*celdas[1])
           && celdas[1]->es_igual(*celdas[2]);
}
