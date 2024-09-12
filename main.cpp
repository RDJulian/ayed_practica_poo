#include "Tablero.hpp"
#include <iostream>

int main() {
    Tablero tablero('X', 'O');
    tablero.colocar_ficha(1, 1);
    tablero.mostrar();
    std::cout << std::endl;
    tablero.colocar_ficha(1, 0);
    tablero.mostrar();
    std::cout << std::endl;
    tablero.colocar_ficha(0, 2);
    tablero.mostrar();
    std::cout << std::endl;
    tablero.colocar_ficha(2, 0);
    tablero.mostrar();
    std::cout << std::endl;
    tablero.colocar_ficha(0, 0);
    tablero.mostrar();
    std::cout << std::endl;
    tablero.colocar_ficha(0, 1);
    tablero.mostrar();
    std::cout << std::endl;
    tablero.colocar_ficha(2, 2);
    tablero.mostrar();
    std::cout << std::endl;
    std::cout << "Hay ganador? " << (tablero.hay_ganador() ? "Si" : "No") << std::endl;
    std::cout << "El ganador es " << tablero.obtener_ganador() << std::endl;
    return 0;
}
