#include <iostream>
using namespace std;

int main() {
    int A = 20, B = 30;
    int *ptrA = &A;
    int *ptrB = &B;

    cout << "Antes del intercambio:\n";
    cout << "A = " << A << ", B = " << B << endl;

    int aux = *ptrA;
    *ptrA = *ptrB;
    *ptrB = aux;

    cout << "Después del intercambio:\n";
    cout << "A = " << A << ", B = " << B << endl;

    return 0;
}