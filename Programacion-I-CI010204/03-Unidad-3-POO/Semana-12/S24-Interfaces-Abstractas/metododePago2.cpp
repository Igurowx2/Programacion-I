/*2. Sistema de notificaciones
-enviar-mensaje -> clase abstracta (mensaje via correo - SMS , Whatsapp)
*/
#include <iostream>
#include <string>
using namespace std;

// clase abstracta que define el comportamiento general de una notificacion
// tiene metodos para ingresar el mensaje, obtenerlo y enviarlo
class Notificacion {
    private:
        string _mensaje;
    public:
        Notificacion(const string& mensaje = "") : _mensaje(mensaje) {}
        // metodo para pedir el mensaje al usuario
        virtual void setMensaje() = 0;
        // metodo para obtener el mensaje almacenado
        virtual string getMensaje() const = 0;
        // metodo para enviar la notificacion por el medio correspondiente
        virtual void enviarMensaje() = 0;
};

// clase para notificacion via correo electronico
class Correo : public Notificacion {
    private:
        string _mensaje;
    public:
        Correo() : Notificacion(), _mensaje("") {}
        // se pide el mensaje al usuario
        void setMensaje() override {
            cout << "Ingrese el mensaje para correo: ";cin >> _mensaje;
        }
        string getMensaje() const override {
            return _mensaje;
        }
        // simula el envio de un correo
        void enviarMensaje() override {
            cout << "[CORREO] Enviando: " << _mensaje << endl;
        }
};

// clase para notificacion via sms
class SMS : public Notificacion {
    private:
        string _mensaje;
    public:
        SMS() : Notificacion(), _mensaje("") {}
        void setMensaje() override {
            cout << "Ingrese el mensaje para SMS: ";cin >> _mensaje;
        }
        string getMensaje() const override {
            return _mensaje;
        }
        void enviarMensaje() override {
            cout << "[SMS] Enviando: " << _mensaje << endl;
        }
};

// clase para notificacion via whatsapp
class WhatsApp : public Notificacion {
    private:
        string _mensaje;
    public:
        WhatsApp() : Notificacion(), _mensaje("") {}
        void setMensaje() override {
            cout << "Ingrese el mensaje para WhatsApp: ";cin >> _mensaje;   
        }
        string getMensaje() const override {
            return _mensaje;
        }
        void enviarMensaje() override {
            cout << "[WHATSAPP] Enviando: " << _mensaje << endl;
        }
};

int main() {
    cout << "=== SISTEMA DE NOTIFICACIONES ===" << endl;

    // se crean objetos para cada tipo de notificacion
    Correo correo;
    SMS sms;
    WhatsApp whatsapp;

    // se ingresan los mensajes para cada medio
    correo.setMensaje();
    sms.setMensaje();
    whatsapp.setMensaje();

    // se envian todas las notificaciones
    cout << "\n--- Enviando notificaciones ---" << endl;
    correo.enviarMensaje();
    sms.enviarMensaje();
    whatsapp.enviarMensaje();

    return 0;
}