#include <iostream>
using namespace std;

int triangular(int n) {
    // Caso base: triangular(0) = 0
    if (n == 0) {
        return 0;
    }
    // Caso recursivo: t(n) = n + t(n-1)
    else {
        return n + triangular(n - 1);
    }
}

int main() {
    int n;

    cout << "Ingrese un numero entero no negativo: "; cin >> n;
    cout << "El numero triangular T(" << n << ") es: " << triangular(n) << endl;

    return 0;
}