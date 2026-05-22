#include <iostream>
using namespace std;

int main() {
    int anio;

    cout << "Ingrese un año: "; cin >> anio;

    // Verificar si es bisiesto
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        cout << anio << " es un año bisiesto." << endl;
    } else {
        cout << anio << " NO es un año bisiesto." << endl;
    }

    return 0;
}