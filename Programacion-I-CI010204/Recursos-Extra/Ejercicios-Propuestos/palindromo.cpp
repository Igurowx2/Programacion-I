#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool esPalindromo(const string& palabra) {
    queue<char> cola;
    stack<char> pila;
    for (char c : palabra) {
        cola.push(c);
        pila.push(c);
    }
    while (!cola.empty()) {
        if (cola.front() != pila.top()) {
            return false;
        }
        cola.pop();
        pila.pop();
    }
    return true;
}

int main() {
    string palabra;
    cout << "Ingrese una palabra: "; cin >> palabra;

    if (esPalindromo(palabra)) {
        cout << "Es palindromo" << endl;
    } else {
        cout << "No es palindromo" << endl;
    }

    return 0;
}