/*
 * Archivo: Clinica.cpp
 * Propósito: Clase principal del sistema. Administra los arreglos
 *            de pacientes, médicos, servicios y citas, con límites
 *            definidos (5 pacientes, 3 médicos, 5 servicios).
 *            Incluye el menú interactivo, operaciones de registro,
 *            eliminación, modificación de estado y exportación de
 *            reportes por servicio a archivo de texto.
 * Métodos:   menu(), registrarPaciente(), registrarMedico(), etc.
 */

#ifndef CLINICA_CPP // Evitar inclusiones múltiples
#define CLINICA_CPP

#include <iostream>
#include <string>
#include <fstream> // Para exportar reportes a archivo
#include "Paciente.cpp"
#include "Medico.cpp"
#include "Servicio.cpp"
#include "Cita.cpp"
using namespace std;

// Clase principal: gestiona todos los registros y el menú
class Clinica {
private:
    // Límites máximos (según requerimiento) , son valores constantes no cambian
    static const int MAX_PACIENTES = 5;
    static const int MAX_MEDICOS  = 3;
    static const int MAX_SERVICIOS = 5;
    static const int MAX_CITAS    = 20;

    // Arreglos de objetos
    Paciente pacientes[MAX_PACIENTES];
    Medico medicos[MAX_MEDICOS];
    Servicio servicios[MAX_SERVICIOS];
    Cita citas[MAX_CITAS];

    // Contadores actuales
    int num_pacientes;
    int num_medicos;
    int num_servicios;
    int num_citas;

    // Función auxiliar: valida que una cadena no esté vacía ni solo espacios , se usa para validar entradas
    bool cadena_no_vacia(const string& s) {
        return !s.empty() && s.find_first_not_of(" \t\n") != string::npos;
    }

public:
    // Constructor: inicializa los contadores en 0
    Clinica() {
        this->num_pacientes = 0;
        this->num_medicos = 0;
        this->num_servicios = 0;
        this->num_citas = 0;
    }

    // Menú interactivo: se repite hasta que el usuario elija Salir
    void menu() {
        int opc;
        do {
            cout << "\n===== SISTEMA DE CITAS CLINICA =====" << endl;
            cout << "1. Registrar paciente (max " << MAX_PACIENTES << ")" << endl;
            cout << "2. Registrar medico  (max " << MAX_MEDICOS << ")" << endl;
            cout << "3. Registrar servicio (max " << MAX_SERVICIOS << ")" << endl;
            cout << "4. Crear cita" << endl;
            cout << "5. Listar citas" << endl;
            cout << "6. Eliminar cita" << endl;
            cout << "7. Modificar estado de cita" << endl;
            cout << "8. Exportar reporte por servicio (txt)" << endl;
            cout << "9. Salir" << endl;
            cout << "Seleccione una opcion: "; cin >> opc;
            cin.ignore(); // Limpiar salto de línea

            switch(opc) {
                case 1: this->registrar_paciente(); break;
                case 2: this->registrar_medico(); break;
                case 3: this->registrar_servicio(); break;
                case 4: this->crear_cita(); break;
                case 5: this->listar_citas(); break;
                case 6: this->eliminar_cita(); break;
                case 7: this->modificar_estado_cita(); break;
                case 8: this->exportar_reporte_servicio(); break;
                case 9: cout << "Saliendo..." << endl; break;
                default: cout << "Opcion no valida." << endl;
            }
        } while (opc != 9);
    }

    // ---------- REGISTRO DE PACIENTE ----------
    void registrar_paciente() {
        if (this->num_pacientes >= MAX_PACIENTES) { // Verificar límite
            cout << "Limite de pacientes alcanzado." << endl;
            return;
        }
        string dni, nom, ape, tel;
        cout << "DNI: "; getline(cin, dni);
        if (!this->cadena_no_vacia(dni)) { cout << "DNI invalido." << endl; return; } // Validar
        cout << "Nombres: "; getline(cin, nom);
        if (!this->cadena_no_vacia(nom)) { cout << "Nombre invalido." << endl; return; }
        cout << "Apellidos: "; getline(cin, ape);
        if (!this->cadena_no_vacia(ape)) { cout << "Apellidos invalidos." << endl; return; }
        cout << "Telefono: "; getline(cin, tel);

        // Guardar en el arreglo y aumentar contador
        this->pacientes[this->num_pacientes] = Paciente(dni, nom, ape, tel);
        this->num_pacientes++;
        cout << "Paciente registrado." << endl;
    }

    // ---------- REGISTRO DE MÉDICO ----------
    void registrar_medico() {
        if (this->num_medicos >= MAX_MEDICOS) {
            cout << "Limite de medicos alcanzado." << endl;
            return;
        }
        string dni, nom, ape, esp;
        cout << "DNI del medico: "; getline(cin, dni);
        if (!this->cadena_no_vacia(dni)) { cout << "DNI invalido." << endl; return; }
        cout << "Nombres: "; getline(cin, nom);
        if (!this->cadena_no_vacia(nom)) { cout << "Nombre invalido." << endl; return; }
        cout << "Apellidos: "; getline(cin, ape);
        if (!this->cadena_no_vacia(ape)) { cout << "Apellidos invalidos." << endl; return; }
        cout << "Especialidad: "; getline(cin, esp);
        if (!this->cadena_no_vacia(esp)) { cout << "Especialidad invalida." << endl; return; }

        this->medicos[this->num_medicos] = Medico(dni, nom, ape, esp);
        this->num_medicos++;
        cout << "Medico registrado." << endl;
    }

    // ---------- REGISTRO DE SERVICIO ----------
    void registrar_servicio() {
        if (this->num_servicios >= MAX_SERVICIOS) {
            cout << "Limite de servicios alcanzado." << endl;
            return;
        }
        string nom, desc;
        double costo;
        cout << "Nombre del servicio: "; getline(cin, nom);
        if (!this->cadena_no_vacia(nom)) { cout << "Nombre invalido." << endl; return; }
        cout << "Descripcion: "; getline(cin, desc);
        if (!this->cadena_no_vacia(desc)) { cout << "Descripcion invalida." << endl; return; }
        cout << "Costo (S/.): "; cin >> costo; cin.ignore();
        if (costo < 0) { cout << "Costo invalido." << endl; return; }

        this->servicios[this->num_servicios] = Servicio(nom, desc, costo);
        this->num_servicios++;
        cout << "Servicio registrado." << endl;
    }

    // ---------- CREAR CITA ----------
    void crear_cita() {
        if (this->num_pacientes == 0 || this->num_medicos == 0 || this->num_servicios == 0) {
            cout << "Debe haber al menos un paciente, un medico y un servicio." << endl;
            return;
        }

        // Seleccionar paciente
        cout << "\n--- Pacientes ---" << endl;
        for (int i = 0; i < this->num_pacientes; i++) {
            cout << i+1 << ". "; this->pacientes[i].mostrar();
        }
        int idxP;
        cout << "Numero: "; cin >> idxP; cin.ignore();
        if (idxP < 1 || idxP > this->num_pacientes) { cout << "Invalido." << endl; return; }

        // Seleccionar médico
        cout << "\n--- Medicos ---" << endl;
        for (int i = 0; i < this->num_medicos; i++) {
            cout << i+1 << ". "; this->medicos[i].mostrar();
        }
        int idxM;
        cout << "Numero: "; cin >> idxM; cin.ignore();
        if (idxM < 1 || idxM > this->num_medicos) { cout << "Invalido." << endl; return; }

        // Seleccionar servicio
        cout << "\n--- Servicios ---" << endl;
        for (int i = 0; i < this->num_servicios; i++) {
            cout << i+1 << ". "; this->servicios[i].mostrar();
        }
        int idxS;
        cout << "Numero: "; cin >> idxS; cin.ignore();
        if (idxS < 1 || idxS > this->num_servicios) { cout << "Invalido." << endl; return; }

        // Solicitar fecha y hora
        string fecha, hora;
        cout << "Fecha (dd/mm/aaaa): "; getline(cin, fecha);
        if (!this->cadena_no_vacia(fecha)) { cout << "Fecha invalida." << endl; return; }
        cout << "Hora (hh:mm): "; getline(cin, hora);
        if (!this->cadena_no_vacia(hora)) { cout << "Hora invalida." << endl; return; }

        // Comprobar límite de citas
        if (this->num_citas >= MAX_CITAS) {
            cout << "Limite de citas alcanzado." << endl;
            return;
        }

        // Crear la cita y almacenarla
        this->citas[this->num_citas] = Cita(
            this->pacientes[idxP-1],
            this->medicos[idxM-1],
            this->servicios[idxS-1],
            fecha, hora
        );
        this->num_citas++;
        cout << "Cita creada con exito." << endl;
    }

    // ---------- LISTAR CITAS ----------
    void listar_citas() {
        if (this->num_citas == 0) {
            cout << "No hay citas registradas." << endl;
            return;
        }
        for (int i = 0; i < this->num_citas; i++) {
            this->citas[i].mostrar();
        }
    }

    // ---------- ELIMINAR CITA ----------
    void eliminar_cita() {
        if (this->num_citas == 0) {
            cout << "No hay citas." << endl;
            return;
        }
        this->listar_citas(); // Mostrar para que el usuario vea los IDs
        int idCita;
        cout << "ID de la cita a eliminar: "; cin >> idCita; cin.ignore();
        for (int i = 0; i < this->num_citas; i++) {
            if (this->citas[i].get_id() == idCita) { // Buscar por ID
                // Desplazar los elementos posteriores hacia la izquierda
                for (int j = i; j < this->num_citas - 1; j++) {
                    this->citas[j] = this->citas[j+1];
                }
                this->num_citas--; // Reducir contador
                cout << "Cita eliminada." << endl;
                return;
            }
        }
        cout << "Cita no encontrada." << endl;
    }

    // ---------- MODIFICAR ESTADO DE CITA ----------
    void modificar_estado_cita() {
        if (this->num_citas == 0) {
            cout << "No hay citas." << endl;
            return;
        }
        this->listar_citas();
        int idCita;
        cout << "ID de la cita a modificar: "; cin >> idCita; cin.ignore();
        for (int i = 0; i < this->num_citas; i++) {
            if (this->citas[i].get_id() == idCita) {
                cout << "Estado actual: " << this->citas[i].get_estado() << endl;
                cout << "Nuevo estado (Pendiente/Atendida/Cancelada): ";
                string nuevo;
                getline(cin, nuevo);
                // Solo se permiten esos tres estados
                if (nuevo == "Pendiente" || nuevo == "Atendida" || nuevo == "Cancelada") {
                    this->citas[i].set_estado(nuevo);
                    cout << "Estado actualizado." << endl;
                } else {
                    cout << "Estado no valido." << endl;
                }
                return;
            }
        }
        cout << "Cita no encontrada." << endl;
    }

    // ---------- EXPORTAR REPORTE POR SERVICIO ----------
    void exportar_reporte_servicio() {
        if (this->num_servicios == 0) {
            cout << "No hay servicios registrados." << endl;
            return;
        }
        // Mostrar servicios disponibles
        cout << "\n--- Servicios ---" << endl;
        for (int i = 0; i < this->num_servicios; i++) {
            cout << i+1 << ". "; this->servicios[i].mostrar();
        }
        int idxS;
        cout << "Seleccione servicio: "; cin >> idxS; cin.ignore();
        if (idxS < 1 || idxS > this->num_servicios) {
            cout << "Invalido." << endl;
            return;
        }

        Servicio s = this->servicios[idxS-1]; // Servicio elegido
        string nombre_archivo = "reporte_" + s.get_nombre() + ".txt";
        ofstream archivo(nombre_archivo.c_str()); // Abrir archivo de texto
        if (!archivo.is_open()) {
            cout << "Error al crear archivo." << endl;
            return;
        }

        // Escribir cabecera del reporte
        archivo << "REPORTE DE CITAS - Servicio: " << s.get_nombre() << endl;
        archivo << "Descripcion: " << s.get_descripcion() << endl;
        archivo << "Costo: S/. " << s.get_costo() << endl;
        archivo << "========================================\n\n";

        bool encontro = false; // Bandera para verificar si hay citas
        for (int i = 0; i < this->num_citas; i++) {
            if (this->citas[i].get_servicio().get_id() == s.get_id()) { // Coincide el servicio
                encontro = true;
                Paciente p = this->citas[i].get_paciente();
                Medico m = this->citas[i].get_medico();

                archivo << "Cita ID: " << this->citas[i].get_id() << endl;
                archivo << "Fecha: " << this->citas[i].get_fecha() << "  Hora: " << this->citas[i].get_hora() << endl;
                archivo << "Estado: " << this->citas[i].get_estado() << endl;
                archivo << "Medico: Dr/a " << m.get_nombres() << " " << m.get_apellidos() << " (" << m.get_especialidad() << ")" << endl;
                archivo << "Paciente: " << p.get_nombres() << " " << p.get_apellidos() << " | DNI: " << p.get_dni() << " | Tel: " << p.get_telefono() << endl;
                archivo << "----------------------------------------\n";
            }
        }
        if (!encontro) archivo << "No hay citas registradas para este servicio." << endl;

        archivo.close(); // Cerrar archivo
        cout << "Reporte exportado como '" << nombre_archivo << "'." << endl;
    }
};

#endif