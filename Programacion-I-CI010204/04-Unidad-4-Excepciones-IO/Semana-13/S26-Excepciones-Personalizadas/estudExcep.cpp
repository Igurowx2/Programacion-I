#include <iostream>
#include <exception>
using namespace std;

// excepcion para nota fuera de rango
class NotaFueraDeRango : public exception {
public:
    const char* what() const noexcept override {
        return "Error: la nota debe estar entre 0 y 20";
    }
};

// clase estudiante
class Estudiante {
private:
    string nombre;
    double promedio;
public:
    Estudiante(const string& nom, double prom) : nombre(nom) {
        if (prom < 0 || prom > 20) {
            throw NotaFueraDeRango();
        }
        promedio = prom;
    }

    void mostrar() const {
        cout << "Nombre: " << nombre << endl;
        cout << "Promedio: " << promedio << endl;
    }
};

int main() {
    string nombre;
    double nota;

    cout << "Ingrese el nombre del estudiante: "; cin >> nombre;
    cout << "Ingrese el promedio (0-20): "; cin >> nota;

    try {
        Estudiante est(nombre, nota);
        est.mostrar();
    } catch (const NotaFueraDeRango& e) {
        cout << e.what() << endl;
    }

    return 0;
}