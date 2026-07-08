/*1. Elabora un programa que realice las funciones de una calculadora, el sistema debe solicitar opciones al usuario (5:salir)
debe contener una resultado acumulado
Autor: Trujillo Aguirre Maykel
Fecha: 21/05/2026*/
#include <iostream>
using namespace std;

int main() {
    int opc;                                 // Almacena la opción del menú elegida por el usuario
    float numero1, numero2, resultado, resultado_acumulado = 0; // Variables para operandos, resultado actual y acumulador
    char seguir = 's';                        // Controla si el usuario desea continuar usando la calculadora

    // Bucle principal: se repite mientras el usuario responda 's' o 'S' al terminar una operación
    while (seguir == 's' || seguir == 'S') {
        // Mostrar menú de opciones
        cout << "\n--- CALCULADORA ---" << endl;
        cout << "1. Suma" << endl;
        cout << "2. Resta" << endl;
        cout << "3. Multiplicación" << endl;
        cout << "4. División" << endl;
        cout << "5. Salir" << endl;
        cout << "Opción : "; 
        cin >> opc;

        // Opciones de operación (1 a 4)
        if (opc >= 1 && opc <= 4) {
            // Solicitar los dos números para la operación
            cout << "Ingrese el primer número: "; cin >> numero1;
            cout << "Ingrese el segundo número: "; cin >> numero2;

            // Realizar la operación correspondiente y mostrar el resultado
            switch(opc) {
                case 1: // Suma
                    resultado = numero1 + numero2;
                    cout << "Resultado: " << numero1 << " + " << numero2 << " = " << resultado << endl;
                    resultado_acumulado += resultado;  // Acumula sumando el nuevo resultado
                    break;
                case 2: // Resta
                    resultado = numero1 - numero2;
                    cout << "Resultado: " << numero1 << " - " << numero2 << " = " << resultado << endl;
                    resultado_acumulado -= resultado;  // Acumula restando el nuevo resultado
                    break;
                case 3: // Multiplicación
                    resultado = numero1 * numero2;
                    cout << "Resultado: " << numero1 << " * " << numero2 << " = " << resultado << endl;
                    resultado_acumulado *= resultado;  // Acumula multiplicando por el nuevo resultado
                    break;
                case 4: // División
                    if (numero2 != 0) {  // Validar división entre cero
                        resultado = numero1 / numero2;
                        cout << "Resultado: " << numero1 << " / " << numero2 << " = " << resultado << endl;
                        resultado_acumulado /= resultado;  // Acumula dividiendo entre el nuevo resultado
                    } else {
                        cout << "No se puede dividir entre cero." << endl;
                    }
                    break;
            }

            // Preguntar al usuario si desea continuar, con validación de respuesta
            do {
                cout << "¿Desea continuar? (S/N): "; cin >> seguir;
                if (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N') {
                    cout << "Respuesta no válida. Por favor ingrese S o N." << endl;
                }
            } while (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');

            // Mostrar el resultado acumulado después de cada operación
            cout << "El resultado acumulado es: " << resultado_acumulado << endl;
        }
        else if (opc == 5) {  // Opción para salir del programa
            cout << "Saliendo de la calculadora ......" << endl;
            cout << "El resultado acumulado final es: " << resultado_acumulado << endl;
            break;  // Rompe el bucle while y termina la ejecución
        }
        else {  // Opción no válida
            cout << "Opción inválida." << endl;
            // Se pregunta si desea continuar a pesar de la opción incorrecta
            do {
                cout << "¿Desea continuar? (S/N): "; cin >> seguir;
                if (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N') {
                    cout << "Respuesta no válida. Por favor ingrese S o N." << endl;
                }
            } while (seguir != 's' && seguir != 'S' && seguir != 'n' && seguir != 'N');
        }
    } // Fin del while principal

    return 0;
}