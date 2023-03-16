//============================================================================
// Name        : PunterosDobles.cpp
// Author      : carolina

//============================================================================

#include <iostream>
using namespace std;


void ejemplo1();
void ejemplo2();
int sumaPorCopia (int a, int b); //nunca usar nombres asi para las funciones (esto es solo a nivel didactico)
void ejemplo3();				//los nombres de las funciones no deben revelar como estan implementadas
void allocPorReferencia(int** p);
void allocPorValor(int* p);
void ejemplo4();
void matrizDinamica(int filas, int columnas);


int main()
{
    ejemplo1();

    ejemplo2();

    ejemplo3();

    ejemplo4();

    return 0;
}

//------------------Ejemplo 1------------------------------
// Demostracion de declaracion basica de punteros dobles
void ejemplo1()
{
	int numero = 123;

	cout << "\n-------------Ejemplo 1---------------------"<<endl;
    // puntero a la variable "numero"
    int *ptr1;

    // doble puntero (puntero a ptr1)
    int **ptr2;

    // dirección de almacenamiento de la variable "numero"
    // El puntero ptr1 apunta a "numero"
    ptr1 = &numero;

    // Direccion de almacenamiento del puntero "ptr1" en ptr2
    // El puntero ptr2 apunta a ptr1
    ptr2 = &ptr1;

    //Muestra el valor del numero usando
    // punteros simples y punteros dobles

    cout << "Valor de numero = " << numero << endl;
    cout << "Valor de numero usando puntero simple = " << *ptr1 << endl;
	cout << "Valor de numero usando puntero doble  = " << **ptr2 << endl;


	cout<<"El puntero doble apunta a la direccion: "<< ptr2 << endl;
	cout<<"El puntero doble apunta a la direccion: "<< &ptr1 << endl;

	cout<<"El puntero simple apunta a la direccion: " << *ptr2 <<endl;
	cout<<"El puntero doble apunta a la direccion: " << ptr1 <<endl;


}


int sumaPorCopia (int a, int b)
{
    int resultado = a + b;

    return resultado;
}

void sumaPorReferencia(int a, int b, int* resultado)
{
	*resultado = a + b;
}

void ejemplo2()
{
	cout << "\n-------------Ejemplo 2---------------------"<<endl;
	int a=1, b=2, suma;
	//suma = sumaPorCopia(a, b);
	sumaPorReferencia(a,b,&suma);

	cout << "Resultado de la suma: " << suma <<endl;
}

//--------------------------Ejemplo 3----------------------------
// Ejemplo de aplicacion a punteros como parametros de funciones
void allocPorReferencia(int** p)
{
	*p = new int;
	**p = 10;
}

void allocPorValor(int* p)
{
	p = new int;
	*p = 10;
}

void ejemplo3()
{
	cout << "\n-------------Ejemplo 3---------------------"<<endl;

	int *p = NULL;

	//Alloc por valor
	/*allocPorValor(p);
	cout << "*p: " << *p << endl;; //No va a imprimir nada: indefinido (perdi la referencia)
	delete(p); //No va a liberar memoria que se asigno en la funcion*/
	//(ver valgrind)

	//Alloc por referencia
	allocPorReferencia(&p);
	cout << "*p: " << *p << endl;
	delete (p);
	//(ver valgrind)

}

void ejemplo4()
{
	int filas = 3, columnas = 4;
	matrizDinamica(filas,columnas);
}

void matrizDinamica(int filas, int columnas)
{
	int **matriz = new int*[filas];

	int i, j, contador = 0;
	for (i = 0; i < filas; i++)
	{
		matriz[i] = new int[columnas];
		for(j = 0; j < columnas ; j++)
			matriz[i][j] = ++contador;
	}

	for (i = 0; i <  filas; i++)
	  for (j = 0; j < columnas; j++)
	  {
		 cout<< *(*(matriz+i)+j) <<" ";
		 if (j == columnas-1)
			 cout<<endl;
	  }

	//ver valgrind sin delete
	for (int i = 0; i < filas; ++i)
	    delete [] matriz[i];
	delete [] matriz;
}





