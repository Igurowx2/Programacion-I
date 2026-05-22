#include <iostream>
using namespace std;

int main() {
    double a, b;
    int opcion;

    do {
        cout << "\n--- CALCULADORA ---\n";
        cout << "1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\n5. Salir\n";
        cout << "Opción: "; cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese dos números: "; cin >> a >> b;
        }

        switch (opcion) {
            case 1:
                cout << "Resultado: " << a + b << endl;
                break;
            case 2:
                cout << "Resultado: " << a - b << endl;
                break;
            case 3:
                cout << "Resultado: " << a * b << endl;
                break;
            case 4:
                if (b != 0)
                    cout << "Resultado: " << a / b << endl;
                else
                    cout << "Error: división entre cero." << endl;
                break;
            case 5:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 5);

    return 0;
}