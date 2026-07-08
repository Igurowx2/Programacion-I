#include <iostream>
using namespace std;

int main() {
    int opcion;
    double a, b;
    do {
        cout << "\n--- CALCULADORA ---" << endl;
        cout << "1. Suma\n2. Resta\n3. Multiplicacion\n4. Division\n5. Salir" << endl;
        cout << "Seleccione opcion: "; cin >> opcion;
        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese dos numeros: "; cin >> a >> b;
        }
        switch (opcion) {
            case 1: cout << "Resultado: " << a + b << endl; break;
            case 2: cout << "Resultado: " << a - b << endl; break;
            case 3: cout << "Resultado: " << a * b << endl; break;
            case 4:
                if (b == 0) cout << "Error: division por cero" << endl;
                else cout << "Resultado: " << a / b << endl;
                break;
            case 5: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion no valida" << endl;
        }
    } while (opcion != 5);
    return 0;
}