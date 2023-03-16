#include <iostream>
#include "listaT.h"

class Universidad
{
public:
    // Crea una universidad con su nombre, el ranking y una lista de carreras
    Universidad (string nombre, int ranking, Lista<string>* carreras);

    string obtener_nombre(); // devuelve el nombre de la universidad

    unsigned int obtener_ranking (); // devuelve el ranking

    Lista<string>* obtener_carreras (); // devuelve ptr a lista de carreras
};

//Implementar el método recomendar_universidades de la clase Buscador_universidades:
class Buscador_universidades
{
    public:
        // Post: busca en “universidades” aquellas que tienen alguna carrera de la
        // lista “vocaciones” y un ranking mayor o igual a ranking_minimo.
        // Devuelve una lista con las universidades que cumplen con estas características.
        Lista<Universidad *>* recomendar_universidades (Lista<Universidad *>* universidades, Lista<string>* vocaciones, int ranking_minimo);

        
};


bool tiene_vocacion(Lista<string>* vocaciones, Lista<string>* carreras)
{
    bool carrera_encontrada = false;

    while(!carrera_encontrada && vocaciones ->hay_siguiente())
    {
        string carrera_buscada = carreras -> siguiente();

        vocaciones->reiniciar(); //reinicio el recorrido de la lista

        //como reinicie el recorrido, vuevlo a iterar
        while(!carrera_encontrada && vocaciones ->hay_siguiente())
        {
            if(carrera_buscada == vocaciones->siguiente())
            {
                carrera_encontrada = true;
                
            }
        }

                
               
    }
     
    return carrera_encontrada;
}

Lista<Universidad *>* Buscador_universidades::recomendar_universidades(Lista<Universidad *>* universidades, Lista<string>* vocaciones, int ranking_minimo)
{
    Lista<Universidad *>* universidades_recomendadas = new Lista<Universidad*>();
    universidades ->reiniciar();
    while(universidades ->hay_siguiente()) //verifico que no esté vacia
    {
        Universidad* universidad = universidades ->siguiente();

        if(universidad ->obtener_ranking() >= ranking_minimo) //condicion de ranking
        {
            Lista<string>* carreras = universidad->obtener_carreras();
            

            if(tiene_vocacion(carreras, vocaciones))
            {
               universidades_recomendadas-> insertar(universidad, 0); //lo inserto en la primera pos
            }

        }
    }

    return universidades_recomendadas;
}