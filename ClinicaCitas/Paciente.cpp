/*
 * Archivo: Paciente.cpp
 * Propósito: Hereda de Persona y agrega el atributo teléfono.
 *            Representa a un paciente del sistema.
 * Métodos:   Constructores, get/set de telefono, mostrar().
 */

#ifndef PACIENTE_CPP // Evitar inclusiones múltiples
#define PACIENTE_CPP // Incluye la definición de Persona

#include "Persona2.cpp" // Hereda de Persona

// Paciente: una persona con teléfono adicional
class Paciente : public Persona {
private:
    string telefono; // Número de contacto
public:
    // Constructor vacío: inicia sin teléfono
    Paciente() : Persona() {
        this->telefono = "";
    }
    // Constructor parametrizado: pasa datos comunes a Persona y guarda teléfono
    Paciente(string _dni, string _nombres, string _apellidos, string _telefono) : Persona(_dni, _nombres, _apellidos) {
        this->telefono = _telefono;
    }

    // Getter y setter del teléfono
    string get_telefono() { return this->telefono; }
    void set_telefono(string _telefono) { this->telefono = _telefono; }

    // Muestra los datos comunes y añade el teléfono
    void mostrar() {
        Persona::mostrar(); // Reutiliza el método de la clase base
        cout << " | Tel: " << this->telefono << endl;
    }
};

#endif