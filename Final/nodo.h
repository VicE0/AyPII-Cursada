#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

// El int puede ser cualquier tipo de dato
typedef int Dato;

class Nodo {
private:
    // atributos
    Dato dato;
    Nodo* siguiente;

public:
    // Constructor con parametro
    // PRE: d es un Dato valido
    // POS: crea un Nodo con d como dato y NULL en siguiente
    Nodo (Dato d);

    // Cambia el dato
    // PRE: d es un Dato valido
    // POS: cambia el dato actual por d
    void cambiar_dato (Dato d);

    // Cambia el siguiente
    // PRE: s es un puntero a Nodo valido
    // POS: cambia el siguiente por s
    void cambiar_siguiente (Nodo* s);

    // Obtiene el dato
    // PRE:
    // POS: devuelve el dato
    Dato obtener_dato( );

    // Obtiene el siguiente
    // PRE:
    // POS: devuelve el puntero siguiente
    Nodo* obtener_siguiente( );

};


Nodo::Nodo(Dato d){
    dato = d;
    siguiente = 0;
}


void Nodo::cambiar_dato(Dato d){   
    dato = d;
}


void Nodo::cambiar_siguiente(Nodo* s){
    siguiente = s;
}


Dato Nodo::obtener_dato(){
    return dato;
}


Nodo* Nodo::obtener_siguiente(){
    return siguiente;
}



#endif // NODO_H_INCLUDED
