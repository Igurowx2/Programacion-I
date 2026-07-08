/*2. Una universidad almacena notas de 5 estudiantes
a. Permite registrar las 4 notas
b. Calcule el promedio por cada estudiante
c. Identifique al estudiante con mayor promedio
d. Mostrar estudiantes aprobados y desaprobados
Autor : Trujillo Aguirre Maykel
Código : 0020250411
Fecha : 01/06/2026
*/
#include <iostream>
using namespace std;

int main() {
    const int ESTUDIANTES = 5;
    const int NOTAS_POR_EST = 4;
    const double NOTA_APROBATORIA = 10.5;  // Se aprueba con 10.5 o más
    double notas[ESTUDIANTES][NOTAS_POR_EST]; // Matriz de notas
    double promedios[ESTUDIANTES];            // Promedio de cada estudiante

    // --- a. Registrar las 4 notas de los 5 estudiantes ---
    cout << "=== INGRESO DE NOTAS (escala 0-20) ===\n";
    for (int i = 0; i < ESTUDIANTES; i++) {
        cout << "Estudiante " << (i + 1) << ":\n";
        for (int j = 0; j < NOTAS_POR_EST; j++) {
            cout << "  Nota " << (j + 1) << ": "; cin >> notas[i][j];
            // Validar rango
            while (notas[i][j] < 0 || notas[i][j] > 20) {
                cout << "  Nota invalida. Ingrese un valor entre 0 y 20: "; cin >> notas[i][j];
            }
        }
    }

    // --- b. Calcular el promedio por cada estudiante ---
    for (int i = 0; i < ESTUDIANTES; i++) {
        double suma = 0.0;
        for (int j = 0; j < NOTAS_POR_EST; j++) {
            suma += notas[i][j];
        }
        promedios[i] = suma / NOTAS_POR_EST;
    }

    // Mostrar los promedios calculados
    cout << "\n=== PROMEDIOS POR ESTUDIANTE ===\n";
    for (int i = 0; i < ESTUDIANTES; i++) {
        cout << "Estudiante " << (i + 1) << ": " << promedios[i] << endl;
    }

    // --- c. Identificar al estudiante con mayor promedio ---
    double mayorPromedio = promedios[0];
    int indiceMayor = 0;
    for (int i = 1; i < ESTUDIANTES; i++) {
        if (promedios[i] > mayorPromedio) {
            mayorPromedio = promedios[i];
            indiceMayor = i;
        }
    }
    cout << "\n=== ESTUDIANTE CON MAYOR PROMEDIO ===\n";
    cout << "Estudiante " << (indiceMayor + 1)
         << " con promedio " << mayorPromedio << endl;

    // --- d. Mostrar aprobados y desaprobados ---
    cout << "\n=== ESTADO FINAL (Nota aprobatoria: "
         << NOTA_APROBATORIA << ") ===\n";

    cout << "APROBADOS:\n";
    bool hayAprobados = false;
    for (int i = 0; i < ESTUDIANTES; i++) {
        if (promedios[i] >= NOTA_APROBATORIA) {
            cout << "  Estudiante " << (i + 1)
                 << " - Promedio: " << promedios[i] << endl;
            hayAprobados = true;
        }
    }
    if (!hayAprobados)
        cout << "  Ninguno.\n";

    cout << "\nDESAPROBADOS:\n";
    bool hayDesaprobados = false;
    for (int i = 0; i < ESTUDIANTES; i++) {
        if (promedios[i] < NOTA_APROBATORIA) {
            cout << "  Estudiante " << (i + 1)
                 << " - Promedio: " << promedios[i] << endl;
            hayDesaprobados = true;
        }
    }
    if (!hayDesaprobados)
        cout << "  Ninguno.\n";

    return 0;
}