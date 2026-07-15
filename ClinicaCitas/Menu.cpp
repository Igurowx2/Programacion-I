#include <iostream>
#include <string>
#include "Clinica.cpp" // Incluye toda la lógica de la clínica
using namespace std;

// Función principal: punto de inicio del programa
int main() {
    Clinica clinica;   // Se crea el objeto que maneja las listas y el menú
    clinica.menu();    // Se inicia el menú interactivo
    return 0;          // Fin del programa
}