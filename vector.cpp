#include <iostream>
#include "vector.h"

// Constructor
Vector::Vector(int l) {
    //std::cout << "Constructor de Vector" << std::endl;

    largo = l;
    datos = new Dato[largo];
    inicializar(0, largo);
}


Vector::Vector(const Vector& v) {
    //std::cout << "Constructor de copia de Vector" << std::endl;

    largo = v.largo;
    datos = new Dato[largo];
    inicializar(0, largo);
    for (int i = 0; i < largo; i++)
        datos[i] = v.datos[i];
}


void Vector::inicializar(int desde, int hasta) {
    for (int i = desde; i < hasta; i++)
        datos[i] = NULO;
}

Dato Vector::consultar(int posicion) {
    return datos[posicion];
}

void Vector::cambiar(int posicion, Dato valor) {
    datos[posicion] = valor;
}

void Vector::mostrar() {
    for (int i = 0; i < largo; i++)
        std::cout << datos[i] << " ";
    std::cout << std::endl;
}

Vector::~Vector() {
    //std::cout << "Ejecuta el destructor" << std::endl;

    if (largo > 0)
        delete [] datos;
}



void Vector::agrandar(int cantidad) {
    int nueva_longitud = largo + cantidad;
    Dato* aux = new Dato[nueva_longitud];
    copiar(aux, 0, largo);
    delete [] datos;
    datos = aux;
    inicializar(largo, nueva_longitud);
    largo = nueva_longitud;
}


void Vector::copiar(Dato* pd, int desde, int hasta) {
    for (int i = desde; i < hasta; i++)
        pd[i] = datos[i];
}


Vector Vector::sumar(Vector v) {
    Vector aux(largo);
    for (int i = 0; i < largo; i++)
        aux.datos[i] = datos[i] + v.datos[i];
    return aux;
}

int Vector::prod_escalar(Vector v) {
    int total = 0;
    for (int i = 0; i < largo; i++)
        total += datos[i] * v.datos[i];
    return total;
}

Vector Vector::operator+(Vector v) {
    Vector aux(largo);
    for (int i = 0; i < largo; i++)
        aux.datos[i] = datos[i] + v.datos[i];
    aux.mostrar();
    return aux;
}

int Vector::operator*(Vector v) {
    int total = 0;
    for (int i = 0; i < largo; i++)
        total += datos[i] * v.datos[i];
    return total;
}
