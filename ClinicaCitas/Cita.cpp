/*
 * Archivo: Cita.cpp
 * Propósito: Relaciona un paciente, un médico y un servicio con una fecha,
 *            hora y estado (por defecto "Pendiente"). Asigna ID único.
 * Métodos:   Constructores, getters, set de estado, mostrar().
 */

#ifndef CITA_CPP // Evitar inclusiones múltiples
#define CITA_CPP

#include <iostream>
#include <string>
#include "Paciente.cpp"
#include "Medico.cpp"
#include "Servicio.cpp"
using namespace std;

// Cita: reúne paciente, médico, servicio, fecha, hora y estado
class Cita {
private:
    int id;                  // ID único de la cita
    Paciente paciente;       // Objeto paciente (copia)
    Medico medico;           // Objeto médico
    Servicio servicio;       // Objeto servicio
    string fecha;            // Fecha en formato dd/mm/aaaa
    string hora;             // Hora en formato hh:mm
    string estado;           // Pendiente, Atendida o Cancelada
    static int next_id;      // Contador para IDs de citas
public:
    // Constructor por defecto
    Cita() { this->id = 0; }
    // Constructor parametrizado: asigna ID y copia los objetos
    Cita(Paciente _paciente, Medico _medico, Servicio _servicio, string _fecha, string _hora) {
        this->id = next_id++;
        this->paciente = _paciente;
        this->medico = _medico;
        this->servicio = _servicio;
        this->fecha = _fecha;
        this->hora = _hora;
        this->estado = "Pendiente"; // Toda cita nueva empieza como Pendiente
    }

    // Getters
    int get_id() { return this->id; }
    Paciente get_paciente() { return this->paciente; }
    Medico get_medico() { return this->medico; }
    Servicio get_servicio() { return this->servicio; }
    string get_fecha() { return this->fecha; }
    string get_hora() { return this->hora; }
    string get_estado() { return this->estado; }

    // Setters (solo estado e ID se modifican externamente)
    void set_id(int _id) { this->id = _id; }
    void set_estado(string _estado) { this->estado = _estado; }

    // Muestra la cita completa y los objetos que la componen
    void mostrar() {
        cout << "Cita ID: " << this->id << " | Fecha: " << this->fecha << " "
             << this->hora << " | Estado: " << this->estado << endl;
        cout << "   Paciente: "; this->paciente.mostrar();
        cout << "   Medico: "; this->medico.mostrar();
        cout << "   Servicio: "; this->servicio.mostrar();
    }
};

// Inicializa el contador de citas en 1
int Cita::next_id = 1;
#endif