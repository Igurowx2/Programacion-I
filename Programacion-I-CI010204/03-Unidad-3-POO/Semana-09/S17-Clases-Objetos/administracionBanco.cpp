#include <iostream>
#include <string>
using namespace std;

// estructura para almacenar los datos de un cliente
struct Cliente {
    string dni;
    string nombre;
};

// clase para manejar la cola de clientes (capacidad max 5)
class ColaClientes {
    private:
        Cliente clientes[5];   // arreglo para 5 clientes
        int frente;            // indice del primer cliente
        int final;             // indice del ultimo cliente + 1
        int contador;          // cantidad actual de clientes en la cola

    public:
        ColaClientes() {
            frente = 0;
            final = 0;
            contador = 0;
        }

        // verifica si la cola esta vacia
        bool estaVacia() {
            return contador == 0;
        }

        // verifica si la cola esta llena
        bool estaLlena() {
            return contador == 5;
        }

        // registra un cliente (lo inserta al final)
        void registrarCliente() {
            if (estaLlena()) {
                cout << "La cola esta llena, no se pueden registrar mas clientes" << endl;
                return;
            }

            Cliente nuevo;
            cout << "Ingrese el DNI del cliente: ";cin >> nuevo.dni;
            cout << "Ingrese el nombre del cliente: ";cin >> nuevo.nombre;

            clientes[final] = nuevo;     // se inserta en la posicion final
            final = (final + 1) % 5;     // avanza el indice final (circular)
            contador++;                  // incrementa el contador

            cout << "Cliente registrado exitosamente" << endl;
        }

        // atiende al cliente (elimina el primero)
        void atenderCliente() {
            if (estaVacia()) {
                cout << "No hay clientes en la cola para atender" << endl;
                return;
            }

            cout << "Atendiendo al cliente: " << clientes[frente].nombre << " (DNI: " << clientes[frente].dni << ")" << endl;
            frente = (frente + 1) % 5;   // avanza el indice frente (circular)
            contador--;                  // decrementa el contador
        }

        // muestra el estado actual de la cola
        void mostrarCola() {
            if (estaVacia()) {
                cout << "La cola esta vacia" << endl;
                return;
            }

            cout << "\n=== ESTADO DE LA COLA ===" << endl;
            cout << "Clientes esperando: " << contador << endl;
            int indice = frente;
            for (int i = 0; i < contador; i++) {
                cout << i + 1 << ". " << clientes[indice].nombre << " (DNI: " << clientes[indice].dni << ")" << endl;
                indice = (indice + 1) % 5;
            }
            cout << "========================" << endl;
        }

        // devuelve cuantos clientes quedan en la cola
        int clientesRestantes() {
            return contador;
        }
};

int main() {
    ColaClientes cola;
    int opcion;

    do {
        cout << "\n=== SISTEMA DE ATENCION BANCARIA ===" << endl;
        cout << "1. Registrar Cliente" << endl;
        cout << "2. Atender Cliente" << endl;
        cout << "3. Mostrar cola" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: "; cin >> opcion;

        switch (opcion) {
            case 1:
                cola.registrarCliente();
                break;

            case 2:
                cola.atenderCliente();
                break;

            case 3:
                cola.mostrarCola();
                cout << "Clientes restantes: " << cola.clientesRestantes() << endl;
                break;

            case 4:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion no valida, intente nuevamente" << endl;
        }

    } while (opcion != 4);

    return 0;
}