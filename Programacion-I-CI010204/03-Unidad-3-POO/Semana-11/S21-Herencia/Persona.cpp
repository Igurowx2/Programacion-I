#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string codigo, dni, nombre, apellidos;
public:
    Persona() {
    }

    Persona(string _dni, string _nombre, string _apellidos) {
        this->dni = _dni;
        this->nombre = _nombre;
        this->apellidos = _apellidos;
    }

    string get_dni() {
        return this->dni;
    }

    void set_dni(string _dni) {
        this->dni = _dni;
    }

    string get_nombre() {
        return this->nombre;
    }

    void set_nombre(string _nombre) {
        this->nombre = _nombre;
    }

    string get_apellidos() {
        return this->apellidos;
    }

    void set_apellidos(string _apellidos) {
        this->apellidos = _apellidos;
    }

    void info() {
        cout << this->dni + " " + this->nombre + " " + this->apellidos << cout;
    }
};

class Estudiante : public Persona {
private:
    string colegio, direccion;
public:
    Estudiante() {
    }

    Estudiante(string _colegio, string _direccion, string _dni, string _nombre, string _apellidos)
        : Persona(_dni, _nombre, _apellidos) {
        this->colegio = _colegio;
        this->direccion = _direccion;
    }

    string get_colegio() {
        return this->colegio;
    }

    void set_colegio(string _colegio) {
        this->colegio = _colegio;
    }

    string get_direccion() {
        return this->direccion;
    }

    void set_direccion(string _direccion) {
        this->direccion = _direccion;
    }
};

int main() {
    Estudiante estudiante = Estudiante();
    Estudiante estudiante2 = Estudiante("GOmes", "ABC", "123", "Andy", "Marce");
    estudiante2.info();  
    return 0;
}