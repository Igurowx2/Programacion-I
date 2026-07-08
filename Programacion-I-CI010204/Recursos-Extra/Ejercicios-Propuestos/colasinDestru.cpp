#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// devuelve una nueva pila con los elementos invertidos sin modificar la original
stack<int> invertirPilaSinDestruir(stack<int> original) {
    vector<int> elementos;
    while (!original.empty()) {
        elementos.push_back(original.top());
        original.pop();
    }
    stack<int> invertida;
    for (int i = elementos.size() - 1; i >= 0; i--) {
        invertida.push(elementos[i]);
    }
    return invertida;
}

int main() {
    stack<int> pila;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.push(40);
    pila.push(50);

    cout << "Pila original: ";
    stack<int> copia = pila;
    while (!copia.empty()) {
        cout << copia.top() << " ";
        copia.pop();
    }
    cout << endl;

    stack<int> invertida = invertirPilaSinDestruir(pila);

    cout << "Pila invertida (sin modificar la original): ";
    while (!invertida.empty()) {
        cout << invertida.top() << " ";
        invertida.pop();
    }
    cout << endl;

    return 0;
}