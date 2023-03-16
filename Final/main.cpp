#include "lista.h"
#include <iostream>

using namespace std;


int main()
{
    
    Lista l;
    Lista l2;

    Lista* l3;
   
    l.insertar(2, 1);
    l.insertar(10, 2);
    l.insertar(4, 3);
    l.mostrar();

    l2.insertar(1,1);
    l2.insertar(2,2);
    l2.insertar(3,3);
    l2.mostrar();

    l3 = l.invertir_lista();
    l3->mostrar();

    std::cout << endl;



    return 0;







}