#include <iostream>
using namespace std;

int main() {
    int a, b, c, suma;
    int *pa = &a , *pb = &b , *pc = &c , *ps = &suma;

    cout << "Digite el valor de a : "; cin >> *pa;
    cout << "Digite el valor de b : " ; cin >> *pb;
    cout << "Digite el valor de c : " ; cin >> *pc;

    *ps = *pa + *pb + *pc;

    cout << "La suma es: " << suma << endl;
    return 0;
}