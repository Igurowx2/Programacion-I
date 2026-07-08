#include <iostream>
#include <exception>
using namespace std;

// excepcion personalizada para saldo insuficiente
class SaldoInsuficiente : public exception {
public:
    const char* what() const noexcept override {
        return "Error: saldo insuficiente para realizar el retiro";
    }
};

// clase cuenta bancaria
class Cuenta {
private:
    double saldo;
public:
    Cuenta(double saldoInicial) : saldo(saldoInicial) {}

    double getSaldo() const { return saldo; }

    void retirar(double monto) {
        if (monto > saldo) {
            throw SaldoInsuficiente();
        }
        saldo -= monto;
        cout << "Retiro exitoso, nuevo saldo: " << saldo << endl;
    }
};

int main() {
    Cuenta miCuenta(1000.0);
    double monto;

    cout << "Saldo actual: " << miCuenta.getSaldo() << endl;
    cout << "Ingrese el monto a retirar: "; cin >> monto;

    try {
        miCuenta.retirar(monto);
    } catch (const SaldoInsuficiente& e) {
        cout << e.what() << endl;
    }

    return 0;
}