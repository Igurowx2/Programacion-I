#include <iostream>
using namespace std;

/*void calculadora(float a, float b) {
    cout << "La suma es : " << a + b << endl;
    cout << "La resta es : " << a - b << endl;
    cout << "La multiplicación es : " << a * b << endl;
    if (b != 0)
        cout << "La división es : " << a / b << endl;
    else
        cout << "La división no es posible (división por cero)" << endl;
}

int main() {
    float n1 = 10, n2 = 15;

    calculadora(n1, n2);

    return 0;
}*/

int main() {
    float n1, n2;

    cout << "Digite los dos numeros: "; cin >> n1 >> n2;

    cout << "La suma es : " << n1 + n2 << endl;
    cout << "La resta es : " << n1 - n2 << endl;
    cout << "La multiplicación es : " << n1 * n2 << endl;

    if (n2 != 0)
        cout << "La división es : " << n1 / n2 << endl;
    else
        cout << "La división no es posible (división por cero)" << endl;

    return 0;
}