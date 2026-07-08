/* 1. Una empresa registra sus ventas diarias en una tienda durante 30 días
a. Permitir registrar las ventas
b. Calcular el promedio de ventas
c. Contar cuantos dias tuvieron ventas mayores
d. Mostrar los resultados obtenido
Autor : Trujillo Aguirre Maykel
Codigo : 0020250411
Fecha : 01/06/2026
*/
#include <iostream>
using namespace std;

int main() {
    // Constante para el número de días
    const int DIAS = 30; // const para evitar modificar el número de días accidentalmente
    // Arreglo para almacenar las ventas de cada día
    double ventas[DIAS];
    double suma = 0.0, promedio;
    int diasMayores = 0;

    // --- a. Permitir registrar las ventas ---
    cout << "=== REGISTRO DE VENTAS DIARIAS ===\n";
    for (int i = 0; i < DIAS; i++) {
        cout << "Ingrese la venta del dia " << (i + 1) << ": $"; cin >> ventas[i];
        // Acumulamos la suma para el promedio
        suma += ventas[i]; // suma = suma + ventas[i];
    }

    // --- b. Calcular el promedio de ventas ---
    promedio = suma / DIAS;

    // --- c. Contar cuántos días tuvieron ventas mayores al promedio ---
    for (int i = 0; i < DIAS; i++) {
        if (ventas[i] > promedio) {
            diasMayores++;
        }
    }

    // --- d. Mostrar los resultados obtenidos ---
    cout << "\n=== RESULTADOS ===\n";
    cout << "Promedio de ventas en " << DIAS << " días: $" << promedio << endl;
    cout << "Días con ventas superiores al promedio: " << diasMayores << endl;

    return 0;
}