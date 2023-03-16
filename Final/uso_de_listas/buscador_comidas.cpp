//Consi derar como implementada la clase Alimento a partir de la siguiente interfaz:
#include <iostream>
#include "listaT.h"

class Alimento{

    private:
        string nombre;
        unsigned int calorias;
        Lista<string>* ingredientes;


    public:

        Alimento();

        // Crea un alimento con su nombre, la cantidad de calorías y una lista
        // de los ingredientes que lo conforman
        Alimento (string nombre, unsigned int calorias, Lista<string>* ingredientes);

        // devuelve el nombre del alimento
        string obtener_nombre(); 

        // devuelve la cantidad de calorías
        unsigned int obtener_calorias (); 

        // devuelve un ptr la lista de ingredientes
        Lista<string>* obtener_ingredientes ();
};

//Implementar el método comidas_para_celiacos de la clase Buscador_de_comidas:
class Buscador_de_comidas{

    private:
        unsigned int caloria_maxima;

        Lista<string>* ingredientes_permitidos;

        Lista<string>* ingredientes_no_permitidos;

    public:


        Buscador_de_comidas(unsigned int caloria_maxima, Lista<string>* ingredientes_permitidos,  Lista<string>* ingredientes_no_permitidos);
       
        bool tiene_ingredientes_aptos(Lista<string>* ingredientes, Lista<string>* ingredientes_permitidos, Lista<string>* ingredientes_no_permitidos);

    // Post: busca en “comidas” aquellas que tienen algún ingrediente de la
    // lista “ingredientes_permitidos” y ninguno de la lista
    //“ingredientes_no_permitidos”
    // y tienen una caloría menor a “caloría_maxima”.
    // Devuelve una lista con los alimentos que cumplen con estas características.
        Lista<Alimento*>* comidas_para_celiacos(Lista<Alimento *>* comidas, Lista<string>* ingredientes_permitidos, Lista<string>* ingredientes_no_permitidos, unsigned int caloria_maxima);
    
};

bool Buscador_de_comidas::tiene_ingredientes_aptos(Lista<string>* ingredientes, Lista<string>* ingredientes_permitidos, Lista<string>* ingredientes_no_permitidos)
{

    bool tiene_aptos = false;
    bool tiene_no_aptos = false;

    while(ingredientes->hay_siguiente() && !tiene_no_aptos && !tiene_aptos)
    {
        string ingrediente_buscado = ingredientes ->siguiente();

        ingredientes_no_permitidos ->reiniciar();
        while (ingredientes_no_permitidos->hay_siguiente() && !tiene_no_aptos)
        {
            
            if(ingrediente_buscado == ingredientes_no_permitidos ->siguiente())
            {
                tiene_no_aptos = true;
            }
        }
        
        ingredientes_permitidos ->reiniciar();
        while (ingredientes_permitidos ->hay_siguiente() && !tiene_aptos)
        {
            if(ingrediente_buscado == ingredientes_permitidos->siguiente())
            {
                tiene_aptos = true;
            }
        }
        
    }

    return (tiene_aptos && tiene_no_aptos);
}

   // Post: busca en “comidas” aquellas que tienen algún ingrediente de la
    // lista “ingredientes_permitidos” y ninguno de la lista
    //“ingredientes_no_permitidos”
    // y tienen una caloría menor a “caloría_maxima”.
    // Devuelve una lista con los alimentos que cumplen con estas características.

 Lista<Alimento*>* Buscador_de_comidas::comidas_para_celiacos(Lista<Alimento *>* comidas, Lista<string>* ingredientes_permitidos, Lista<string>* ingredientes_no_permitidos, unsigned int caloria_maxima)
{
    Lista<Alimento*>* comidas_buscadas = new Lista<Alimento*>();

    comidas->reiniciar();
    while (comidas ->hay_siguiente())
    {
        Alimento* alimento = comidas ->siguiente();

        if(alimento ->obtener_calorias() < caloria_maxima)
        {
            Lista<string>* ingredientes = alimento ->obtener_ingredientes();

            if(tiene_ingredientes_aptos(ingredientes, ingredientes_permitidos, ingredientes_no_permitidos))
            {
                comidas_buscadas->insertar(alimento_celiaco, 1);
            }
                
        }
    }
    
    return comidas_buscadas;
}