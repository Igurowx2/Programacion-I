#include <iostream>
using namespace std;

// funcion que suma dos numeros mediante punteros
// recibe las direcciones de los dos numeros y la direccion donde guardar el resultado
void sumaPunteros(int* a, int* b, int* resultado) {
    *resultado = *a + *b;   // se accede al valor mediante los punteros y se suman
}

int main() {
    int num1, num2, suma;

    cout << "Ingrese el primer numero: ";cin >> num1;

    cout << "Ingrese el segundo numero: ";cin >> num2;

    // se llama a la funcion pasando las direcciones de las variables
    sumaPunteros(&num1, &num2, &suma);

    cout << "La suma es: " << suma << endl;

    return 0;
}