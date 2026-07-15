/*
 * Archivo: Servicio.cpp
 * Propósito: Define la clase Servicio (no hereda de Persona).
 *            Almacena información de un servicio médico: nombre,
 *            descripción y costo, con su propio ID automático.
 * Métodos:   Constructores, getters/setters, mostrar().
 */

#ifndef SERVICIO_CPP // Evitar inclusiones múltiples
#define SERVICIO_CPP

#include <iostream>
#include <string>
using namespace std;

// Servicio médico: no es una persona, tiene nombre, descripción y costo
class Servicio {
private:
    int id;                // Identificador único
    string nombre;         // Nombre del servicio (ej: Traumatología)
    string descripcion;    // Breve explicación
    double costo;          // Precio en soles
    static int next_id;    // Contador estático para IDs de servicio
public:
    // Constructor por defecto
    Servicio() {
        this->id = 0;
        this->costo = 0;
    }
    // Constructor parametrizado: asigna siguiente ID y guarda datos
    Servicio(string _nombre, string _descripcion, double _costo) {
        this->id = next_id++;
        this->nombre = _nombre;
        this->descripcion = _descripcion;
        this->costo = _costo;
    }

    // Getters
    int get_id() { return this->id; }
    string get_nombre() { return this->nombre; }
    string get_descripcion() { return this->descripcion; }
    double get_costo() { return this->costo; }

    // Setters
    void set_id(int _id) { this->id = _id; }
    void set_nombre(string _nombre) { this->nombre = _nombre; }
    void set_descripcion(string _descripcion) { this->descripcion = _descripcion; }
    void set_costo(double _costo) { this->costo = _costo; }

    // Muestra todos los datos del servicio
    void mostrar() {
        cout << "ID: " << this->id << " | " << this->nombre << " - " << this->descripcion << " | Costo: S/. " << this->costo << endl;
    }
};

// Inicializa el contador de servicios en 1
int Servicio::next_id = 1;
#endif