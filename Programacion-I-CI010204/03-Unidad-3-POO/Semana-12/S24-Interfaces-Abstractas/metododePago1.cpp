/*1. Diseñar un programa de metodo de pago -> hacer uso de clase interface 
-Procesar pago (double-pago) -> (Tarjeta de credito - Yape - Transferencia) , esos tres metodos de pago*/
#include <iostream>
#include <string>
using namespace std;

// clase abstracta que define la interfaz para cualquier metodo de pago
// contiene metodos virtuales puros que las clases hijas deben implementar
class MetodoPago {
    private:
        double _monto;
    public:
        MetodoPago(double monto = 0) : _monto(monto) {}
        // metodo para solicitar el monto al usuario
        virtual void setMonto() = 0;
        // metodo para obtener el monto como cadena
        virtual string getMonto() const = 0;
        // metodo que procesa el pago y muestra el resultado
        virtual void procesarPago() = 0;
};

// clase para pago con tarjeta de credito
class TarjetaCredito : public MetodoPago {
    private:
        double _monto;
    public:
        TarjetaCredito() : MetodoPago(), _monto(0) {}
        // pide al usuario ingresar el monto para este metodo
        void setMonto() override {
            cout << "Ingrese el monto para tarjeta de credito: S/";cin >> _monto;
        }
        // convierte el monto a string para mostrarlo
        string getMonto() const override {
            return to_string(_monto);
        }
        // muestra que el pago fue procesado exitosamente
        void procesarPago() override {
            cout << "Tarjeta de Credito: S/" << _monto << " procesado correctamente" << endl;
        }
};

// clase para pago con yape
class Yape : public MetodoPago {
    private:
        double _monto;
    public:
        Yape() : MetodoPago(), _monto(0) {}
        // pide el monto para yape
        void setMonto() override {
            cout << "Ingrese el monto para Yape: S/";cin >> _monto;
        }
        string getMonto() const override {
            return to_string(_monto);
        }
        void procesarPago() override {
            cout << "Yape: S/" << _monto << " procesado correctamente" << endl;
        }
};

// clase para pago con transferencia bancaria
class Transferencia : public MetodoPago {
    private:
        double _monto;
    public:
        Transferencia() : MetodoPago(), _monto(0) {}
        // pide el monto para transferencia
        void setMonto() override {
            cout << "Ingrese el monto para transferencia: S/";cin >> _monto;
        }
        string getMonto() const override {
            return to_string(_monto);
        }
        void procesarPago() override {
            cout << "Transferencia: S/" << _monto << " procesado correctamente" << endl;
        }
};

int main() {
    cout << "=== SISTEMA DE METODOS DE PAGO ===" << endl;

    // se crean objetos de cada tipo de pago
    TarjetaCredito tc;
    Yape yp;
    Transferencia tr;

    // se ingresan los montos para cada metodo
    tc.setMonto();
    yp.setMonto();
    tr.setMonto();

    // se procesan los pagos y se muestran los resultados
    cout << "\n--- Procesando pagos ---" << endl;
    tc.procesarPago();
    yp.procesarPago();
    tr.procesarPago();

    return 0;
}