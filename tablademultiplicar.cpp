#include <iostream>
using namespace std;

int main() {
    double number;

    cout << "Introduce un número para ver su tabla de multiplicar: ";cin >> number;
    cout << "\nTabla de multiplicar de " << number << " de 2 a 12:\n";
    for (int i = 2; i <= 12; ++i) {
        cout << number << " x " << i << " = " << number * i << endl;
    }

    return 0;
}