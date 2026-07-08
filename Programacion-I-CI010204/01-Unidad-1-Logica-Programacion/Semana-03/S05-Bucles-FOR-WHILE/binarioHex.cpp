#include <iostream>
#include <string>
using namespace std;

// funcion para convertir un numero decimal a binario (como string)
string a_binario(int x) {
    if (x == 0) return "0";
    string bin = "";
    while (x > 0) {
        // se obtiene el residuo (0 o 1) y se agrega al inicio
        bin = char('0' + (x % 2)) + bin;
        x /= 2;
    }
    return bin;
}

// funcion para convertir a hexadecimal (como string)
string a_hexadecimal(int x) {
    if (x == 0) return "0";
    string hex = "";
    char digitos[] = "0123456789ABCDEF";
    while (x > 0) {
        int residuo = x % 16;
        hex = digitos[residuo] + hex;
        x /= 16;
    }
    return hex;
}

int main() {
    int x;
    cout << "Ingrese un numero entero positivo: ";cin >> x;

    if (x < 0) {
        cout << "Solo se aceptan numeros no negativos" << endl;
        return 1;
    }

    cout << "Binario: " << a_binario(x) << endl;
    cout << "Hexadecimal: " << a_hexadecimal(x) << endl;

    return 0;
}