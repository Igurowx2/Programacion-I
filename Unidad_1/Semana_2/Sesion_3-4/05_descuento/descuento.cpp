#include <iostream>
using namespace std;

int main() {
    double compra, descuento = 0;
    cout << "Ingrese el monto de la compra: "; SScin >> compra;

    if (compra > 500)
        descuento = compra * 0.05;
    else if (compra > 200)
        descuento = compra * 0.02;
    else if (compra > 100)
        descuento = compra * 0.01;

    double total = compra - descuento;
    cout << "Descuento: " << descuento << endl;
    cout << "Total a pagar: " << total << endl;

    return 0;
}