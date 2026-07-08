#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

int main() {
    int divisor, dividendo;
    float resultado;

    cout << "Ingrese el dividendo: "; cin >> dividendo;
    cout << "Ingrese el divisor: "; cin >> divisor;

    try {
        if (divisor == 0) {
            throw runtime_error("Error al dividir por cero.");
        }
        resultado = static_cast<float>(dividendo) / divisor;
        cout << "El resultado es: " << resultado << endl;
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

    return 0;
}


/*Requerimientos , diseño , desarrollo , excepciones , pruebas , implementación , producción , mantenimiento*/