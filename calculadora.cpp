#include <iostream>
using namespace std;

int main() {
    int opcion;
    double a, b;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicar" << endl;
        cout << "4. Dividir" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese dos numeros: ";
            cin >> a >> b;
        }

        switch (opcion) {
            case 1: cout << "Resultado: " << a + b << endl; break;
            case 2: cout << "Resultado: " << a - b << endl; break;
            case 3: cout << "Resultado: " << a * b << endl; break;
            case 4:
                if (b != 0)
                    cout << "Resultado: " << a / b << endl;
                else
                    cout << "Error: division entre cero" << endl;
                break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida" << endl;
        }
    } while (opcion != 5);

    return 0;
}