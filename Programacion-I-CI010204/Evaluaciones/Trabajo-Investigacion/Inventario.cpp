#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <string>
using namespace std;

// estructura para almacenar los datos de un producto
struct Producto {
    int codigo;
    string nombre;
    int cantidad;
    double precio;
};

// variables globales para el inventario
vector<Producto> inventario;                 // arreglo dinamico para almacenar todos los productos
map<int, int> indicePorCodigo;              // diccionario: codigo -> posicion en el vector
stack<string> historial;                    // pila para registrar las operaciones realizadas
queue<int> colaPedidos;                     // cola para manejar solicitudes de productos

// funcion para agregar un producto al inventario
void agregarProducto() {
    Producto nuevo;
    cout << "Ingrese el codigo del producto: ";cin >> nuevo.codigo;

    // verifica si el codigo ya existe en el diccionario
    if (indicePorCodigo.find(nuevo.codigo) != indicePorCodigo.end()) {
        cout << "El codigo ya existe en el inventario" << endl;
        return;
    }

    cout << "Ingrese el nombre del producto: ";cin >> nuevo.nombre;
    cout << "Ingrese la cantidad: ";cin >> nuevo.cantidad;
    cout << "Ingrese el precio: ";cin >> nuevo.precio;

    // se agrega al vector y se actualiza el mapa
    inventario.push_back(nuevo);
    int posicion = inventario.size() - 1;
    indicePorCodigo[nuevo.codigo] = posicion;

    // se registra la operacion en la pila de historial
    string operacion = "Agregado: " + nuevo.nombre + " (cod: " + to_string(nuevo.codigo) + ")";
    historial.push(operacion);

    cout << "Producto agregado exitosamente" << endl;
}

// funcion para eliminar un producto del inventario
void eliminarProducto() {
    int codigo;
    cout << "Ingrese el codigo del producto a eliminar: ";cin >> codigo;

    // busca el codigo en el diccionario
    auto it = indicePorCodigo.find(codigo);
    if (it == indicePorCodigo.end()) {
        cout << "Producto no encontrado" << endl;
        return;
    }

    int posicion = it->second;
    string nombreProducto = inventario[posicion].nombre;

    // se elimina del vector intercambiando con el ultimo y haciendo pop
    inventario[posicion] = inventario.back();
    inventario.pop_back();

    // se actualiza el indice para el producto que se movio
    if (posicion < inventario.size()) {
        int codigoMovido = inventario[posicion].codigo;
        indicePorCodigo[codigoMovido] = posicion;
    }

    // se elimina del diccionario
    indicePorCodigo.erase(it);

    // se registra en el historial
    string operacion = "Eliminado: " + nombreProducto + " (cod: " + to_string(codigo) + ")";
    historial.push(operacion);

    cout << "Producto eliminado" << endl;
}

// funcion para buscar un producto por codigo usando el diccionario
void buscarProducto() {
    int codigo;
    cout << "Ingrese el codigo del producto a buscar: ";cin >> codigo;

    auto it = indicePorCodigo.find(codigo);
    if (it == indicePorCodigo.end()) {
        cout << "Producto no encontrado" << endl;
        return;
    }

    int posicion = it->second;
    Producto& p = inventario[posicion];
    cout << "\nProducto encontrado:" << endl;
    cout << "Codigo: " << p.codigo << endl;
    cout << "Nombre: " << p.nombre << endl;
    cout << "Cantidad: " << p.cantidad << endl;
    cout << "Precio: " << p.precio << endl;
}

// funcion para listar todos los productos (recorre el arreglo)
void listarProductos() {
    if (inventario.empty()) {
        cout << "El inventario esta vacio" << endl;
        return;
    }

    cout << "\n=== LISTA DE PRODUCTOS ===" << endl;
    for (size_t i = 0; i < inventario.size(); i++) {
        cout << "Posicion: " << i << endl;
        cout << "Codigo: " << inventario[i].codigo << endl;
        cout << "Nombre: " << inventario[i].nombre << endl;
        cout << "Cantidad: " << inventario[i].cantidad << endl;
        cout << "Precio: " << inventario[i].precio << endl;
        cout << "------------------------" << endl;
    }
}

// funcion para mostrar el historial de operaciones (desapila)
void mostrarHistorial() {
    if (historial.empty()) {
        cout << "No hay operaciones registradas" << endl;
        return;
    }

    cout << "\n=== HISTORIAL DE OPERACIONES (pila) ===" << endl;
    // se crea una copia para no perder la pila original
    stack<string> copia = historial;
    while (!copia.empty()) {
        cout << copia.top() << endl;
        copia.pop();
    }
}

// funcion para agregar un pedido a la cola (solicitud de producto)
void agregarPedido() {
    int codigo;
    cout << "Ingrese el codigo del producto solicitado: ";cin >> codigo;

    // verifica que el producto exista
    if (indicePorCodigo.find(codigo) == indicePorCodigo.end()) {
        cout << "El producto no existe en el inventario" << endl;
        return;
    }

    colaPedidos.push(codigo);
    cout << "Pedido agregado a la cola" << endl;
}

// funcion para atender un pedido (desencola y actualiza el inventario)
void atenderPedido() {
    if (colaPedidos.empty()) {
        cout << "No hay pedidos pendientes" << endl;
        return;
    }

    int codigo = colaPedidos.front();
    colaPedidos.pop();

    // busca el producto en el diccionario
    auto it = indicePorCodigo.find(codigo);
    if (it == indicePorCodigo.end()) {
        cout << "El producto ya no existe en el inventario" << endl;
        return;
    }

    int posicion = it->second;
    Producto& p = inventario[posicion];

    if (p.cantidad <= 0) {
        cout << "El producto " << p.nombre << " no tiene stock" << endl;
        return;
    }

    p.cantidad--;
    cout << "Pedido atendido: " << p.nombre << " (cod: " << p.codigo << ")" << endl;
    cout << "Stock restante: " << p.cantidad << endl;

    // se registra en el historial
    string operacion = "Atendido pedido: " + p.nombre + " (cod: " + to_string(p.codigo) + ")";
    historial.push(operacion);
}

// funcion para mostrar la cola de pedidos
void mostrarColaPedidos() {
    if (colaPedidos.empty()) {
        cout << "La cola de pedidos esta vacia" << endl;
        return;
    }

    cout << "\n=== COLA DE PEDIDOS (queue) ===" << endl;
    queue<int> copia = colaPedidos;
    int num = 1;
    while (!copia.empty()) {
        int cod = copia.front();
        copia.pop();

        // busca el nombre del producto para mostrarlo
        auto it = indicePorCodigo.find(cod);
        if (it != indicePorCodigo.end()) {
            int pos = it->second;
            cout << num << ". " << inventario[pos].nombre << " (cod: " << cod << ")" << endl;
        } else {
            cout << num << ". Producto eliminado (cod: " << cod << ")" << endl;
        }
        num++;
    }
}

// menu principal
int main() {
    int opcion;

    do {
        cout << "\n=== SISTEMA DE INVENTARIO ===" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Eliminar producto" << endl;
        cout << "3. Buscar producto" << endl;
        cout << "4. Listar todos los productos" << endl;
        cout << "5. Mostrar historial de operaciones" << endl;
        cout << "6. Agregar pedido a la cola" << endl;
        cout << "7. Atender pedido" << endl;
        cout << "8. Mostrar cola de pedidos" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                eliminarProducto();
                break;
            case 3:
                buscarProducto();
                break;
            case 4:
                listarProductos();
                break;
            case 5:
                mostrarHistorial();
                break;
            case 6:
                agregarPedido();
                break;
            case 7:
                atenderPedido();
                break;
            case 8:
                mostrarColaPedidos();
                break;
            case 9:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opcion != 9);

    return 0;
}