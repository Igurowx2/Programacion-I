/*1.Ingresado por teclado (usuario)
  2.Calcular el promedio
  3.La nota mayor 
  4.Ordenar de menor a mayor 
  5.Ordenar de mayor a menor*/
#include <iostream>
using namespace std;

float promedio(float arr[3]) {
    float suma = 0;
    for (int i = 0; i < 3; i++) {
        suma += arr[i];
    }
    return (suma / 3);
}

float mayor(float arr[3]) {
    float max = arr[0];
    for (int i = 1; i < 3; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    float nota[3] = {10,14,15};
/*
    float nota[3];
    cout << "Ingrese 3 notas:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Nota " << i+1 << ": "; cin >> nota[i];
    }
*/
    float prom = promedio(nota);
    float maxNota = mayor(nota);

    cout << "\nEl promedio es: " << prom << endl;
    cout << "La nota mayor es: " << maxNota << endl;

    return 0;
}