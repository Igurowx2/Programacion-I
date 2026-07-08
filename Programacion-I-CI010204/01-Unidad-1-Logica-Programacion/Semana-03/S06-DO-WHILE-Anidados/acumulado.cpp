#include <iostream>
using namespace std;

int main() {
    double acumulado = 0;   // variable que almacena el resultado acumulado
    int opcion;
    double a, b, resultado;

    do {
        // se muestra el menu de opciones
        cout << "\n=== CALCULADORA CON ACUMULADO ===" << endl;
        cout << "Acumulado actual: " << acumulado << endl;
        cout << "1. Suma (a + b)" << endl;
        cout << "2. Resta (a - b)" << endl;
        cout << "3. Multiplicacion (a * b)" << endl;
        cout << "4. Division (a / b)" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";cin >> opcion;

        if (opcion == 5) {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        if (opcion < 1 || opcion > 5) {
            cout << "Opcion no valida, intente nuevamente" << endl;
            continue;
        }

        // se solicitan los dos numeros
        cout << "Ingrese el primer numero: ";cin >> a;
        cout << "Ingrese el segundo numero: ";cin >> b;

        // se calcula el resultado de la operacion entre a y b
        switch (opcion) {
            case 1:
                resultado = a + b;
                acumulado = acumulado + resultado;   // se suma el resultado al acumulado
                cout << a << " + " << b << " = " << resultado << endl;
                break;
            case 2:
                resultado = a - b;
                acumulado = acumulado - resultado;   // se resta el resultado al acumulado
                cout << a << " - " << b << " = " << resultado << endl;
                break;
            case 3:
                resultado = a * b;
                acumulado = acumulado * resultado;   // se multiplica el acumulado por el resultado
                cout << a << " * " << b << " = " << resultado << endl;
                break;
            case 4:
                if (b == 0) {
                    cout << "Error: division por cero" << endl;
                    continue;   // no se actualiza el acumulado
                }
                resultado = a / b;
                acumulado = acumulado / resultado;   // se divide el acumulado por el resultado
                cout << a << " / " << b << " = " << resultado << endl;
                break;
        }

        // se muestra el nuevo acumulado
        cout << "Nuevo acumulado: " << acumulado << endl;

    } while (opcion != 5);

    return 0;
}