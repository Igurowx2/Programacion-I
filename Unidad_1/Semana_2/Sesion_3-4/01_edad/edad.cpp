#include <iostream>
using namespace std;

int main() {
    int edad;
    cout << "Ingrese su edad: "; cin >> edad;

    if (edad >= 0 && edad <= 12)
        cout << "Clasificacion: Nino" << endl;
    else if (edad <= 17)
        cout << "Clasificacion: Adolescente" << endl;
    else if (edad <= 59)
        cout << "Clasificacion: Adulto" << endl;
    else if (edad <= 90)
        cout << "Clasificacion: Adulto Mayor" << endl;
    else
        cout << "Edad fuera de rango" << endl;

    return 0;
}