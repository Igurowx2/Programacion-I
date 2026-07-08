#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

void intercambiarPilaCola(stack<int>& pila, queue<int>& cola) {
    vector<int> elementosPila;
    vector<int> elementosCola;

    while (!pila.empty()) {
        elementosPila.push_back(pila.top());
        pila.pop();
    }
    while (!cola.empty()) {
        elementosCola.push_back(cola.front());
        cola.pop();
    }

    for (int i = elementosCola.size() - 1; i >= 0; i--) {
        pila.push(elementosCola[i]);
    }
    for (int i = 0; i < elementosPila.size(); i++) {
        cola.push(elementosPila[i]);
    }
}

int main() {
    stack<int> pila;
    queue<int> cola;

    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);

    cola.push(10);
    cola.push(20);
    cola.push(30);
    cola.push(40);
    cola.push(50);

    cout << "Pila original: ";
    stack<int> copiaPila = pila;
    while (!copiaPila.empty()) {
        cout << copiaPila.top() << " ";
        copiaPila.pop();
    }
    cout << endl;

    cout << "Cola original: ";
    queue<int> copiaCola = cola;
    while (!copiaCola.empty()) {
        cout << copiaCola.front() << " ";
        copiaCola.pop();
    }
    cout << endl;

    intercambiarPilaCola(pila, cola);

    cout << "Pila despues del intercambio (con elementos de la cola): ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;

    cout << "Cola despues del intercambio (con elementos de la pila): ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;

    return 0;
}