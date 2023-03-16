#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

typedef int Dato;
const Dato NULO = 0;

class Vector {
    // Atributos
private:
    int largo;
    Dato* datos;

    // Metodos
public:
    //Constructor con un parametro (largo inicial)
    //PRE: l > 0
    //POS: construye un Vector de largo l e inicializa en NULO
    Vector(int l);

    //Constructor de copia
    Vector(const Vector& v);


    //Destructor
    //PRE: -
    //POS: libera la memoria utilizada
    ~Vector();

    //consultar
    //PRE: 0 <= posicion < largo
    //POS: devuelve el valor que esta en la posicion posicion
    Dato consultar(int posicion);

    //cambiar
    //PRE: 0 <= posicion < largo
    //POS: cambia el valor que esta en la posicion posicion por v
    void cambiar(int posicion, Dato valor);

    //mostrar
    //PRE: -
    //POS: muestra en pantalla el vector
    void mostrar();

    //PRE: cantidad > 0
    //POS: extiende el vector en cantidad de lugares
    void agrandar(int cantidad);


    //PRE: v tiene que ser de la misma longitud que el objeto que llama
    //POS: devuelve un vector que es la suma del objeto + v
    Vector sumar (Vector v);

    //PRE: v tiene que ser de la misma longitud que el objeto que llama
    //POS: devuelve el producto escalar entre el objeto que llama y v
    int prod_escalar(Vector v);

    //Sobrecarga del operador +
    Vector operator+(Vector v);

    //Sobrecarga del operador *
    int operator*(Vector v);


private:
    //PRE:
    //POS: pone en nulos los valores desde, desde, hasta, hasta - 1
    void inicializar(int desde, int hasta);

    void copiar(Dato* pd, int desde, int hasta);
};


#endif // VECTOR_H_INCLUDED
