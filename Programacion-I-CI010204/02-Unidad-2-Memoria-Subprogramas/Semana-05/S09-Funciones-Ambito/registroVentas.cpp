#include <iostream>
using namespace std;

const int DIAS = 30;

// funcion para registrar las ventas de los 30 dias
void registrarVentas(float ventas[]) {
    for (int i = 0; i < DIAS; i++) {
        cout << "Ingrese la venta del dia " << i + 1 << ": ";cin >> ventas[i];
    }
}

// funcion que calcula el promedio de ventas
float calcularPromedio(float ventas[]) {
    float suma = 0;
    for (int i = 0; i < DIAS; i++) {
        suma += ventas[i];
    }
    return suma / DIAS;
}

// funcion que cuenta cuantos dias tuvieron ventas mayores al promedio
int contarMayores(float ventas[], float promedio) {
    int contador = 0;
    for (int i = 0; i < DIAS; i++) {
        if (ventas[i] > promedio) {
            contador++;
        }
    }
    return contador;
}

int main() {
    float ventas[DIAS];

    cout << "=== REGISTRO DE VENTAS DIARIAS ===" << endl;
    registrarVentas(ventas);

    float promedio = calcularPromedio(ventas);
    int diasMayores = contarMayores(ventas, promedio);

    cout << "\n=== RESULTADOS ===" << endl;
    cout << "Promedio de ventas: " << promedio << endl;
    cout << "Dias con ventas mayores al promedio: " << diasMayores << endl;

    return 0;
}