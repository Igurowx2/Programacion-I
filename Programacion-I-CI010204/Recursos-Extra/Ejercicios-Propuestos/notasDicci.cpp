#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Estudiante {
    vector<float> notas;
    float promedio;
};

int main() {
    map<string, Estudiante> estudiantes;
    int num = 3;

    for (int i = 0; i < num; i++) {
        string nombre;
        cout << "Nombre del estudiante " << i+1 << ": "; cin >> nombre;

        Estudiante e;
        e.notas.resize(3);
        for (int j = 0; j < 3; j++) {
            cout << "Nota " << j+1 << ": "; cin >> e.notas[j];
        }

        float suma = 0;
        for (float n : e.notas) suma += n;
        e.promedio = suma / 3;

        estudiantes[nombre] = e;
    }

    cout << "\nResultados:" << endl;
    for (auto& par : estudiantes) {
        cout << "Estudiante: " << par.first << endl;
        cout << "  Notas: ";
        for (float n : par.second.notas) cout << n << " ";
        cout << endl;
        cout << "  Promedio: " << par.second.promedio << endl;
    }

    return 0;
}