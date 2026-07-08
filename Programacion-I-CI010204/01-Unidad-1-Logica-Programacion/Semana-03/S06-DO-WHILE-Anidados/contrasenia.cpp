#include <iostream>
using namespace std;

int main() {
    string clave = "123456";

    do{
        cout << "Digite la contraseña : " ; cin >> clave;

    }while(clave != "123456");

    cout << "Acceso autorizado" << endl;

    return 0;
}