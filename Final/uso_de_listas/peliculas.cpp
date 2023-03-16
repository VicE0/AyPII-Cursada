#include <iostream>
#include "listaT.h"

class Pelicula 
{
    public:
        /* Crea una Pelicula con su nombre, puntaje y una lista de actores*/
        Pelicula(string nombre, int puntaje, Lista<string>* actores);

        /*devuelve el nombre de la pelicula*/
        string obtener_nombre();

        /*devuelve el puntaje*/
        int obtener_puntaje();

        /*devuelve un ptr a lista de actores*/
        Lista<string>* obtener_actores();
};


class Servicio_streaming 
{
    public:

    /*
    Post: busca en "peliculas_ofrecidas" aquellas que tienen por lo menos un actor de la lista "peliculas_vistas"
    y un puntaje mayor o igual a puntaje_minimo.
    Devuelve un puntero a una lista con las películas que cumplen con estas caracteristicas.
    */
    Lista<Pelicula*>* recomendar_peliculas(Lista<Pelicula*>* peliculas_ofrecidas, Lista<Pelicula*>* peliculas_vistas, int puntaje_minimo);
};

bool tiene_actor(Lista<string>* actores, Lista<Pelicula*>* peliculas_vistas)
{
    int cantidad_actores = 0;
    bool actor_encontrado = false;
    
    while(!actor_encontrado && actores->hay_siguiente())
    {
        string actor = actores ->siguiente();

        peliculas_vistas->reiniciar();
        while( !actor_encontrado && peliculas_vistas->hay_siguiente())
        {
            if(actor == peliculas_vistas->siguiente()->obtener_actores() ->siguiente())
            {
                actor_encontrado = true;
            }
        }
    }

    return actor_encontrado;
}

    /*
    Post: busca en "peliculas_ofrecidas" aquellas que tienen por lo menos un actor de la lista "peliculas_vistas"
    y un puntaje mayor o igual a puntaje_minimo.
    Devuelve un puntero a una lista con las películas que cumplen con estas caracteristicas.
    */
    Lista<Pelicula*>* recomendar_peliculas(Lista<Pelicula*>* peliculas_ofrecidas, Lista<Pelicula*>* peliculas_vistas, int puntaje_minimo)
    {

        Lista<Pelicula*>* pelicula_buscada = new Lista<Pelicula*>();

        peliculas_ofrecidas->reiniciar();
        while(peliculas_ofrecidas->hay_siguiente())
        {
            Pelicula* pelicula = peliculas_ofrecidas ->siguiente();

            if(pelicula ->obtener_puntaje() >= puntaje_minimo)
            {
                Lista<string>* actores = pelicula ->obtener_actores();   

                if(tiene_actor(actores, peliculas_vistas))
                {
                    pelicula_buscada -> insertar(pelicula, 0);

                }       
            }
        }

        return pelicula_buscada;
    }