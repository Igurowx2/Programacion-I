#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

// SOBRECARGA — mismo nombre, distintos parámetros (compilación)
void mostrar(int x) { 
    cout << "[INT] " << x << '\n'; 
}
void mostrar(double x) { 
    cout << "[DOUBLE] " << x << '\n'; 
}
void mostrar(const string& x) { 
    cout << "[STRING] " << x << '\n'; 
}

// SOBRESCRITURA — virtual en base, override en derivadas (ejecución)
class Animal {
public:
    virtual void sonido() const {    // virtual permite redefinición
        cout << "Sonido genérico\n"; 
    }
    virtual ~Animal() = default; // destructor virtual para evitar fugas al eliminar por puntero base
};

class Perro : public Animal {
public:
    void sonido() const override {   // override = reemplazo polimórfico
        cout << "Guau\n"; 
    }
};

class Gato : public Animal {
public:
    void sonido() const override {
        cout << "Miau\n"; 
    }
};

int main() {
    // Prueba de sobrecarga (elige en compilación)
    mostrar(10);
    mostrar(2.5);
    mostrar("texto"s); // el sufijo s convierte a std::string

    // Prueba de sobrescritura (elige en tiempo de ejecución)
    unique_ptr<Animal> a1 = make_unique<Perro>();
    unique_ptr<Animal> a2 = make_unique<Gato>();
    a1->sonido();  // Perro::sonido
    a2->sonido();  // Gato::sonido

    // No es necesario eliminar los punteros únicos, se hace automáticamente
    return 0;
}