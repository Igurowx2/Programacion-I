#include <iostream>
using namespace std;

// funcion recursiva que suma los digitos de un numero hasta obtener un solo digito
int reducirADigito(int n) {
    // caso base: si n es menor a 10, ya es un solo digito
    if (n < 10) {
        return n;
    }

    // se calcula la suma de los digitos
    int suma = 0;
    int temp = n;
    while (temp > 0) {
        suma += temp % 10;   // se obtiene el ultimo digito y se suma
        temp /= 10;          // se elimina el ultimo digito
    }

    // se llama recursivamente con la nueva suma
    return reducirADigito(suma);
}

int main() {
    int numero;
    cout << "Ingrese un numero entero positivo: ";
    cin >> numero;

    if (numero < 0) {
        cout << "El numero debe ser positivo" << endl;
        return 1;
    }

    int resultado = reducirADigito(numero);
    cout << "El numero especial (un digito) es: " << resultado << endl;

    return 0;
}