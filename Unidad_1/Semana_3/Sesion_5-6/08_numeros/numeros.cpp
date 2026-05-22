#include <iostream>
using namespace std;

int main() {
    int nums[4];
    cout << "Ingrese 4 numeros:\n";
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }

    int mayor = nums[0], menor = nums[0], suma = 0;
    for (int i = 0; i < 4; i++) {
        if (nums[i] > mayor) mayor = nums[i];
        if (nums[i] < menor) menor = nums[i];
        suma += nums[i];
    }
    double promedio = suma / 4.0;

    // Ordenar de menor a mayor (burbuja simple)
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (nums[i] > nums[j]) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
    }

    cout << "Mayor: " << mayor << "\nMenor: " << menor << "\nSuma: " << suma
         << "\nPromedio: " << promedio << "\nOrden ascendente: ";
    for (int i = 0; i < 4; i++) cout << nums[i] << " ";
    cout << endl;

    return 0;
}