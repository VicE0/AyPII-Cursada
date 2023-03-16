#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include <string>
#include "nodoT.h"

using namespace std;

template <typename T>

class Lista {
    private:
    // atributos
    Nodo<T>* primero;
    Nodo<T>* actual;
    int longitud;

    // devuelve un puntero al Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve un puntero al Nodo que esta en la posicion pos (la 1 es la primera)
    Nodo<T>* obtener_nodo (int pos);

public:
    // Constructor sin parametros
    // PRE:
    // POS: crea una Lista de longitud 0 y primero apunta a NULL
    Lista ( );

    // Constructor de copia
    // PRE: lista es una Lista valida
    // POS: crea una Lista igual a lista
    Lista (const Lista& lista);

    // Destructor
    // PRE:
    // POS: libera la memoria solicitada
    ~Lista ( );

    // Lista vacia?
    // PRE:
    // POS: devuelve verdadero si la lista esta vacia, falso de lo contrario
    bool vacia( );

    // obtener longitud de la lista
    // PRE:
    // POS: devuelve la longitud de la lista
    int obtener_longitud( );

    // insertar un dato en cierta posicion
    // PRE: d dato valido y 0 < pos <= longitud + 1
    // POS: inserta el Dato d en la posicion pos (la 1 es la primera),
    //      inrementa en 1 la longitud
    void insertar (T  d, int pos);

    // eliminar un Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: elimina el Nodo en la posicion pos (la 1 es la primera),
    //      libera memoria y decrementa en uno la longitud
    void eliminar (int pos);

    // obtiene el DAto en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve el dato que esta en la posicion pos (la 1 es la primera)
    T obtener_dato (int pos);

    // cambia el DAto que esta en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: cambia el dato que esta en la posicion pos (la 1 es la primera)
    void cambiar_dato (T d, int pos);

    // reinicia el puntero actual a la primera posición (o nulo si la lista es vacía).
    // PRE:
    // POS: pone el puntero a la primera posición o apuntando a NULL
    void reiniciar ( );

    // consulta si hay un elemento siguiente (si el actual no apunta a NULL)
    // PRE:
    // POS: devuelve true si el actual no apunta a NULL, false de lo contrario
    bool hay_siguiente ( );

    // devuelve el siguiente elemento (el elemento que apunta actual)
    // PRE: hay_siguiente tiene que haber devuelto true previamente
    // POS: devuelve el elemento actual y avanza
    T siguiente ( );

    void mostrar();

};

template<typename T >
Lista<T>::Lista(){
    primero = 0;
    actual = 0;
    longitud = 0;
}

template<typename T >
Lista<T>::Lista(const Lista& lista) : Lista<T>()
{
    *this = lista;
}

template<typename T >
bool Lista<T>::vacia(){
    return(longitud == 0);
}

template<typename T >
int Lista<T>::obtener_longitud(){
    return longitud;
}

template<typename T >
void Lista<T>::insertar(T d, int pos){

    Nodo<T>* nuevo = new Nodo<T>(d); //pido la memoria
    Nodo<T>* siguiente = primero;

    if (pos == 0){ //Inicio de la lista => primero == nullptr
        nuevo ->cambiar_siguiente(primero);
        primero = nuevo; 
        actual = primero;
          
    }
    else{
        Nodo<T>* anterior =  obtener_nodo(pos-1);
        siguiente = anterior->obtener_siguiente();
        anterior ->cambiar_siguiente(nuevo);

    }
    // En todos los casos posibles el nuevo nodo va a apuntar al siguiente
    nuevo->cambiar_siguiente(siguiente);
    longitud++;
}


template<typename T >
T Lista<T>::obtener_dato(int pos){
    Nodo<T>* aux = primero;
    for(int i = 0; i < pos; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}

template<typename T >
Nodo<T>* Lista<T>::obtener_nodo(int pos){
    Nodo<T>* aux = primero;
    for(int i = 0; i < pos; i++){
        aux = aux ->obtener_siguiente();
    }
    return aux;

}



template<typename T >
void Lista<T>::eliminar(int pos){

    Nodo<T>* baja = primero;

    if(pos == 0){
        primero = baja->obtener_siguiente();
    }
    else{
        Nodo<T>* anterior = obtener_nodo(pos - 1);
        baja = anterior ->obtener_siguiente();
        anterior -> cambiar_siguiente(baja->obtener_siguiente());
    }
    longitud--;
    delete baja;
}


template<typename T >
void Lista<T>::cambiar_dato(T d,int pos){
    Nodo<T>* aux = obtener_nodo(pos);
    aux->cambiar_nodo(d);
}


template<typename T >
void Lista<T>::reiniciar(){ 
    actual = primero;
}


template<typename T >
bool Lista<T>::hay_siguiente(){
    return actual != nullptr;
} 

template<typename T >
T Lista<T>::siguiente(){

    Nodo<T>* aux = actual;
    aux = aux ->obtener_siguiente();

    return aux;
}

template<typename T >
void Lista<T>::mostrar(){
    Nodo<T>* aux = primero;
    for(int i = 0; i < longitud; i++){
        cout << aux->obtener_dato()<<" ";
        aux = aux ->obtener_siguiente();
    }
}




template<typename T >
Lista<T>::~Lista(){}

#endif // LISTA_H_INCLUDED