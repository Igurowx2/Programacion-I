#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese un numero n > 0: ";cin >> n;

    if (n <= 0) {
        cout << "El numero debe ser mayor que 0" << endl;
        return 1;
    }

    cout << "Los divisores de " << n << " son: ";
    // se recorre desde 1 hasta n
    for (int i = 1; i <= n; i++) {
        // si i divide exactamente a n, es divisor
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}