/*Elabore un programa que permita invertir los valores de una pila usando colas
Autor: Trujillo Aguirre Maykel
Fecha: 21/05/2026*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    // Se crea una pila y se agregan algunos valores de ejemplo
    stack<int> pila;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.push(40);
    pila.push(50);

    // Se muestra el contenido original de la pila (desde la cima hacia la base)
    cout << "Pila original (cima -> base): ";
    stack<int> pilaCopia = pila; // Copia auxiliar para no perder los elementos
    while (!pilaCopia.empty()) {
        cout << pilaCopia.top() << " ";
        pilaCopia.pop();
    }
    cout << endl;

    // Se utiliza una cola para invertir el orden de los elementos
    queue<int> cola;

    // Paso 1: Trasladar todos los elementos de la pila a la cola
    // Al pasar de pila (LIFO) a cola (FIFO) se invierte el orden
    while (!pila.empty()) {
        cola.push(pila.top());
        pila.pop();
    }

    // Paso 2: Regresar los elementos de la cola a la pila
    // Ahora la cola entrega los elementos en el orden inverso al original
    while (!cola.empty()) {
        pila.push(cola.front());
        cola.pop();
    }

    // Se muestra la pila ya invertida
    cout << "Pila invertida (cima -> base): ";
    while (!pila.empty()) {
        cout << pila.top() << " ";
        pila.pop();
    }
    cout << endl;

    return 0;
}