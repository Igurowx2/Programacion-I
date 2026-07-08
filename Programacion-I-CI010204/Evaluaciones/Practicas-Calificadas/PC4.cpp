/*Elabore un programa que simule el manejo de un inventario de productos
<diccionarios ; pilas , colas , arreglos>
Autor: Trujillo Aguirre Maykel
Fecha: 21/05/2026*/
#include <iostream>
#include <map>        // Para el diccionario de productos
#include <stack>      // Para el historial de acciones
#include <queue>      // Para la cola de pedidos
#include <string>     // Para manejar nombres y descripciones
#include <vector>     // Para almacenar codigos (como arreglo)
using namespace std;

// Estructura que representa un producto en el inventario
struct Producto {
    string nombre;
    int cantidad;
};

// Variables globales para las estructuras de datos
map<int, Producto> inventario;    // Diccionario: codigo -> Producto (nombre, cantidad)
stack<string> historial;          // Pila para guardar las ultimas acciones realizadas
queue<int> pedidos;               // Cola para los codigos de productos pedidos
vector<int> codigosExistentes;    // Arreglo dinamico de codigos (simula un arreglo)

// Funcion para mostrar el menu y manejar la entrada
void mostrarMenu() {
    cout << "\n=== SISTEMA DE INVENTARIO ===" << endl;
    cout << "1. Agregar producto" << endl;
    cout << "2. Eliminar producto" << endl;
    cout << "3. Realizar pedido" << endl;
    cout << "4. Procesar siguiente pedido" << endl;
    cout << "5. Mostrar inventario" << endl;
    cout << "6. Mostrar historial de acciones" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    int opcion, codigo, cantidad;
    string nombreProducto;

    // Inicializamos algunos codigos de ejemplo en el arreglo
    codigosExistentes.push_back(101);
    codigosExistentes.push_back(102);
    codigosExistentes.push_back(103);

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: { // Agregar producto
                cout << "Ingrese el codigo del producto: ";
                cin >> codigo;
                // Verificar si el codigo ya existe en el diccionario
                if (inventario.find(codigo) != inventario.end()) {
                    cout << "El codigo ya existe. No se puede agregar." << endl;
                } else {
                    cout << "Ingrese el nombre del producto (una sola palabra): ";
                    cin >> nombreProducto;   // Lee una palabra, no necesita limpieza de buffer
                    cout << "Ingrese la cantidad: ";
                    cin >> cantidad;

                    // Agregar al diccionario
                    Producto nuevo;
                    nuevo.nombre = nombreProducto;
                    nuevo.cantidad = cantidad;
                    inventario[codigo] = nuevo;

                    // Agregar el codigo al arreglo dinamico
                    codigosExistentes.push_back(codigo);

                    // Guardar la accion en la pila
                    historial.push("Producto agregado: " + nombreProducto + " (Cod. " + to_string(codigo) + ", Cant. " + to_string(cantidad) + ")");
                    cout << "Producto agregado exitosamente." << endl;
                }
                break;
            }
            case 2: { // Eliminar producto
                cout << "Ingrese el codigo del producto a eliminar: ";
                cin >> codigo;
                map<int, Producto>::iterator it = inventario.find(codigo);  // Iterador explicito
                if (it != inventario.end()) {
                    // Guardar accion antes de borrar
                    string nom = it->second.nombre;
                    int cant = it->second.cantidad;
                    historial.push("Producto eliminado: " + nom + " (Cod. " + to_string(codigo) + ", Cant. " + to_string(cant) + ")");

                    // Eliminar del diccionario
                    inventario.erase(it);

                    // Actualizar el arreglo (eliminar el codigo del vector)
                    for (int i = 0; i < codigosExistentes.size(); i++) {
                        if (codigosExistentes[i] == codigo) {
                            codigosExistentes.erase(codigosExistentes.begin() + i);
                            break;
                        }
                    }
                    cout << "Producto eliminado." << endl;
                } else {
                    cout << "El codigo no existe en el inventario." << endl;
                }
                break;
            }
            case 3: { // Realizar pedido (encolar)
                if (inventario.empty()) {
                    cout << "No hay productos en el inventario para pedir." << endl;
                    break;
                }
                cout << "Ingrese el codigo del producto a pedir: ";
                cin >> codigo;
                map<int, Producto>::iterator it = inventario.find(codigo);  // Iterador explicito
                if (it != inventario.end()) {
                    if (it->second.cantidad > 0) {
                        // Reducir inventario en 1 unidad
                        it->second.cantidad--;
                        // Encolar el pedido
                        pedidos.push(codigo);
                        historial.push("Pedido realizado: " + it->second.nombre + " (Cod. " + to_string(codigo) + ")");
                        cout << "Pedido encolado exitosamente." << endl;
                    } else {
                        cout << "Producto sin existencias." << endl;
                    }
                } else {
                    cout << "El codigo no existe." << endl;
                }
                break;
            }
            case 4: { // Procesar siguiente pedido (desencolar)
                if (pedidos.empty()) {
                    cout << "No hay pedidos pendientes." << endl;
                } else {
                    int cod = pedidos.front();
                    pedidos.pop();
                    // Asumimos que el producto sigue existiendo porque solo se pide si hay stock
                    historial.push("Pedido procesado: " + inventario[cod].nombre + " (Cod. " + to_string(cod) + ")");
                    cout << "Pedido procesado del producto con codigo " << cod << " (" << inventario[cod].nombre << ")" << endl;
                }
                break;
            }
            case 5: { // Mostrar inventario (diccionario)
                cout << "\n--- INVENTARIO ---" << endl;
                if (inventario.empty()) {
                    cout << "El inventario esta vacio." << endl;
                } else {
                    // Recorremos el mapa con un iterador
                    map<int, Producto>::const_iterator it;
                    for (it = inventario.begin(); it != inventario.end(); ++it) {
                        cout << "Codigo: " << it->first
                             << " | Nombre: " << it->second.nombre
                             << " | Cantidad: " << it->second.cantidad << endl;
                    }
                }
                // Mostrar tambien el arreglo de codigos
                cout << "Codigos registrados en el arreglo: ";
                for (int i = 0; i < codigosExistentes.size(); i++) {
                    cout << codigosExistentes[i] << " ";
                }
                cout << endl;
                break;
            }
            case 6: { // Mostrar historial (pila)
                cout << "\n--- HISTORIAL (cima primero) ---" << endl;
                if (historial.empty()) {
                    cout << "No hay acciones registradas." << endl;
                } else {
                    // Copiamos la pila para no perder su contenido
                    stack<string> copia = historial;
                    while (!copia.empty()) {
                        cout << copia.top() << endl;
                        copia.pop();
                    }
                }
                break;
            }
            case 7: // Salir
                cout << "Saliendo del sistema de inventario..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);

    return 0;
}