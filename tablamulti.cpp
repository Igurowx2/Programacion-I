#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Ingrese un número: ";cin >> num;

    for (int i = 1; i <= 13; i++) {
        cout << num << " x " << i << " = " << num * i << endl;
    }

    return 0;
}