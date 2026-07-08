#include <iostream>
using namespace std;

// multiplica dos enteros usando solo sumas
// muestra el proceso de sumas sucesivas
int multiplicar_con_sumas(int a, int b) {
    int resultado = 0;
    // se usa el segundo numero como contador de sumas
    for (int i = 0; i < b; i++) {
        resultado += a;
        // muestra cada suma parcial
        cout << a;
        if (i < b - 1) {
            cout << " + ";
        }
    }
    return resultado;
}

int main() {
    int num1, num2;
    cout << "Ingrese el primer numero: ";cin >> num1;
    cout << "Ingrese el segundo numero: ";cin >> num2;

    cout << "Multiplicacion " << num1 << " x " << num2 << " = ";
    int producto = multiplicar_con_sumas(num1, num2);
    cout << " = " << producto << endl;

    return 0;
}