#include <iostream>
using namespace std;

void porValor(int x){
    cout << "Dentro del rango : "  << x * 2 << endl;
}
void porReferencia(int &x){
    cout << "Dentro del rango : " << x * 2 << endl;
}
int main () {
    int a = 10, b = 10;
    porValor(a); cout << "Fuera del rango : " << a << endl;
    porReferencia(b); cout << "Fuera del rango : " << b << endl;

    return 0;
}