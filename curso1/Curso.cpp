#include <iostream>
#include <string>
using namespace std;

class Curso {
private:
    string codigo;
    string nombreCurso;
    string dniDocente;
    int cantidadAlumnos;

public:
    Curso() {
        codigo = "";
        nombreCurso = "";
        dniDocente = "";
        cantidadAlumnos = 0;
    }

    void setCodigo(string codigo) { this->codigo = codigo; }
    void setNombreCurso(string nombreCurso) { this->nombreCurso = nombreCurso; }
    void setDniDocente(string dniDocente) { this->dniDocente = dniDocente; }
    void setCantidadAlumnos(int cantidadAlumnos) { this->cantidadAlumnos = cantidadAlumnos; }

    string getCodigo() { return codigo; }
    string getNombreCurso() { return nombreCurso; }
    string getDniDocente() { return dniDocente; }
    int getCantidadAlumnos() { return cantidadAlumnos; }

    void mostrar() {
        cout << "Codigo: " << codigo << endl;
        cout << "Nombre del curso: " << nombreCurso << endl;
        cout << "DNI docente: " << dniDocente << endl;
        cout << "Cantidad de alumnos: " << cantidadAlumnos << endl;
    }
};