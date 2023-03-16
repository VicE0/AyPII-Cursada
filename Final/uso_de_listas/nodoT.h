#ifndef NODOT_H
#define NODOT_H

#include <string>

using namespace std;

template <typename T>
class Nodo {
private:
    T  dato;
    Nodo<T>* siguiente;



public:

    // Constructor con parametro
    // PRE: d es un Dato valido
    // POS: crea un Nodo con d como dato y NULL en siguiente
    Nodo<T>(T d);

    // Cambia el dato
    // PRE: d es un Dato valido
    // POS: cambia el dato actual por d
    void cambiar_nodo(T d);

    // Cambia el siguiente
    // PRE: s es un puntero a Nodo valido
    // POS: cambia el siguiente por s
    void cambiar_siguiente(Nodo<T> * s);

    // Obtiene el dato
    // PRE:
    // POS: devuelve el dato
    T  obtener_dato();


    // Obtiene el siguiente
    // PRE:
    // POS: devuelve el puntero siguiente
    Nodo* obtener_siguiente();



    // //Destructor
    // ~Nodo();

};  

template <typename T>
Nodo<T>::Nodo(T  d){
    dato = d;
    siguiente = 0;
}


template <typename T>
void Nodo<T>::cambiar_nodo(T d){
    dato = d;
}

template <typename T>
T  Nodo<T>::obtener_dato()
{
    return dato;
}


template <typename T>
void Nodo<T>::cambiar_siguiente(Nodo * s){
    siguiente = s;
}

template <typename T>
Nodo<T>* Nodo<T>::obtener_siguiente(){
    return siguiente;
}


// template <typename T>
// Nodo<T>::~Nodo(){
//     delete dato;
//     dato = 0;
// }

#endif //NODOT_H