#include "listaT.h"
#include <iostream>

class Club
{
    public:
        /*Crea un Club con su nombre, precio de cuota y una lista de actividades*/
        Club(string nombre, int precio_cuota, Lista<string>* actividades);

        /*devuelve el nombre del Club*/
        string obtener_nombre();

        /*devuelve el precio de la cuota*/
        int obtener_precio_cuota();

        /*devuelve un ptr a lista de actividades*/
        Lista<string>* obtener_actividades();
};

class Buscador_clubes 
{
    public:
        /*
        * Busca en "clubes" aquellos que tienen por lo menos tres actividades de la lista
        * "actividades_deseadas" y una cuota mensual menor o igual a cuota máxima.
        * Devuelve un puntero a una lista con los clubes que cumplen con estas caracteristicas.
        */
        Lista<Club*>* recomendar_clubes(Lista<Club*>* clubes, Lista<string>* actividades_deseadas, int cuota_maxima);

        bool tiene_actividades(Lista<string>* actividades_deseadas, Lista<string>* actividades);
     
};


bool Buscador_clubes::tiene_actividades(Lista<string>* actividades_deseadas, Lista<string>* actividades)
{
    int cantidad_actividades = 0;

    while (cantidad_actividades < 3 && actividades->hay_siguiente())
    {
       string actividad_encontrada = actividades ->siguiente();
       bool cumple = false;

       actividades_deseadas->reiniciar();

       while (!cumple && actividades_deseadas ->hay_siguiente())
       {
          if(actividad_encontrada == actividades_deseadas ->siguiente())
          {
              cantidad_actividades++;
              cumple = true;
          }
       }
       
    }

    return (cantidad_actividades >= 3);
}

        /*
        * Busca en "clubes" aquellos que tienen por lo menos tres actividades de la lista
        * "actividades_deseadas" y una cuota mensual menor o igual a cuota máxima.
        * Devuelve un puntero a una lista con los clubes que cumplen con estas caracteristicas.
        */
Lista<Club*>* Buscador_clubes::recomendar_clubes(Lista<Club*>* clubes, Lista<string>* actividades_deseadas, int cuota_maxima)
{
    Lista<Club*>* clubes_deseados = new Lista<Club*>();

    clubes ->reiniciar();
    while(clubes ->hay_siguiente())
    {
        Club* club = clubes ->siguiente();
        if(club ->obtener_precio_cuota() <= cuota_maxima)
        {
            Lista<string>* actividades = club ->obtener_actividades();

            if(tiene_actividades(actividades_deseadas, actividades))
            {
                clubes_deseados ->insertar(club, 0);
            }
        }
    }

    return clubes_deseados;
    
}