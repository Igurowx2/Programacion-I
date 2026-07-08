#include <iostream>
using namespace std;

const int TAMANIO = 10;

// funcion que calcula la suma total de los elementos del arreglo usando punteros
int calcularSuma(int* arreglo, int tamanio) {
    int suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma += *(arreglo + i);   // se accede al valor en la posicion i usando aritmetica de punteros
    }
    return suma;
}

// funcion que determina el numero mayor usando punteros
int obtenerMayor(int* arreglo, int tamanio) {
    int mayor = *arreglo;   // se asume que el primer elemento es el mayor
    for (int i = 1; i < tamanio; i++) {
        if (*(arreglo + i) > mayor) {
            mayor = *(arreglo + i);
        }
    }
    return mayor;
}

// funcion que determina el numero menor usando punteros
int obtenerMenor(int* arreglo, int tamanio) {
    int menor = *arreglo;   // se asume que el primer elemento es el menor
    for (int i = 1; i < tamanio; i++) {
        if (*(arreglo + i) < menor) {
            menor = *(arreglo + i);
        }
    }
    return menor;
}

// funcion que calcula el promedio usando el puntero al arreglo
float calcularPromedio(int* arreglo, int tamanio) {
    int suma = calcularSuma(arreglo, tamanio);
    return static_cast<float>(suma) / tamanio;
}

int main() {
    int numeros[TAMANIO];

    cout << "Ingrese 10 numeros enteros:" << endl;
    for (int i = 0; i < TAMANIO; i++) {
        cout << "Numero " << i + 1 << ": ";cin >> numeros[i];
    }

    // se envian las direcciones del arreglo (el nombre del arreglo es un puntero al primer elemento)
    int suma = calcularSuma(numeros, TAMANIO);
    int mayor = obtenerMayor(numeros, TAMANIO);
    int menor = obtenerMenor(numeros, TAMANIO);
    float promedio = calcularPromedio(numeros, TAMANIO);

    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Suma total: " << suma << endl;
    cout << "Numero mayor: " << mayor << endl;
    cout << "Numero menor: " << menor << endl;
    cout << "Promedio: " << promedio << endl;

    return 0;
}