#include <iostream>
using namespace std;

int main() {
    double saldo = 1000.0;
    int opcion;
    double cantidad;

    do {
        cout << "\n--- CAJERO ---\n";
        cout << "1. Consultar saldo\n2. Depositar\n3. Retirar\n4. Salir\n";
        cout << "Opción: "; cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Su saldo es: $" << saldo << endl;
                break;
            case 2:
                cout << "Cantidad a depositar: $"; cin >> cantidad;
                if (cantidad > 0) {
                    saldo += cantidad;
                    cout << "Depósito exitoso. Nuevo saldo: $" << saldo << endl;
                } else {
                    cout << "Cantidad inválida." << endl;
                }
                break;
            case 3:
                cout << "Cantidad a retirar: $"; cin >> cantidad;
                if (cantidad > 0 && cantidad <= saldo) {
                    saldo -= cantidad;
                    cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
                } else {
                    cout << "Fondos insuficientes o cantidad inválida." << endl;
                }
                break;
            case 4:
                cout << "Gracias por usar el cajero." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 4);

    return 0;
}