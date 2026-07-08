#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// funcion que invierte los elementos de una pila utilizando una cola
void invertirPila(stack<int>& pila) {
    queue<int> cola;

    // paso 1: vaciar la pila y encolar todos los elementos
    while (!pila.empty()) {
        int elemento = pila.top();
        pila.pop();
        cola.push(elemento);
    }

    // paso 2: desencolar los elementos y apilarlos nuevamente
    // esto invierte el orden porque la cola mantiene el orden FIFO
    // y al apilarlos, el ultimo en salir de la cola sera el primero en la pila
    while (!cola.empty()) {
        int elemento = cola.front();
        cola.pop();
        pila.push(elemento);
    }
}

// funcion para mostrar el contenido de la pila (sin modificar)
void mostrarPila(stack<int> pila) {
    cout << "Contenido de la pila (tope a base): ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;
}

int main() {
    stack<int> pila;

    // se agregan algunos elementos a la pila
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);

    cout << "Pila original: ";
    mostrarPila(pila);

    // se invierte la pila
    invertirPila(pila);

    cout << "Pila invertida: ";
    mostrarPila(pila);

    return 0;
}