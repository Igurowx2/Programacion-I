/*3. Cree un sistema para clasificar mascotas que ingresan el tipo , debe mostrar el sonido
que emite el animal (escoger el tipo y el mensaje->sonido)
hacerlo libre con interface o abstracta - codigo comentado */
#include <iostream>
#include <string>
using namespace std;

// clase abstracta que representa a un animal
// define metodos para obtener el tipo y emitir el sonido caracteristico
class Animal {
    private:
        string _tipo;
    public:
        Animal(const string& tipo = "") : _tipo(tipo) {}
        // metodo para ingresar el tipo de animal
        virtual void setTipo() = 0;
        // metodo para obtener el tipo
        virtual string getTipo() const = 0;
        // metodo que emite el sonido del animal
        virtual void sonido() const = 0;
};

// clase perro
class Perro : public Animal {
    private:
        string _tipo;
    public:
        Perro() : Animal(), _tipo("Perro") {}
        // se pide al usuario que confirme el tipo
        void setTipo() override {
            cout << "Ingrese el tipo de animal (Perro): ";
            cin >> _tipo;
        }
        string getTipo() const override {
            return _tipo;
        }
        // sonido que hace el perro
        void sonido() const override {
            cout << "Guau guau" << endl;
        }
};

// clase gato
class Gato : public Animal {
    private:
        string _tipo;
    public:
        Gato() : Animal(), _tipo("Gato") {}
        void setTipo() override {
            cout << "Ingrese el tipo de animal (Gato): ";
            cin >> _tipo;
        }
        string getTipo() const override {
            return _tipo;
        }
        // sonido que hace el gato
        void sonido() const override {
            cout << "Miau miau" << endl;
        }
};

// clase vaca
class Vaca : public Animal {
    private:
        string _tipo;
    public:
        Vaca() : Animal(), _tipo("Vaca") {}
        void setTipo() override {
            cout << "Ingrese el tipo de animal (Vaca): ";
            cin >> _tipo;
        }
        string getTipo() const override {
            return _tipo;
        }
        // sonido que hace la vaca
        void sonido() const override {
            cout << "Muuuu" << endl;
        }
};

int main() {
    cout << "=== CLASIFICACION DE MASCOTAS ===" << endl;

    // se instancian los tres animales
    Perro perro;
    Gato gato;
    Vaca vaca;

    // se pide el tipo para cada uno
    perro.setTipo();
    gato.setTipo();
    vaca.setTipo();

    // se muestra el tipo y el sonido correspondiente
    cout << "\n--- Sonidos de los animales ---" << endl;
    cout << perro.getTipo() << " -> ";
    perro.sonido();

    cout << gato.getTipo() << " -> ";
    gato.sonido();

    cout << vaca.getTipo() << " -> ";
    vaca.sonido();

    return 0;
}