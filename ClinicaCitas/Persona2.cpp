/*
 * Archivo: Persona2.cpp
 * Propósito: Define la clase base Persona, que contiene los datos
 *            comunes de pacientes y médicos (id, dni, nombres, apellidos).
 *            Incluye un contador estático (next_id) para asignar IDs únicos.
 * Métodos:   Constructores, getters/setters, mostrar() virtual.
 */
#ifndef PERSONA2_CPP // Evitar inclusiones múltiples
#define PERSONA2_CPP // Definir la macro de Persona

#include <iostream>
#include <string>
using namespace std;

// Clase base: almacena los datos comunes de una persona (paciente o médico)
class Persona {
protected: // Atributos visibles para las clases hijas
    int id;                 // Identificador único
    string dni;             // Documento de identidad
    string nombres;         // Nombres
    string apellidos;       // Apellidos
    static int next_id;     // no pertenece a cada objeto , clase entera

public:
    // Constructor por defecto: id = 0 (sin asignar)
    Persona() {
        this->id = 0;
    }
    // Constructor con parámetros: asigna el siguiente ID y guarda los datos
    Persona(string _dni, string _nombres, string _apellidos) {
        this->id = next_id++;   // Toma el ID actual y luego incrementa
        this->dni = _dni;
        this->nombres = _nombres;
        this->apellidos = _apellidos;
    }

    // Métodos para acceder a los atributos (getters) -> consultar
    int get_id() { return this->id; }
    string get_dni() { return this->dni; }
    string get_nombres() { return this->nombres; }
    string get_apellidos() { return this->apellidos; }

    // Métodos para modificar los atributos (setters) 
    void set_id(int _id) { this->id = _id; }
    void set_dni(string _dni) { this->dni = _dni; }
    void set_nombres(string _nombres) { this->nombres = _nombres; }
    void set_apellidos(string _apellidos) { this->apellidos = _apellidos; }

    // Método virtual: se puede sobrescribir en las clases derivadas
    virtual void mostrar() { // para que muestre datos extras
        cout << "ID: " << this->id << " | DNI: " << this->dni << " | " << this->nombres << " " << this->apellidos;
    }
};

// Inicialización del contador estático (primer ID = 1)
int Persona::next_id = 1;
#endif