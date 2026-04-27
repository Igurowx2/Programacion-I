#include <iostream>
using namespace std;

int main() {
    int sumaPares = 0, sumaImpares = 0;
    for (int i = 1; i <= 100; i++) {
        if (i % 2 == 0)
            sumaPares += i;
        else
            sumaImpares += i;
    }
    cout << "Suma de numeros pares (1 al 100): " << sumaPares << endl;
    cout << "Suma de numeros impares (1 al 100): " << sumaImpares << endl;
    return 0;
}