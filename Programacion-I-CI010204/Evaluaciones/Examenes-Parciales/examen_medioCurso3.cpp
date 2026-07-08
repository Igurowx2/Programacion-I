/*3. Un número es considerado especial si la suma de sus dígitos puede
calcularse hasta obtener un solo dígito.
a. Solicite ingresar un número por teclado
b. Desarrolle una función recursiva
c. Debe obtener el resultado esperado -> un dígito
Ejemplo: 987 -> 9+8+7 = 24 -> 2+4 = 6
Autor : Trujillo Aguirre Maykel
Código : 0020250411
Fecha : 01/06/2026
*/
#include <iostream>
using namespace std;

int reducirADigito(int n) {
    // Caso base 
    if (n < 10) {
        return n;
    }

    // Paso recursivo: sumar los dígitos de n
    int suma = 0;
    while (n > 0) {
        suma += n % 10;  // Obtiene el último dígito y lo suma
        n /= 10;         // Elimina el último dígito
    }

    // Llamada recursiva con la nueva suma
    return reducirADigito(suma);
}

int main() {
    int numero;

    // a. Solicitar número por teclado
    cout << "Ingrese un numero entero positivo: "; cin >> numero;

    // Validación 
    while (numero < 0) {
        cout << "Por favor, ingrese un numero no negativo: "; cin >> numero;
    }

    // b y c. Llamar a la función recursiva y obtener el dígito final
    int digitoEspecial = reducirADigito(numero);

    // Mostrar resultado
    cout << "\nEl digito especial de " << numero << " es: " << digitoEspecial << endl;

    return 0;
}