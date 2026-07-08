#include <iostream>
using namespace std;

int main() {
    int edad;
    cout << "Ingrese la edad de la persona: "; cin >> edad;

    if (edad >= 0 && edad <= 12) {
        cout << "Clasificacion: Ninio" << endl;
    } else if (edad >= 13 && edad <= 17) {
        cout << "Clasificacion: Adolescente" << endl;
    } else if (edad >= 18 && edad <= 59) {
        cout << "Clasificacion: Adulto" << endl;
    } else if (edad >= 60 && edad <= 90) {
        cout << "Clasificacion: Adulto Mayor" << endl;
    } else {
        cout << "Edad fuera de los rangos establecidos" << endl;
    }

    return 0;
}