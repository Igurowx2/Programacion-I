#include <iostream>
#include <string>
using namespace std;

int main() {
    const string TARJETA_CORRECTA = "4578";
    string contrasenia = "2025";
    float saldo = 2500.0;
    int opc;
    bool continuar = true; // Controla el ciclo principal del cajero
 
    do {
        string tarjetaIngresada, claveIngresada;
        cout << "\nDigite el numero de la tarjeta: "; cin >> tarjetaIngresada;
        cout << "Digite la contraseña: "; cin >> claveIngresada;

        if (tarjetaIngresada == TARJETA_CORRECTA && claveIngresada == contrasenia) {
            do {
                cout << "\n\t===== Bienvenido al cajero automatico =====\n";
                cout << "1. Consultar Saldo\n";
                cout << "2. Realizar Retiro\n";
                cout << "3. Realizar Deposito\n";
                cout << "4. Cambio de contraseña\n";
                cout << "5. Autenticarse nuevamente\n";
                cout << "6. Salir del sistema\n";
                cout << "Opcion: "; cin >> opc;

                switch (opc) {
                case 1:
                    cout << "El saldo disponible es: " << saldo << endl;
                    break;

                case 2: {
                    float retiro;
                    cout << "Ingrese la cantidad a retirar: "; cin >> retiro;
                    if (saldo >= retiro) {
                        saldo -= retiro; // saldo = saldo - retiro
                        cout << "Retiro exitoso. Su saldo ahora es: " << saldo << endl;
                    } else {
                        cout << "Saldo insuficiente. Operacion cancelada." << endl;
                    }
                    break;
                }

                case 3: {
                    float deposito;
                    cout << "Ingrese la cantidad a depositar: "; cin >> deposito;
                    saldo += deposito; // saldo = saldo + deposito
                    cout << "Deposito exitoso. Su saldo ahora es: " << saldo << endl;
                    break;
                }

                case 4: {
                    string claveActual, nuevaClave;
                    cout << "Ingrese su contraseña actual para validar: "; cin >> claveActual;
                    if (claveActual == contrasenia) {
                        cout << "Ingrese su nueva contraseña: "; cin >> nuevaClave;
                        contrasenia = nuevaClave;
                        cout << "contraseña modificada exitosamente." << endl;
                    } else {
                        cout << "Contraseña incorrecta. No se realizo el cambio." << endl;
                    }
                    break;
                }

                case 5: {
                    string tarjetaRe, claveRe; //Reautenticación
                    cout << "Digite su numero de tarjeta : "; cin >> tarjetaRe;
                    cout <<"Digite su contraseña : "; cin >> claveRe;
                    if (tarjetaRe == TARJETA_CORRECTA && claveRe == contrasenia) {
                        cout << "Autenticacion exitosa. Todo esta correcto." << endl;
                    } else {
                        cout << "Datos incorrectos. Autenticacion fallida." << endl;
                    }
                    break;
                }

                case 6:
                    cout << "Saliendo del programa..." << endl;
                    break;

                default:
                    cout << "Opcion no valida. Intente de nuevo." << endl;
                }

            } while (opc != 6);

        } else {
            cout << "Numero de tarjeta o contraseña incorrectos." << endl;
        }
        char respuesta;
        cout << "\n¿Desea continuar usando el cajero? (Y/N): "; cin >> respuesta;
        if (respuesta == 'Y' || respuesta == 'y' || respuesta == 'O' || respuesta == 'o') {
            continuar = true; // Volver a pedir tarjeta y contraseña
        } else {
            continuar = false; // Terminar el programa completamente
            cout << "Gracias por usar el cajero." << endl;
        }

    } while (continuar); // El ciclo externo se repite si el usuario quiere seguir

    return 0;
}