#include <iostream>
#include <string>
using namespace std;

int main() {
    string tipo;
    double monto, descuento = 0, total;

    cout << "Ingrese el tipo de cliente (normal, VIP, Premium): "; cin >> tipo;
    cout << "Ingrese el monto de la compra: "; cin >> monto;

    // se asigna el porcentaje de descuento segun el tipo
    if (tipo == "normal" || tipo == "Normal") {
        descuento = 0;
    } else if (tipo == "VIP" || tipo == "vip") {
        descuento = 0.20;
    } else if (tipo == "Premium" || tipo == "premium") {
        descuento = 0.30;
    } else {
        cout << "Tipo de cliente no valido, se aplica tarifa normal" << endl;
        descuento = 0;
    }

    total = monto - (monto * descuento);
    cout << "Monto original: " << monto << endl;
    cout << "Descuento aplicado: " << (descuento * 100) << "%" << endl;
    cout << "Total a pagar: " << total << endl;

    return 0;
}