#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const string PATH_ENTRADA = "numeros.txt";
const string PATH_SALIDA = "salida.txt";

void leer_archivo();
void escribir_archivo();

int main(){
    leer_archivo();
    escribir_archivo();
    return 0;
}

void leer_archivo(){
    // NUMERO NUMERO NUMERO NUMERO ...
    /*
    123
    1
    NUMERO
    ...
    */

    ifstream archivo_entrada(PATH_ENTRADA);

    string numero;

    //Leer un archivo de números, separados cada uno con fines de linea o espacios
    while(archivo_entrada >> numero){
        cout << numero << endl;
    }

    //Leer un archivo con el formato NOMBRE;DNI;LEGAJO (separado con ;)

    /*string nombre;
    string dni;
    string legajo;
    while(getline(archivo_entrada, nombre, ';')){
        getline(archivo_entrada, dni, ';');
        getline(archivo_entrada, legajo);

        cout << "Nombre: " << nombre << ", Dni: " << dni << endl;
    }*/

    archivo_entrada.close();

}

void escribir_archivo(){

    ofstream archivo_salida(PATH_SALIDA);

    for(int i = 0; i < 15; i++){
        archivo_salida << i * 2 << endl;
    }

    archivo_salida.close();
}



