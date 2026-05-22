#include <iostream>
using namespace std;

int main() {
    const int SECRETO = 8;  // número a adivinar
    int intento, contador = 0;
    bool acertado = false;

    while (contador < 4 && !acertado) {
        cout << "Intento " << contador + 1 << "/4 - Ingrese un numero: ";
        cin >> intento;
        if (intento == SECRETO) {
            cout << "¡Felicidades! Adivinaste el numero." << endl;
            acertado = true;
        }
        contador++;
    }

    if (!acertado)
        cout << "No adivinaste el numero. Era: " << SECRETO << endl;

    return 0;
}