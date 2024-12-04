// dynamic array inversion.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
using namespace std;

class DynamicArray {
private:
    int size = 0;// La cantidad actual de elementos en el arreglo (inicialmente 0).
    int capacity;// El tamaño máximo del arreglo antes de que se tenga que redimensionar (inicialmente 10).
    string* array;// Es el contenedor donde se guardan los elementos del arreglo (es un puntero porque estás utilizando memoria dinámica para almacenar los elementos del arreglo, y los punteros son necesarios para trabajar con memoria dinámica)

public:
    DynamicArray() { // constructor por defecto
        capacity = 10; //Este constructor inicializa un arreglo con una capacidad fija de 10
        array = new string[capacity]; //reserva memoria dinámica con new string[capacity]
    }

    DynamicArray(int _c) { //Constructor con capacidad inicial personalizada
        capacity = _c; //signa el valor de _c a la variable capacity
        array = new string[capacity]; //memoria dinamica, Si el valor de capacity es 15, entonces new string[capacity] asignará espacio para 15 cadenas de texto.
    }

    DynamicArray(int _c, string* init, int init_size) { // el init  es para copiar los elementos de 'init' a 'array' (*preguntar, no entiendo porque pasa de init a array y no al reves si el init aparece de la nada)
        capacity = _c;
        size = init_size;
        array = new string[capacity];
        for (int i = 0; i < init_size; i++) {
            array[i] = init[i]; // Copiar cada elemento de 'init' a 'array'
        }
    }

    //Insert() Inserta un nuevo elemento en una posición dada. Si no hay espacio suficiente, el arreglo crece.
    bool insert(string newElement, int position) {
        if (capacity <= size) { //Si la capacidad es menor o igual al tamaño actual (size), duplicamos la capacidad del arreglo.
            capacity *= 2;
        }
        string* newArray = new string[capacity]; //Crear un nuevo arreglo con la capacidad duplicada
        size++; //  aumenta la cantidad de elementos en el arreglo después de insertar un nuevo elemento
        int i;
        for (i = 0; i < position; i++) { //  Copiar los elementos hasta la posición de inserción del nuevo elemento
            newArray[i] = array[i];
        }
        cout << i << endl; //imprime la posición en la que se insertará el nuevo elemento ( *preguntar porque lo hace, porque es necesario?)
        newArray[i] = newElement; //Colocar el nuevo elemento en la posición indicada
        i++; // avanza a la siguiente posición

        while (i < size) { // El propósito es mover todos los elementos después de la posición de inserción una posición hacia la derecha, para que el nuevo elemento pueda ocupar el lugar que antes estaba vacío.
            newArray[i] = array[i - 1];
            i++;
        }
        delete[] array; // Liberar la memoria del arreglo antiguo.
        array = newArray; // vuelve a pasar todo lo del newArray a la array, ya que ahora vuelve a estar vacía
        return true; //Indica que la inserción fue exitosa
    }

    bool remove(int position) {
        if (position >= size || position < 0) { //Si la posición está fuera de los límites (mayor o igual a size o menor que 0) 
            cout << "Posicio inexistent"; //muestra un mensaje de error ("Posición inexistente")
            return false; //devuelve false indicando que la eliminación no fue exitosa.
        }
        string* newArray = new string[capacity]; //Se crea un nuevo arreglo newArray que tendrá la misma capacidad que el arreglo original array
        size--; //Decrementa size porque al eliminar un elemento, el número de elementos en el arreglo disminuye en 1.
        for (int i = 0; i < position; i++) { //copia los elementos de array en newArray hasta la posición de eliminación. Los elementos previos a la posición se mantienen intactos.
            newArray[i] = array[i];
        }
        for (int i = position; i < capacity - 1; i++) { //se copian los elementos de array que están después de la posición eliminada en newArray
            newArray[i] = array[i + 1]; //Desplaza los elementos hacia la izquierda para llenar el espacio vacío dejado por el elemento eliminado.
        }
        delete[] array; //borra memoria array
        array = newArray; // copia los elementos de newArray bien colocados a la array otra vez
        return true; // eliminación exitosa, devuelve true
    }

    void print() { //Imprimir los elementos del arreglo array en la consola.
        for (int i = 0; i < size; i++) {
            cout << array[i] << ", ";
        }
        cout << endl;
    }
};

int main() {
    //string start[10]; --> esto está en el código del profe pero no sirve para nada, preguntarle o no sé pero es inútil literal
    DynamicArray a(10); //llama al segundo constructor, el DynamicArray(int _c), por tanto _c es 10, esto inicializa un arreglo dinámico con una capacidad de 10. Se crea un objeto a de la clase DynamicArray.
    a.insert("bli", 0); //e inserta el string "bli" en la posición 0 del arreglo.
    a.print(); //Luego se llama a a.print(), que imprimirá el estado actual del arreglo (debería mostrar "bli").
    a.insert("blo", 0);
    a.print();
    a.insert("blu", 0);
    a.print();
    a.remove(-10); //Intento de eliminación con una posición no válida (-10), (fuera del rango del arreglo), el método mostrará el mensaje "Posicio inexistent" y no realizará ninguna eliminación.
    a.print();
}