/*Dado un arreglo de 10 numeros enteros debe desarrollar una funcion que complete el arreglo de numeros aleatorios, funcion para aleatorios
luego debe ordenar de menor a mayor, indicar el numero maximo
Autor: Trujillo Aguirre Maykel
Fecha: 21/05/2026*/
#include <iostream>
#include <cstdlib>  // Para rand() y srand()
#include <ctime>    // Para time()
using namespace std;

// Función para llenar el arreglo con números aleatorios entre 0 y 99
void llenarArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Números aleatorios de 0 a 99
    }
}

// Función para ordenar el arreglo de menor a mayor (método burbuja)
void ordenarArreglo(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Intercambiar los elementos si están en el orden incorrecto
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Función para encontrar el número máximo en el arreglo
int maximo(int arr[], int n) {
    int max = arr[0];  // Suponemos que el primero es el mayor
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];  // Se actualiza si encontramos uno mayor
        }
    }
    return max;
}

int main() {
    const int TAM = 10;      // Tamaño del arreglo
    int arreglo[TAM];        // Declaración del arreglo de 10 enteros

    srand(time(NULL));       // Semilla para números aleatorios

    // Llenar el arreglo con valores aleatorios
    llenarArreglo(arreglo, TAM);

    // Mostrar arreglo original
    cout << "Arreglo original: ";
    for (int i = 0; i < TAM; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // Ordenar el arreglo de menor a mayor
    ordenarArreglo(arreglo, TAM);

    // Mostrar arreglo ordenado
    cout << "Arreglo ordenado: ";
    for (int i = 0; i < TAM; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    // Obtener y mostrar el número máximo
    int numMax = maximo(arreglo, TAM);
    cout << "Numero maximo: " << numMax << endl;

    return 0;
}