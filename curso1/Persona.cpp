#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string dni;
    string nombre;
    string tipo;

public:
    Persona() {
        dni = "";
        nombre = "";
        tipo = "";
    }

    void setDni(string dni) { this->dni = dni; }
    void setNombre(string nombre) { this->nombre = nombre; }
    void setTipo(string tipo) { this->tipo = tipo; }

    string getDni() { return dni; }
    string getNombre() { return nombre; }
    string getTipo() { return tipo; }

    void mostrar() {
        cout << "DNI: " << dni << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Tipo: " << tipo << endl;
    }
};