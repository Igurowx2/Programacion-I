#include <iostream>
#include <string>
using namespace std;

int main() {
    int numero;
    cout << "Ingrese un numero entero: ";cin >> numero;

    // se convierte a string para recorrer digito por digito
    string numStr = to_string(numero);

    cout << "Numeros pares: ";
    for (char c : numStr) {
        int digito = c - '0';  // convertir char a entero
        if (digito % 2 == 0) {
            cout << digito << " ";
        }
    }

    cout << "\nNumeros impares: ";
    for (char c : numStr) {
        int digito = c - '0';
        if (digito % 2 != 0) {
            cout << digito << " ";
        }
    }
    cout << endl;

    return 0;
}