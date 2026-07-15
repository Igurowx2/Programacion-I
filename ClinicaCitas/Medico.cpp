/*
 * Archivo: Medico.cpp
 * Propósito: Hereda de Persona y añade la especialidad médica.
 *            Representa a un médico del sistema.
 * Métodos:   Constructores, get/set de especialidad, mostrar().
 */


#ifndef MEDICO_CPP // Evitar inclusiones múltiples
#define MEDICO_CPP

#include "Persona2.cpp"

// Médico: una persona con una especialidad
class Medico : public Persona {
private:
    string especialidad; // Especialidad médica
public:
    // Constructor por defecto
    Medico() : Persona() {
        this->especialidad = "";
    }
    // Constructor con parámetros: inicializa persona y especialidad
    Medico(string _dni, string _nombres, string _apellidos, string _especialidad)
        : Persona(_dni, _nombres, _apellidos) {
        this->especialidad = _especialidad;
    }

    // Getter y setter
    string get_especialidad() { return this->especialidad; }
    void set_especialidad(string _especialidad) { this->especialidad = _especialidad; }

    // Muestra los datos de persona y la especialidad
    void mostrar() {
        Persona::mostrar();
        cout << " | Especialidad: " << this->especialidad << endl;
    }
};

#endif