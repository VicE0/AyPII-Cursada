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
        Lista<Restaurante *>* recomendar_restaurantes (Lista<Restaurante *>*
        restaurantes, Lista<string>* platos_deseados, int precio_maximo);
};


bool tiene_platos(Lista<string>* platos_deseados, Lista<string>* platos)
{
    int cantidad_deseados = 0;
    bool encontrado = false;

    while (cantidad_deseados < 2 && platos ->hay_siguiente())
    {
        string plato_encontrado = platos -> siguiente(); //voy iterando

        platos_deseados ->reiniciar();
        while(!encontrado && platos_deseados ->hay_siguiente())
        {
            if(plato_encontrado == platos_deseados -> siguiente())
            {
                cantidad_deseados++;
                encontrado = true;
            }
        }
    }
    return(cantidad_deseados >= 2);
}


Lista<Restaurante *>* recomendar_restaurantes (Lista<Restaurante *>*restaurantes, Lista<string>* platos_deseados, int precio_maximo)
{
    Lista<Restaurante*>* restaurantes_recomendados = new Lista<Restaurante*>();
    int contador = 0;

    restaurantes ->reiniciar();
    while(restaurantes ->hay_siguiente())
    {
        Restaurante* restaurante = restaurantes ->siguiente();

        if (restaurante ->obtener_precio_promedio() <= precio_maximo)
        {
            Lista<string>* platos = restaurante ->obtener_platos();
            contador++;

            for(int i = 0; i < contador; i++)
            {
                if (tiene_platos(platos_deseados, platos))
                {
                    restaurantes_recomendados ->insertar(restaurante, i);
                }
            }          
        }
    }
    return restaurantes_recomendados;
}