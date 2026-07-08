#include <iostream>
#include <string>
using namespace std;

const int NUM_ESTUDIANTES = 5;
const int NUM_NOTAS = 4;
const float NOTA_APROBATORIA = 10.5;

// estructura para almacenar los datos de un estudiante
struct Estudiante {
    string nombre;
    float notas[NUM_NOTAS];
    float promedio;
};

// registra el nombre y las 4 notas de cada estudiante
void registrarEstudiantes(Estudiante estudiantes[]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Ingrese el nombre: ";
        cin >> estudiantes[i].nombre;
        for (int j = 0; j < NUM_NOTAS; j++) {
            cout << "Ingrese la nota " << j + 1 << ": ";
            cin >> estudiantes[i].notas[j];
        }
    }
}

// calcula el promedio de cada estudiante
void calcularPromedios(Estudiante estudiantes[]) {
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        float suma = 0;
        for (int j = 0; j < NUM_NOTAS; j++) {
            suma += estudiantes[i].notas[j];
        }
        estudiantes[i].promedio = suma / NUM_NOTAS;
    }
}

// busca el indice del estudiante con mayor promedio
int estudianteMayorPromedio(Estudiante estudiantes[]) {
    int indiceMayor = 0;
    for (int i = 1; i < NUM_ESTUDIANTES; i++) {
        if (estudiantes[i].promedio > estudiantes[indiceMayor].promedio) {
            indiceMayor = i;
        }
    }
    return indiceMayor;
}

// muestra los estudiantes aprobados y desaprobados segun la nota minima
void mostrarAprobadosDesaprobados(Estudiante estudiantes[]) {
    cout << "\n=== ESTUDIANTES APROBADOS ===" << endl;
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        if (estudiantes[i].promedio >= NOTA_APROBATORIA) {
            cout << estudiantes[i].nombre << " - Promedio: " << estudiantes[i].promedio << endl;
        }
    }

    cout << "\n=== ESTUDIANTES DESAPROBADOS ===" << endl;
    for (int i = 0; i < NUM_ESTUDIANTES; i++) {
        if (estudiantes[i].promedio < NOTA_APROBATORIA) {
            cout << estudiantes[i].nombre << " - Promedio: " << estudiantes[i].promedio << endl;
        }
    }
}

int main() {
    Estudiante estudiantes[NUM_ESTUDIANTES];

    cout << "=== REGISTRO DE NOTAS DE ESTUDIANTES ===" << endl;
    registrarEstudiantes(estudiantes);

    calcularPromedios(estudiantes);

    int indiceMayor = estudianteMayorPromedio(estudiantes);

    cout << "\n=== RESULTADOS ===" << endl;
    cout << "El estudiante con mayor promedio es: " << estudiantes[indiceMayor].nombre << " con " << estudiantes[indiceMayor].promedio << endl;

    mostrarAprobadosDesaprobados(estudiantes);

    return 0;
}