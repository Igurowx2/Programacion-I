#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void invertirColaConPila(queue<int>& cola) {
    stack<int> pila;
    while (!cola.empty()) {
        pila.push(cola.front());
        cola.pop();
    }
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }
}

int main() {
    queue<int> cola;
    cola.push(1);
    cola.push(2);
    cola.push(3);
    cola.push(4);
    cola.push(5);

    cout << "Cola original: ";
    queue<int> copia = cola;
    while (!copia.empty()) {
        cout << copia.front() << " ";
        copia.pop();
    }
    cout << endl;

    invertirColaConPila(cola);

    cout << "Cola invertida: ";
    while (!cola.empty()) {
        cout << cola.front() << " ";
        cola.pop();
    }
    cout << endl;

    return 0;
}