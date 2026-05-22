#include <iostream>
using namespace std;

int main() {
    float lado1, lado2, lado3;

    cout << "Ingrese los tres lados del triangulo: "; cin >> lado1 >> lado2 >> lado3;

    if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
        cout << "Los lados deben ser numeros positivos." << endl;
    }
    if ((lado1 + lado2 > lado3) && (lado1 + lado3 > lado2) && (lado2 + lado3 > lado1)) {
        if (lado1 == lado2 && lado2 == lado3) {
            cout << "El triangulo es EQUILATERO." << endl;
        }
        else if (lado1 == lado2 || lado1 == lado3 || lado2 == lado3) {
            cout << "El triangulo es ISOSCELES." << endl;
        }
        else {
            cout << "El triangulo es ESCALENO." << endl;
        }
    }
    else {
        cout << "No es un triangulo valido (no cumple la desigualdad triangular)." << endl;
    }

    return 0;
}