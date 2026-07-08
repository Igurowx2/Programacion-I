#include <iostream>
#include <string>
using namespace std;

// Clase abstracta vehiculo
class Vehiculo {
    private:
        float _velocidad;
    public:
    Vehiculo(float velocidad) : _velocidad(velocidad) {}
        virtual void set_velocidad() = 0;
        virtual string get_velocidad() = 0;
};

class Moto : public Vehiculo {
    private:
        float _velocidad;
    public:
        void set_velocidad() {
            cout << "Ingrese la velocidad de la moto: "; cin >> _velocidad;
        }
        string get_velocidad() {
            return to_string(_velocidad);
        }
};

class Carro : public Vehiculo {
    private:
        float _velocidad;
    public:
        void set_velocidad() {
            cout << "Ingrese la velocidad del carro: "; cin >> _velocidad;
        }
        string get_velocidad() {
            return to_string(_velocidad);
        }
};

int main () {
    Moto moto;
    Carro carro;

    moto.set_velocidad();
    carro.set_velocidad();

    cout << "La velocidad de la moto es: " << moto.get_velocidad() << " Km/h" << endl;
    cout << "La velocidad del carro es: " << carro.get_velocidad() << " Km/h" << endl;

    return 0;
}