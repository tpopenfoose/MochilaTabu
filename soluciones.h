#ifndef SOLUCIONES_H
#define SOLUCIONES_H

#include "solucion.h"
#include "mochila.h"

class Soluciones
{
private:
  int cant_soluciones;
  Mochila mochila;
  Solucion *soluciones;
  int tipos_obj;
public:
  Soluciones(int cant, Mochila bag, Solucion tabu);
  void llenar_soluciones();
  Solucion tabu_search();
}

#endif