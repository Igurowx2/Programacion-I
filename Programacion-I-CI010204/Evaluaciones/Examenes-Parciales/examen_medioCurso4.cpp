/*4. Una entidad bancaria necesita administrar la atención de clientes
a. Registrar 5 clientes mediante DNI y nombre
b. Insertar clientes al final de la cola
c. Atender clientes
d. Mostrar estado de la cola
e. Indicar cuántos clientes quedan
Autor : Trujillo Aguirre Maykel
Código : 0020250411
Fecha : 01/06/2026
*/

#include <iostream>
#include <string>
using namespace std;

// Estructura para representar un cliente
struct Cliente {
    string dni;
    string nombre;
};

// Tamaño máximo de la cola 
const int MAX_CLIENTES = 5;

// Variables globales para la cola circular
Cliente cola[MAX_CLIENTES];
int frente = -1;   // índice del primer cliente en la cola
int final_ = -1;   // índice del último cliente en la cola

// Función para verificar si la cola está vacía
bool colaVacia() {
    return (frente == -1);
}

// Función para verificar si la cola está llena
bool colaLlena() {
    return ((final_ + 1) % MAX_CLIENTES == frente); // La cola está llena si el siguiente índice de final_ es igual a frente
}

// Función para insertar un cliente al final de la cola (punto b)
void insertarCliente(Cliente c) {
    if (colaLlena()) {
        cout << "\nLa cola está llena. No se puede agregar más clientes.\n";
        return;
    }
    if (colaVacia()) {
        frente = 0;
        final_ = 0;
    } else {
        final_ = (final_ + 1) % MAX_CLIENTES; // Mover final_ al siguiente índice circular
    }
    cola[final_] = c; // Insertar el cliente en la posición final_
    cout << "Cliente " << c.nombre << " (DNI: " << c.dni << ") agregado a la cola.\n";
}

// Función para atender al cliente del frente de la cola (punto c)
void atenderCliente() {
    if (colaVacia()) {
        cout << "\nNo hay clientes esperando para ser atendidos.\n";
        return;
    }
    Cliente atendido = cola[frente];
    cout << "\nAtendiendo a: " << atendido.nombre << " (DNI: " << atendido.dni << ")\n";
    if (frente == final_) {
        // Solo quedaba un cliente
        frente = -1;
        final_ = -1;
    } else {
        frente = (frente + 1) % MAX_CLIENTES; // Mover frente al siguiente índice circular
    }
}

// Función para mostrar el estado actual de la cola (punto d)
void mostrarCola() {
    if (colaVacia()) {
        cout << "\nLa cola está vacía.\n";
        return;
    }
    cout << "\n--- ESTADO DE LA COLA ---\n";
    int i = frente;
    int pos = 1;
    while (true) {
        cout << pos << ". " << cola[i].nombre << " (DNI: " << cola[i].dni << ")\n";
        if (i == final_) break;
        i = (i + 1) % MAX_CLIENTES; // Mover al siguiente índice circular
        pos++;
    }
}

// Función para indicar cuántos clientes quedan en la cola (punto e)
int clientesEnCola() {
    if (colaVacia()) return 0;
    if (final_ >= frente)
        return final_ - frente + 1;
    else
        return MAX_CLIENTES - frente + final_ + 1; 
}

int main() {
    int opcion;
    Cliente nuevo;

    cout << "=== SISTEMA DE ATENCION BANCARIA (Cola de " << MAX_CLIENTES << " clientes maximo) ===\n";

    // Bucle principal del menú
    do {
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Registrar nuevo cliente (al final de la cola)\n";
        cout << "2. Atender al siguiente cliente\n";
        cout << "3. Mostrar estado de la cola\n";
        cout << "4. Indicar cuantos clientes quedan\n";
        cout << "0. Salir\n";
        cout << "Opcion: "; cin >> opcion;
        cin.ignore(); // Limpiar buffer para getline

        switch (opcion) {
            case 1:
                if (colaLlena()) {
                    cout << "\nLa cola ya tiene " << MAX_CLIENTES << " clientes. No se pueden agregar mas.\n";
                } else {
                    cout << "\n--- Registro de nuevo cliente ---\n";
                    cout << "Ingrese DNI: ";
                    getline(cin, nuevo.dni); // Usamos getline para permitir espacios
                    cout << "Ingrese nombre: ";
                    getline(cin, nuevo.nombre); //  Usamos getline para permitir espacios en el nombre
                    insertarCliente(nuevo);
                }
                break;

            case 2:
                atenderCliente();
                break;

            case 3:
                mostrarCola();
                break;

            case 4:
                cout << "\nClientes en espera: " << clientesEnCola() << endl;
                break;

            case 0:
                cout << "\nSaliendo del sistema...\n";
                break;

            default:
                cout << "\nOpcion no valida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 0);

    return 0;
}