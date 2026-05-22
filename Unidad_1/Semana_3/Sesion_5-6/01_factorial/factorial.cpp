#include <iostream>
using namespace std;

int main() {
    int x;
    long long factorial = 1;
    cout << "Ingrese un número: "; cin >> x;

    if (x < 0) {
        cout << "Factorial no definido para negativos." << endl;
    } else {
        for (int i = 1; i <= x; i++) {
            factorial *= i;
        }
        cout << "Factorial de " << x << " = " << factorial << endl;
    }

    return 0;
}