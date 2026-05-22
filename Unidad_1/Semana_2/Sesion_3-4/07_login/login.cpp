#include <iostream>
using namespace std;

int main() {
    string usuarioCorrecto = "admin";
    string passwordCorrecto = "1234";
    string usuario, password;
    int intentos = 3;

    do {
        cout << "Usuario: "; cin >> usuario;
        cout << "Contraseña: "; cin >> password;

        if (usuario == usuarioCorrecto && password == passwordCorrecto) {
            cout << "Acceso concedido." << endl;
            break;
        } else {
            intentos--;
            cout << "Acceso denegado. Intentos restantes: " << intentos << endl;
        }
    } while (intentos > 0);

    if (intentos == 0) cout << "Cuenta bloqueada." << endl;

    return 0;
}