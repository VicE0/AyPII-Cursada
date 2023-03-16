#include "listaT.h"
#include <iostream>

class Restaurante
{
    public:

        // Crea un restaurante con su nombre, el precio promedio por cubierto y
        // una lista de platos que sirve
        Restaurante (string nombre, int precio_promedio, Lista<string>* platos);

        string obtener_nombre(); // devuelve el nombre del restaurante

        int obtener_precio_promedio (); // devuelve el precio promedio

        Lista<string>* obtener_platos (); // devuelve ptr a la lista de platos
};


//Implementar el método recomendar_restaurantes de la clase Buscador_restaurantes:

class Buscador_restaurantes
{
    public:


        // Post: busca en “restaurantes” aquellos que tienen por lo menos dos platos de la
        // lista “platos_deseados” y un precio promedio menor o igual a precio_maximo.
        // Devuelve una lista con los restaurantes que cumplen con estas características.
        Lista<Restaurante *>* recomendar_restaurantes (Lista<Restaurante *>*restaurantes, Lista<string>* platos_deseados, int precio_maximo);
};
