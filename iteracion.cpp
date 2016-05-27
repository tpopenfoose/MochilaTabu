#include "iteracion.h"
#include <iostream>
#include <vector>

using namespace std;

Iteracion::Iteracion(int c, vector<Objeto> obj)
{
    int peso = 0; 
    int valor = 0;
    cant_tipo_obj = c;
    for(int i = 0; i < c; i++){
        objetos.push_back(obj[i]);
        if(obj[i].isEsta()){
            peso = peso + obj[i].getPeso();
            valor = valor + obj[i].getValor();
        }
    }
    peso_total = peso;
    valor_total = valor;
}

void Iteracion::print_solucion() {
    cout << "El peso de la solucion tabu es de " << peso_total << endl;
    cout << "El valor de la solucion tabu es de " << valor_total << endl;
    for (int i = 0; i < cant_tipo_obj; i++) {
      objetos[i].print_esta();
    }
}

void Iteracion::setObjetos(std::vector<Objeto> objetos) {
    this->objetos = objetos;
}

std::vector<Objeto> Iteracion::getObjetos() const {
    return objetos;
}

void Iteracion::setCant_tipo_obj(int cant_tipo_obj) {
    this->cant_tipo_obj = cant_tipo_obj;
}

int Iteracion::getCant_tipo_obj() const {
    return cant_tipo_obj;
}

void Iteracion::setValor_total(int valor_total) {
    this->valor_total = valor_total;
}

int Iteracion::getValor_total() const {
    return valor_total;
}

void Iteracion::setPeso_total(int peso_total) {
    this->peso_total = peso_total;
}

int Iteracion::getPeso_total() const {
    return peso_total;
}

vector<Objeto> Iteracion::swap_cant_obj(int cantidad, int indice, vector<Objeto> obj)
{
    bool esta1 = obj[indice].isEsta();
    bool esta2 = obj[indice + 1].isEsta();
    vector<Objeto> cambiado;
    for(int i = 0; i < cantidad; i++){
        cambiado.push_back(obj[i]);
    }
    cambiado[indice].setEsta(esta2);
    cambiado[indice + 1].setEsta(esta1);
    return cambiado;
}