#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
// Interfaz para inspeccionar cualquier bien
class Inspeccionable {
public:
    virtual void inspeccionar() = 0;
    virtual void registrarDanios(const string& danio) = 0;
    virtual void revisarCombustible() = 0;
    virtual ~Inspeccionable() {}
};
// Clase abstracta Vehiculo
class Vehiculo : public Inspeccionable {
private:
    const string placa;      // no se puede cambiar despues de crear
    string marca;
    string modelo;
    int anio;
    double tarifaDiaria;
    vector<string> danios;
public:
    // Constructor con todos los datos obligatorios
    Vehiculo(const string& placa, const string& marca, const string& modelo, int anio, double tarifaDiaria) : placa(placa) {
        this->marca = marca;
        this->modelo = modelo;
        this->anio = anio;
        this->tarifaDiaria = tarifaDiaria;
        // Validar año: no puede ser menor a 1900 ni mayor al actual
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        int anioActual = now->tm_year + 1900;
        if (this->anio < 1900 || this->anio > anioActual) {
            this->anio = anioActual;   // si es invalido, pongo el actual
        }
        // Validar tarifa: no puede ser negativa
        if (this->tarifaDiaria < 0) {
            this->tarifaDiaria = 0;
        }
    }
    virtual ~Vehiculo() {}
    // Getters
    string getPlaca() const {
        return placa;
    }
    string getMarca() const {
        return marca;
    }
    string getModelo() const {
        return modelo;
    }
    int getAnio() const {
        return anio;
    }
    double getTarifaDiaria() const {
        return tarifaDiaria;
    }
    // Setters con validacion
    void setMarca(const string& marca) {
        if (!marca.empty()) {
            this->marca = marca;
        }
    }
    void setModelo(const string& modelo) {
        if (!modelo.empty()) {
            this->modelo = modelo;
        }
    }
    void setAnio(int anio) {
        time_t t = time(nullptr);
        tm* now = localtime(&t);
        int anioActual = now->tm_year + 1900;
        if (anio >= 1900 && anio <= anioActual) {
            this->anio = anio;
        }
        // si no es valido, no se cambia
    }
    void setTarifaDiaria(double tarifa) {
        if (tarifa >= 0) {
            this->tarifaDiaria = tarifa;
        }
    }
    // Metodos abstractos (polimorfismo)
    virtual double calcularCosto(int dias) const = 0;
    virtual void mostrarInfo() const = 0;
    // Implementacion de la interfaz Inspeccionable
    void inspeccionar() override {
        cout << "Inspeccionando vehiculo con placa: " << placa << endl;
        revisarCombustible();
        if (danios.empty()) {
            cout << "No hay danios registrados." << endl;
        } else {
            cout << "Danios: ";
            for (int i = 0; i < danios.size(); i++) {
                cout << danios[i] << "; ";
            }
            cout << endl;
        }
    }
    void registrarDanios(const string& danio) override {
        danios.push_back(danio);
    }
    void revisarCombustible() override {
        cout << "Nivel de combustible: Normal" << endl;
    }
};
// Clase Automovil (hereda de Vehiculo)
class Automovil : public Vehiculo {
public:
    Automovil(const string& placa, const string& marca, const string& modelo, int anio, double tarifaDiaria) : Vehiculo(placa, marca, modelo, anio, tarifaDiaria) {}

    double calcularCosto(int dias) const override {
        return getTarifaDiaria() * dias;   // sin recargos
    }
    void mostrarInfo() const override {
        cout << "Automovil - Placa: " << getPlaca() << ", Marca: " << getMarca() << ", Modelo: " << getModelo() << ", Anio: " << getAnio() << ", Tarifa diaria: S/" << getTarifaDiaria() << endl;
    }
};
// Clase Motocicleta (hereda de Vehiculo)
class Motocicleta : public Vehiculo {
public:
    Motocicleta(const string& placa, const string& marca, const string& modelo, int anio, double tarifaDiaria) : Vehiculo(placa, marca, modelo, anio, tarifaDiaria) {}
    double calcularCosto(int dias) const override {
        double costo = getTarifaDiaria() * dias;
        if (dias > 3) {
            costo = costo * 0.9;   // descuento del 10% por alquiler largo
        }
        return costo;
    }
    void mostrarInfo() const override {
        cout << "Motocicleta - Placa: " << getPlaca() << ", Marca: " << getMarca() << ", Modelo: " << getModelo() << ", Anio: " << getAnio() << ", Tarifa diaria: S/" << getTarifaDiaria() << endl;
    }
};
// Clase Camioneta (hereda de Vehiculo)
class Camioneta : public Vehiculo {
private:
    double capacidadCarga;
public:
    Camioneta(const string& placa, const string& marca, const string& modelo,  int anio, double tarifaDiaria, double capacidadCarga) : Vehiculo(placa, marca, modelo, anio, tarifaDiaria) {
        this->capacidadCarga = capacidadCarga;
        if (this->capacidadCarga < 0) {
            this->capacidadCarga = 0;
        }
    }
    double calcularCosto(int dias) const override {
        double costo = getTarifaDiaria() * dias;
        costo = costo * 1.15;   // recargo del 15% por ser carga
        return costo;
    }
    void mostrarInfo() const override {
        cout << "Camioneta - Placa: " << getPlaca() << ", Marca: " << getMarca() << ", Modelo: " << getModelo() << ", Anio: " << getAnio() << ", Tarifa diaria: S/" << getTarifaDiaria() << ", Capacidad de carga: " << capacidadCarga << " kg" << endl;
    }
    double getCapacidadCarga() const {
        return capacidadCarga;
    }
    void setCapacidadCarga(double cap) {
        if (cap >= 0) {
            capacidadCarga = cap;
        }
    }
};
// Otra clase que solo implementa la interfaz (no es vehiculo)
class BicicletaElectrica : public Inspeccionable {
private:
    string modelo;
    int bateria;
    vector<string> danios;
public:
    BicicletaElectrica(const string& modelo, int bateria) {
        this->modelo = modelo;
        this->bateria = bateria;
        if (this->bateria < 0) this->bateria = 0;
        if (this->bateria > 100) this->bateria = 100;
    }
    void inspeccionar() override {
        cout << "Inspeccionando bicicleta electrica " << modelo << endl;
        revisarCombustible();
        if (danios.empty()) {
            cout << "Sin danios." << endl;
        } else {
            cout << "Danios: ";
            for (int i = 0; i < danios.size(); i++) {
                cout << danios[i] << "; ";
            }
            cout << endl;
        }
    }
    void registrarDanios(const string& danio) override {
        danios.push_back(danio);
    }
    void revisarCombustible() override {
        cout << "Bateria al " << bateria << "%" << endl;
    }
};
// Sobrecarga de funciones para mostrar costo
void mostrarCosto(const Vehiculo& v, int dias) {
    cout << "Costo por " << dias << " dias: S/" << v.calcularCosto(dias) << endl;
}
void mostrarCosto(const Vehiculo& v) {
    cout << "Costo por 1 dia (por defecto): S/" << v.calcularCosto(1) << endl;
}
int main() {
    // Crear objetos de cada tipo
    Automovil auto1("ABC-123", "Toyota", "Corolla", 2020, 50.0);
    Motocicleta moto1("XYZ-456", "Honda", "CBR", 2021, 30.0);
    Camioneta cam1("DEF-789", "Ford", "Ranger", 2019, 70.0, 1000.0);
    // Polimorfismo: guardo punteros a Vehiculo
    vector<Vehiculo*> vehiculos;
    vehiculos.push_back(&auto1);
    vehiculos.push_back(&moto1);
    vehiculos.push_back(&cam1);
    cout << "=== LISTA DE VEHICULOS ===" << endl;
    for (int i = 0; i < vehiculos.size(); i++) {
        vehiculos[i]->mostrarInfo();          // cada uno muestra su tipo
        mostrarCosto(*vehiculos[i], 5);       // sobrecarga con 5 dias
        cout << endl;
    }
    // Inspeccion usando la interfaz
    cout << "=== INSPECCION DE VEHICULOS ===" << endl;
    for (int i = 0; i < vehiculos.size(); i++) {
        vehiculos[i]->inspeccionar();
        cout << endl;
    }
    // Registrar un danio en el auto y volver a inspeccionar
    auto1.registrarDanios("Rayon en puerta delantera");
    auto1.inspeccionar();
    // Bicicleta electrica (no es vehiculo pero si inspeccionable)
    BicicletaElectrica bici("E-Bike 3000", 80);
    bici.inspeccionar();
    // Prueba de encapsulamiento: no se puede modificar la placa (no hay setter)
    // auto1.setPlaca("NUEVA"); // ERROR de compilacion
    cout << "\nPlaca de auto1: " << auto1.getPlaca() << endl;
    // Validacion de año: no se permite año futuro
    auto1.setAnio(2026);
    cout << "Anio despues de intentar 2026: " << auto1.getAnio() << endl;  // sigue 2026
    auto1.setAnio(2022);
    cout << "Anio despues de setear 2022: " << auto1.getAnio() << endl;    // ahora 2022 setear significa cambiar el valor, no validar. El valor se cambia si es valido.
    // Sobrecarga de mostrarCosto
    /*cout << "\n=== SOBRECARGA DE mostrarCosto ===" << endl;
    mostrarCosto(auto1, 3);   // con dias
    mostrarCosto(moto1);      // sin dias (usa 1 por defecto)*/

    return 0;
}