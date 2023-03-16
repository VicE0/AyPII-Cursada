/*
 * Se tiene un archivo de inscripciones con el numero de curso y codigo de materia
 * referido a cada inscripcion
 *
 * Para facilitar los calculos, se sabe que los codigos de materias posibles a las que puede
 * inscribirse un alumno son 7540, 7541 y 7542 y que no puede existir un curso n si no existe el n-1
 *
 * Alocar una matriz dinamica que contenga por cada materia y comisión la cantidad de inscriptos.


   El formato del archivo es del tipo:

   Curso
   CodigoMateria

   Curso
   CodigoMateria
   ...
 */

#include <iostream>
using namespace std;
#include <fstream>

const int cantidad_materias = 3;
const int codigo_mas_bajo = 7540;
int cantidad_cursos;
int cantidad_inscripciones;

typedef struct
{
	int curso;
	int materia;
}inscripcion_t;

int cargar_datos(string nombre_archivo, inscripcion_t* inscripciones);
int cantidad_de_cursos(inscripcion_t* inscripciones);
int inscriptos_por_curso_y_materia(int materia, int curso, inscripcion_t* inscripciones);
void cargar_matriz_dinamica(inscripcion_t* inscripciones, int** matriz);
void imprimir_matriz(int** matriz);
void liberar_recursos_matriz(int** matriz);

int main() {

	inscripcion_t* inscripciones = new inscripcion_t[30];

	cantidad_inscripciones = cargar_datos("inscripciones.txt", inscripciones);

	cantidad_cursos = cantidad_de_cursos(inscripciones);

	int **matriz = new int*[cantidad_materias];

	cargar_matriz_dinamica(inscripciones, matriz);

	imprimir_matriz(matriz);

	liberar_recursos_matriz(matriz);

	delete[] inscripciones;

	return 0;

}

int cargar_datos(string nombre_archivo, inscripcion_t* inscripciones)
{
	ifstream archivo;

	int cantidad_inscripciones;

	archivo.open(nombre_archivo);
	if(!archivo)
	{
		cout<<"No ha podido abrirse el archivo"<<endl;
		exit(1);
	}

	while(archivo>>inscripciones[cantidad_inscripciones].curso)
	{
		archivo>>inscripciones[cantidad_inscripciones].materia;
		cantidad_inscripciones++;
	}

	archivo.close();

	return cantidad_inscripciones;
}

int cantidad_de_cursos(inscripcion_t inscripciones[])
{
	int cantidad_cursos = 0;
	for(int i=0;i<cantidad_inscripciones;i++)
	{
		if(inscripciones[i].curso > cantidad_cursos)
			cantidad_cursos = inscripciones[i].curso;
	}
	return cantidad_cursos;

}
int inscriptos_por_curso_y_materia(int materia, int curso, inscripcion_t inscripciones[])
{
	int cantidad = 0;
	for(int i=0;i<cantidad_inscripciones;i++)
	{
		if(inscripciones[i].materia == materia && inscripciones[i].curso == curso)
			cantidad++;
	}
	return cantidad;
}

void cargar_matriz_dinamica(inscripcion_t inscripciones[], int** matriz)
{
	for (int i = 0; i < cantidad_materias; i++)
	{
		matriz[i] = new int[cantidad_cursos];
		for(int j = 0;j<cantidad_cursos;j++)
			matriz[i][j]=inscriptos_por_curso_y_materia(i+codigo_mas_bajo,j+1,inscripciones);
	}
}

void imprimir_matriz(int** matriz)
{
	for (int i = 0; i <  cantidad_materias; i++)
	  for (int j = 0; j < cantidad_cursos; j++)
	  {
		 cout<< matriz[i][j] <<" "; //*(*(matriz+i)+j)
		 if (j == cantidad_cursos-1)
			 cout<<endl;
	  }
}

void liberar_recursos_matriz(int** matriz)
{
	//ver valgrind sin delete
	for (int i = 0; i < cantidad_materias; ++i)
		delete[] matriz[i];
	delete[] matriz;
}


