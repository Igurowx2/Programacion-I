#include <iostream>
using namespace std;

int main() {
    double monto;
    int tipo;
    cout << "Ingrese el monto: "; cin >> monto;
    cout << "Tipo de cliente (1=Normal, 2=VIP, 3=Premium): "; cin >> tipo;

    double descuento = 0;
    if (tipo == 2)
        descuento = 0.20;
    else if (tipo == 3)
        descuento = 0.30;

    double total = monto - (monto * descuento);
    cout << "Descuento aplicado: " << (descuento * 100) << "%" << endl;
    cout << "Total a pagar: " << total << endl;

    return 0;
}