//La clase Lista tiene implementados los metodos que figuran en el archivo lista_con_actual.h que incluye nodo.h (notar que, con respecto al ej. 1, se le agrega un atributo (actual) y tres metodos).
//Considerar como implementada la clase Carrera a partir de la siguiente interfaz:
#include "listaT.h"
#include <iostream>

class Carrera {
public:

    /* Crea una Carrera con su nombre, cantidad de horas totales y una lista de materias */
    Carrera (string nombre, int horas_totales, Lista<string>* materias);

    /* devuelve el nombre de la Carrera */
    string obtener_nombre(); 

    /* devuelve las horas que insume la Carrera */
    unsigned int obtener_horas_totales (); 

    /* devuelve un ptr a lista de materias */
    Lista<string>* obtener_materias (); 

};


//Implementar el método recomendar_carreras de la clase Buscador_carreras, según:

class Buscador_carreras {
public:

/* 
    Post: busca en “carreras” aquellas que tienen por lo menos cinco materias de la lista “pretendidas” 
          y una cantidad de horas menor o igual a horas_maxima.
          Devuelve un puntero a una lista con las carreras que cumplen con estas características.
*/
    Lista<Carrera *>* recomendar_carreras (Lista<Carrera *>* carreras, Lista<string>* pretendidas, int horas_maxima);

    bool tiene_materias(Lista<string>* pretendidas, Lista<string>* materias);
};



bool Buscador_carreras::tiene_materias(Lista<string>* pretendidas, Lista<string>* materias)
{
    int cantidad_materias = 0;
    
    while(cantidad_materias < 5 && materias -> hay_siguiente()) //que la lista no este vacia
    {
        string materia_encontrada = materias->siguiente();
        bool cumple_carrera = false;

        pretendidas->reiniciar();

        while (pretendidas ->hay_siguiente() && !cumple_carrera)
        {
            if(materia_encontrada == pretendidas ->siguiente())
            {
                cantidad_materias++;
                cumple_carrera = true;
            }      
        }       
    }
    return(cantidad_materias >= 5);
}


/* 
    Post: busca en “carreras” aquellas que tienen por lo menos cinco materias de la lista “pretendidas” 
          y una cantidad de horas menor o igual a horas_maxima.
          Devuelve un puntero a una lista con las carreras que cumplen con estas características.
*/
Lista<Carrera *>* Buscador_carreras::recomendar_carreras (Lista<Carrera *>* carreras, Lista<string>* pretendidas, int horas_maxima)
{
    int contador = 0;

    Lista<Carrera*>* lista_carreras = new Lista<Carrera*>();

    carreras->reiniciar();
    while (carreras->hay_siguiente())
    {
        Carrera* carrera = carreras ->siguiente();

        if(carrera->obtener_horas_totales() <= horas_maxima)
        {
            Lista<string>* materias_cumplen = carrera ->obtener_materias(); //agarro la lista de materias de esa carrera
            contador++;

            if(tiene_materias(pretendidas, materias_cumplen))
            {
                for(int i = 0; i < contador; i++)
                {
                    lista_carreras ->insertar(carrera, i);
                }
            }
            else
            cout << "lista vacia" << endl;
        }
    }
    
    return lista_carreras;
}
