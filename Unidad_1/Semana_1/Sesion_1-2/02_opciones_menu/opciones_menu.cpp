#include <iostream>
using namespace std;

int main () {
        int opc = 0;

        do{
            cout <<"\n\t======Opciones======\n";
            cout << "Ingrese las opciones \n";
            cout << "1. Suma \n";
            cout << "2. Resta \n";
            cout << "3. Multiplicación \n";
            cout << "4. Division \n";
            cout << "5. Salir \n";
            cout << "Opcion : " ; cin >> opc;

        }while(opc != 5);

        cout << "Saliendo del Programa............\n";

    return 0;
}