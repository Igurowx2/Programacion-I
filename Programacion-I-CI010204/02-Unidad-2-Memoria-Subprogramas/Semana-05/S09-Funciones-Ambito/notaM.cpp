#include <iostream>
using namespace std;

// funcion que calcula el promedio de 3 notas
float calcularPromedio(float notas[], int tamanio) {
    float suma = 0;
    for (int i = 0; i < tamanio; i++) {
        suma += notas[i];
    }
    return suma / tamanio;
}

// funcion que calcula la nota mayor de 3 notas
float calcularMayor(float notas[], int tamanio) {
    float mayor = notas[0];
    for (int i = 1; i < tamanio; i++) {
        if (notas[i] > mayor) {
            mayor = notas[i];
        }
    }
    return mayor;
}

int main() {
    float notas[3];   // arreglo para guardar 3 notas

    cout << "Ingrese las 3 notas: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Nota " << i + 1 << ": ";cin >> notas[i];
    }

    // se llama a la funcion para calcular el promedio
    float promedio = calcularPromedio(notas, 3);

    // se llama a la funcion para calcular la nota mayor
    float mayor = calcularMayor(notas, 3);

    cout << "\nEl promedio es: " << promedio << endl;
    cout << "La nota mayor es: " << mayor << endl;

    return 0;
}