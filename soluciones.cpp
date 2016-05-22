#include "soluciones.h"
#include <string>
#include <iostream>

using namespace std;

Soluciones::Soluciones(int cant, Mochila bag, Solucion tabu, Objeto *obj)
{
  cant_soluciones = cant;
  mochila = bag;
  soluciones = new *Solucion();
  soluciones[0] = tabu;
  lista_obj = obj;
}

Soluciones::llenar_soluciones ()
{
  int peso = 0;
  int random = 0;
  for (int i = 0; i < cant_soluciones; i++){
    while (peso < mochila.get_peso_max()) {
      random = rand() % cant_tipo_obj;
      if(peso + lista_obj[random].get_peso() <= mochila.get_peso_max()){
        peso = peso + lista_obj[random].get_peso();
        soluciones[i].set_peso_total(peso);
        soluciones[i].set_valor_total(soluciones[i].get_valor_total() + lista_obj[random].get_valor());
      }
      else{
        break;
      }
    }
  }
}

soluciones::tabu_search()
{
  Solucion tabu = soluciones[0];
  for(int i = 1; i < cant_soluciones; i++){
    if(tabu.get_valor_total() < soluciones[i].get_valor_total()){
      tabu = soluciones[i];
    }
  }
  return tabu;
}
