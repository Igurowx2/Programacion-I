#include <iostream>
using namespace std;

int main() {
    int dia;

    cout << "Digite un numero : " ; cin >> dia;

    switch(dia){
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
               cout << "Dia laborable" << endl; ; break;
        case 6:
        case 7:
               cout << "Dia no laborable" << endl; ; break;
        default :
              cout << "Ingreso un digito no valido" << endl; break;
    }

    return 0;
}