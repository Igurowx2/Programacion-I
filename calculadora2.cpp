#include <iostream>
using namespace std;

int main() {
    int opc;
    float numero1, numero2, resultado;
    char seguir = 's';

    while (seguir == 's' || seguir == 'S') {
        cout << "\n--- CALCULADORA ---" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicación" << endl;
        cout << "4. División" << endl;
        cout << "5. Salir" << endl;
        cout << "Opción : "; cin >> opc;

        if (opc >= 1 && opc <= 4) {
            cout << "Ingrese el primer número: "; cin >> numero1;
            cout << "Ingrese el segundo número: "; cin >> numero2;

            switch(opc) {
                case 1:
                    resultado = numero1 + numero2;
                    cout << "Resultado: " << numero1 << " + " << numero2 << " = " << resultado << endl;
                    break;
                case 2:
                    resultado = numero1 - numero2;
                    cout << "Resultado: " << numero1 << " - " << numero2 << " = " << resultado << endl;
                    break;
                case 3:
                    resultado = numero1 * numero2;
                    cout << "Resultado: " << numero1 << " * " << numero2 << " = " << resultado << endl;
                    break;
                case 4:
                    if (numero2 != 0) {
                        resultado = numero1 / numero2;
                        cout << "Resultado: " << numero1 << " / " << numero2 << " = " << resultado << endl;
                    } else {
                        cout << "No se puede dividir entre cero." << endl;
                    }
                    break;
            }

            // Preguntar si desea continuar
            do {
                cout << "¿Desea continuar? (S/N): "; cin >> seguir;
                if (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N') {
                    cout << "Respuesta no válida. Por favor ingrese S o N." << endl;
                }
            } while (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');

        } else if (opc == 5) {
            cout << "Saliendo de la calculadora ......" << endl; break;
        } else {
            cout << "Opción inválida." << endl;

            do {
                cout << "¿Desea continuar? (S/N): "; cin >> seguir;
                if (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N') {
                    cout << "Respuesta no válida. Por favor ingrese S o N." << endl;
                }
            } while (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');
        }
    }

    return 0;
}