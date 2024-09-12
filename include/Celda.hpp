#ifndef CELDA_HPP
#define CELDA_HPP

const int VACIO = 0;
const int JUGADOR_1 = 1;
const int JUGADOR_2 = 2;

class Celda {
private:
    int ficha;

public:
    // Constructor.
    Celda();

    // PRE: -
    // POST: Devuelve true si la celda está ocupada (es decir, no está vacía).
    bool es_celda_ocupada();

    // PRE: La ficha debe ser válida (VACÍO, JUGADOR_1 o JUGADOR_2).
    // POST: Coloca la ficha deseada en la celda.
    void colocar_ficha(int ficha);

    // PRE: -
    // POST: Devuelve true si ambas celdas tienen la misma ficha.
    bool es_igual(Celda celda);

    // PRE: -
    // POST: Imprime por pantalla la celda, con la ficha correspondiente.
    void mostrar(char ficha_vacio, char ficha_jugador_1, char ficha_jugador_2);
};

#endif
