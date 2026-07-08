#include <iostream>
#include <cstdlib>   // para rand y srand
#include <ctime>     // para time
using namespace std;

const int TAM = 10;

// funcion que llena el arreglo con numeros aleatorios entre 1 y 100
void llenarAleatorio(int arreglo[]) {
    srand(time(0));   // semilla para generar numeros diferentes cada ejecucion
    for (int i = 0; i < TAM; i++) {
        arreglo[i] = rand() % 100 + 1;   // numeros entre 1 y 100
    }
}

// funcion que ordena el arreglo de mayor a menor usando el metodo de burbuja
void ordenarMayorAMenor(int arreglo[]) {
    for (int i = 0; i < TAM - 1; i++) {
        for (int j = 0; j < TAM - i - 1; j++) {
            if (arreglo[j] < arreglo[j + 1]) {   // se intercambia si el de la izquierda es menor
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

// funcion que muestra el arreglo
void mostrarArreglo(int arreglo[]) {
    for (int i = 0; i < TAM; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
}

// funcion que devuelve el numero maximo (despues de ordenar es el primero)
int obtenerMaximo(int arreglo[]) {
    return arreglo[0];   // porque esta ordenado de mayor a menor
}

int main() {
    int numeros[TAM];

    llenarAleatorio(numeros);

    cout << "Arreglo generado aleatoriamente: ";
    mostrarArreglo(numeros);

    ordenarMayorAMenor(numeros);

    cout << "Arreglo ordenado de mayor a menor: ";
    mostrarArreglo(numeros);

    int maximo = obtenerMaximo(numeros);
    cout << "El numero maximo es: " << maximo << endl;

    return 0;
}