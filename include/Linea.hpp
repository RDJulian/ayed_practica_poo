#ifndef LINEA_HPP
#define LINEA_HPP

#include "Celda.hpp"

class Linea {
private:
  Celda* celdas[3];

public:
  // Constructor default.
  Linea();

  // Constructor.
  Linea(Celda* celda_1, Celda* celda_2, Celda* celda_3);

  // PRE: -
  // POST: Devuelve true si la línea es ganadora, esto es:
  // 1. Las celdas no son vacías.
  // 2. Las celdas son iguales.
  bool es_linea_ganadora();
};

#endif
