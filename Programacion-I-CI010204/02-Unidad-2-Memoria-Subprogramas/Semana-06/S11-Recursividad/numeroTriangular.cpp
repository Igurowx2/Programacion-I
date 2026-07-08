#include <iostream>
using namespace std;

// funcion recursiva que calcula el numero triangular t(n) = n + t(n-1)
int triangular(int n) {
    // caso base: cuando n es 1, el triangular es 1
    if (n == 1) {
        return 1;
    }
    // caso recursivo: n + triangular de n-1
    return n + triangular(n - 1);
}

int main() {
    int n;
    cout << "Ingrese un numero n (mayor a 0): ";cin >> n;

    if (n <= 0) {
        cout << "El numero debe ser positivo" << endl;
        return 1;
    }

    int resultado = triangular(n);
    cout << "El numero triangular de " << n << " es: " << resultado << endl;

    return 0;
}