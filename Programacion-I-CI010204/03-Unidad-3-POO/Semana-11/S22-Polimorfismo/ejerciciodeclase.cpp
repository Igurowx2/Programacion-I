/*Elabora o desarrollar una aplicacion que envia notificaciones a traves de diferentes
canales (correo electrónico, SMS, token) , cada notificacion debe tener un mensaje
y un destinatario , pero el formato y la forma varia de acuerdo a canal
Requisitos:
1. clase base
2. clases por tipo canal
3. Metodos de enviar (enviar prioritario , reenviar , enviar)

Se va a evaluar el uso de herencia , polimorfismo, sobreescritura y sobrecarga de metodos
*/
#include <iostream>
#include <string>
#include <memory> // gestión de memoria dinámica segura y eficiente
#include <vector> // arreglos dinámicos que permiten almacenar objetos de forma flexible
using namespace std;

// Clase base abstracta para notificaciones , sobreescritura de metodo enviar
class Notificacion {
public:
    // Método abstracto para enviar notificación (sobreescrito por cada canal)
    virtual void enviar(const string& mensaje, const string& destinatario) const = 0;
    
    // Sobrecarga del método enviar para envío prioritario
    virtual void enviar(const string& mensaje, const string& destinatario, bool prioritario) const {
        if (prioritario) cout << "PRIORITARIO: ";
        enviar(mensaje, destinatario); // delega en la versión del canal concreto
    }
    
    // Método para reenviar una notificación (usa el método enviar del canal)
    virtual void reenviar(const string& mensaje, const string& destinatario) const {
        cout << "Reenviando... ";
        enviar(mensaje, destinatario);
    }
    
    virtual ~Notificacion() = default; // destructor virtual
};

// Clase por tipo de canales que heredan de Notificacion y sobreescriben el metodo enviar con su formato especifico
class Correo : public Notificacion { 
public:
    void enviar(const string& mensaje, const string& destinatario) const override {
        cout << "Enviando correo a " << destinatario << ": " << mensaje << '\n';
    }
};

class SMS : public Notificacion {
public:
    void enviar(const string& mensaje, const string& destinatario) const override {
        cout << "Enviando SMS a " << destinatario << ": " << mensaje << '\n';
    }
};

class Token : public Notificacion {
    public:
    void enviar(const string& mensaje, const string& destinatario) const override { 
        cout << "Enviando token a " << destinatario << ": " << mensaje << '\n';
    }
};

int main() {
    vector<unique_ptr<Notificacion>> notificaciones; // vector de punteros únicos a Notificacion
    notificaciones.push_back(make_unique<Correo>()); // agregar instancia de Correo
    notificaciones.push_back(make_unique<SMS>());    // agregar instancia de SMS
    notificaciones.push_back(make_unique<Token>());  // agregar instancia de Token

    for (const auto& n : notificaciones) { // iterar sobre las notificaciones
        // Envío normal
        n->enviar("¡Hola!", "Igurow@gmail.com");
        // Envío prioritario (sobrecarga)
        n->enviar("¡Urgente!", "Igurow@gmail.com", true);
        // Reenviar notificación
        n->reenviar("Recordatorio", "Igurow@gmail.com");
        n->enviar("¡Adiós!", "Igurow@gmail.com");
         cout << "-------------------------\n"; // separador entre canales
    }
    return 0;
}

/*Bien hecho y documentado , siguiente semana*/