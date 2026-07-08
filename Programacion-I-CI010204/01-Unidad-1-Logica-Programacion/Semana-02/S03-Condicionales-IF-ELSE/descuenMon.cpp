#include <iostream>
using namespace std;

int main() {
    double compra, descuento = 0, total;

    cout << "Ingrese el monto de la compra: "; cin >> compra;

    // se asigna el porcentaje segun el monto
    if (compra > 500) {
        descuento = 0.05;
    } else if (compra > 200) {
        descuento = 0.02;
    } else if (compra > 100) {
        descuento = 0.01;
    } else {
        descuento = 0;
    }

    total = compra - (compra * descuento);

    cout << "Compra original: " << compra << endl;
    cout << "Descuento aplicado: " << (descuento * 100) << "%" << endl;
    cout << "Total con descuento: " << total << endl;

    return 0;
}