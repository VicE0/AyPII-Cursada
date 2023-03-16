#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include <string>
#include "nodo.h"

using namespace std;

class Lista {

private:
    // atributos
    Nodo* primero;
    Nodo* actual;
    Nodo* anterior;
    int longitud;

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
    void insertar (Dato d, int pos);

    // eliminar un Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: elimina el Nodo en la posicion pos (la 1 es la primera),
    //      libera memoria y decrementa en uno la longitud
    void eliminar (int pos);

    // obtiene el DAto en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve el dato que esta en la posicion pos (la 1 es la primera)
    Dato obtener_dato (int pos);

    // cambia el DAto que esta en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: cambia el dato que esta en la posicion pos (la 1 es la primera)
    void cambiar_dato (Dato d, int pos);

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
    Dato siguiente ( );



///////////MODELO DE FINAL//////////////////////////
    //Muestra por pantalla
    //PRE: 
    //POS: Muestra la lista por pantalla
    void mostrar(); 

    //EJERCICIO 1 - Intercambia dos datos dada sus posciones
    //PRE: pos_1 y pos_2 deben ser posiciones validas
    //POS: Intercambia los datos de los nodos en las posiciones
    void intercambiar_datos(int pos_1, int pos_2);

    //EJERCICIO 2 -3
    // Lista valida
    // Une las listas en una nueva
   Lista* unir_listas(Lista& l);

    //EJERCICIO 4- 5
    //PRE:
    //POS: invierte la lista
   Lista* invertir_lista();

    //EJERCICIO 7
    //PRE:
    //POS:
    void eliminar_dato(Dato d);

    //PRE: Recibe dos datos validos, a y b
    //POS: Devuelve -1 si a < b, 0 si a = b o 1 si a > b
    int comparar_dato(Dato a, Dato b);


private:
    // devuelve un puntero al Nodo en cierta posicion
    // PRE: 0 < pos <= longitud
    // POS: devuelve un puntero al Nodo que esta en la posicion pos (la 1 es la primera)
    Nodo* obtener_nodo (int pos);

};

Lista::Lista(){
    primero = 0;
    longitud = 0;
}

Lista::Lista(const Lista& lista) : Lista(){
    *this = lista;
}

bool Lista::vacia(){
    return(longitud == 0);
}

int Lista::obtener_longitud(){
    return longitud;
}

void Lista::insertar(Dato d, int pos){

    Nodo* nuevo = new Nodo(d);
    Nodo* siguiente = primero;

    if (pos == 1){
        primero = nuevo;
    }

    else{
        Nodo* anterior = obtener_nodo(pos - 1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);    
    }

    nuevo ->cambiar_siguiente(siguiente);
    longitud++;
}

void Lista::eliminar(int pos){
    Nodo* baja = primero;
    
    if (pos == 1) 
        primero = baja->obtener_siguiente();
    else {
        Nodo* anterior = obtener_nodo(pos - 1);
        baja = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(baja->obtener_siguiente());
    }
    
    longitud--;
    delete baja;
}


Dato Lista::obtener_dato(int pos) {
    Nodo* aux = obtener_nodo(pos);
    return aux->obtener_dato();
}

void Lista::cambiar_dato(Dato d, int pos) {
    Nodo* aux = obtener_nodo(pos);
    aux->cambiar_dato(d);
}

Nodo* Lista::obtener_nodo(int pos) {
    Nodo* aux = primero;
    
    for(int i = 1; i < pos; i++)  
        aux = aux->obtener_siguiente();

    return aux;
}

Lista::~Lista() {
    while(!vacia()) 
        eliminar(1);
};



void Lista::reiniciar(){
    actual = primero;
    anterior = nullptr;

}



bool Lista::hay_siguiente(){
    return actual != nullptr;

}


// Dato Lista::siguiente(){
//     if (this ->hay_siguiente() == true)
//     {
//         anterior = actual;
//         Nodo* aux = actual;
//         Dato d = aux ->obtener_dato();
//         actual = actual -> obtener_siguiente();

//         return d;
//     }

// }


















////////////////////////MODELO DE FINAL//////////////////////////////

// Método necesario para imprimir por pantalla;
    void Lista::mostrar() {
        Nodo* aux = primero;
        std::cout << "[";
        while (aux) {
            std::cout << aux->obtener_dato() << " ";
            aux = aux->obtener_siguiente();
        }
        std::cout << "]";
        std::cout << std::endl;
    }

// EJERCICIO 1 - Método que, dadas dos posiciones, intercambia sus datos.
void Lista::intercambiar_datos(int pos_1, int pos_2){
    Dato dato_1 = this -> obtener_dato(pos_1);
    Dato dato_2 = this -> obtener_dato(pos_2);

    this -> cambiar_dato(dato_2, pos_1);
    this -> cambiar_dato(dato_1, pos_2);
}

//EJERCICIO 2 - Método que une la lista original con otra que se pasa por parámetro, modificando a la
//lista que llama. La lista pasada por parámetro va al final.
//EJERCICIO 3- Método que une la lista original con otra que se pasa por parámetro y devuelve un
//puntero a la nueva lista. La lista pasada por parámetro va al final.
Lista* Lista::unir_listas(Lista& l){

    Lista* nueva = new Lista();
    Nodo * nodo = this -> primero;
    int posicion = 1;
    
    while(nodo != NULL){

        Dato d = nodo -> obtener_dato();
        nueva ->insertar(d, posicion);
        posicion++;

        nodo = nodo ->obtener_siguiente();

        if (posicion == this->obtener_longitud() +1){
            nodo = l.primero;
        }
    }

    return nueva;
}


//EJERCICIO 4- Método que revierte la lista, modificándola (el último elemento pasa al primer lugar, etc).
//EJERCICIO 5 - Método que revierte la lista en una nueva lista, y devuelve un puntero de la misma.
Lista* Lista::invertir_lista(){

    Lista* nueva = new Lista;
    Nodo* actual = this -> primero;


    while(actual != NULL){
        Dato d = actual ->obtener_dato();
        nueva -> insertar(d,1);
        actual = actual->obtener_siguiente();

    }

    return nueva;
}

int Lista::comparar_dato(Dato a , Dato b){
    if (a < b)
        return -1;
    
    else if (a == b)
        return 0;
    else   
        return 1;
}


//EJERCICIO 7 - Método que elimina un dato: se pasa un dato por parámetro y se elimina la primera
//ocurrencia. Usar el método comparar. Si no lo encuentra no hace nada. 
void Lista::eliminar_dato(Dato d){
    bool encontrado = false;
    int i = 1;
    Nodo* aux = this ->primero;

    while(!encontrado && aux != NULL){
        Dato temp = aux ->obtener_dato();
        if(this -> comparar_dato(d, temp) == 0){
            this ->eliminar(i);
            encontrado = true;

        }
        aux = aux ->obtener_siguiente();
        i++;
        
    }



}

//EJERCICIO 8 - Método que elimina todas las ocurrencias del dato.



//EJERCICIO 9 - Método que recibe una lista por parámetro y devuelve un puntero a una nueva lista que
//es A – B (los elementos de A que no están en B), donde A es la lista original y B es la del
//parámetro.


#endif // LISTA_H_INCLUDED
