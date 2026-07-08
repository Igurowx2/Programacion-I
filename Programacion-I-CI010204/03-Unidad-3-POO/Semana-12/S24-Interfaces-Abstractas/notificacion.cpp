#include <iostream>
#include <string>
using namespace std;

// clase base abstracta para todas las notificaciones
class Notificacion {
    protected:
        string mensaje;      // contenido de la notificacion
        string destinatario; // a quien va dirigida
        string propietario;  // dueño del sistema o usuario actual
    public:
        Notificacion(const string& msg = "", const string& dest = "", const string& prop = "") : mensaje(msg), destinatario(dest), propietario(prop) {}

        // metodos virtuales puros que cada canal debe implementar
        virtual void enviar() = 0;                           // envia al destinatario
        virtual void enviarPropietario() = 0;                // envia al propietario
        virtual void reenviar(const string& nuevoDest) = 0;  // reenvia a otro destinatario

        // getters comunes
        string getMensaje() const { return mensaje; }
        string getDestinatario() const { return destinatario; }
        string getPropietario() const { return propietario; }

        // setters
        void setMensaje(const string& msg) { mensaje = msg; }
        void setDestinatario(const string& dest) { destinatario = dest; }
        void setPropietario(const string& prop) { propietario = prop; }

        virtual ~Notificacion() {}
};

// canal correo electronico
class Correo : public Notificacion {
    public:
        Correo(const string& msg = "", const string& dest = "", const string& prop = "")
            : Notificacion(msg, dest, prop) {}

        // envia el correo con formato de asunto y cuerpo
        void enviar() override {
            cout << "\n[ENVIAR CORREO]" << endl;
            cout << "Para: " << destinatario << endl;
            cout << "Asunto: Notificacion importante" << endl;
            cout << "Mensaje: " << mensaje << endl;
            cout << "Estado: Enviado por correo" << endl;
        }

        // envia al propietario
        void enviarPropietario() override {
            cout << "\n[ENVIAR CORREO AL PROPIETARIO]" << endl;
            cout << "Para: " << propietario << " (propietario)" << endl;
            cout << "Asunto: Notificacion para el propietario" << endl;
            cout << "Mensaje: " << mensaje << endl;
            cout << "Estado: Enviado al propietario por correo" << endl;
        }

        // reenvia a otro destinatario (mantiene mensaje)
        void reenviar(const string& nuevoDest) override {
            cout << "\n[REENVIAR CORREO]" << endl;
            cout << "Original para: " << destinatario << endl;
            cout << "Reenviado a: " << nuevoDest << endl;
            cout << "Asunto: Reenvio: Notificacion importante" << endl;
            cout << "Mensaje: " << mensaje << endl;
            cout << "Estado: Reenviado por correo" << endl;
        }
};

// canal sms
class SMS : public Notificacion {
    public:
        SMS(const string& msg = "", const string& dest = "", const string& prop = "") : Notificacion(msg, dest, prop) {}

        void enviar() override {
            cout << "\n[ENVIAR SMS]" << endl;
            cout << "Numero: " << destinatario << endl;
            cout << "Mensaje: " << mensaje << " (limite 160 caracteres)" << endl;
            cout << "Estado: Enviado por SMS" << endl;
        }

        void enviarPropietario() override {
            cout << "\n[ENVIAR SMS AL PROPIETARIO]" << endl;
            cout << "Numero: " << propietario << " (propietario)" << endl;
            cout << "Mensaje: " << mensaje << " (limite 160 caracteres)" << endl;
            cout << "Estado: Enviado al propietario por SMS" << endl;
        }

        void reenviar(const string& nuevoDest) override {
            cout << "\n[REENVIAR SMS]" << endl;
            cout << "Original para: " << destinatario << endl;
            cout << "Reenviado a: " << nuevoDest << endl;
            cout << "Mensaje: " << mensaje << " (limite 160 caracteres)" << endl;
            cout << "Estado: Reenviado por SMS" << endl;
        }
};

// canal token (autenticacion)
class Token : public Notificacion {
    private:
        string tokenGenerado;  // token unico generado para la notificacion
    public:
        Token(const string& msg = "", const string& dest = "", const string& prop = "")
            : Notificacion(msg, dest, prop) {
            // se genera un token simple basado en el mensaje y la hora
            tokenGenerado = "TK-" + to_string(msg.length()) + "-" + to_string(dest.length());
        }

        void enviar() override {
            cout << "\n[ENVIAR TOKEN]" << endl;
            cout << "Destinatario: " << destinatario << endl;
            cout << "Token generado: " << tokenGenerado << endl;
            cout << "Mensaje asociado: " << mensaje << endl;
            cout << "Estado: Token enviado" << endl;
        }

        void enviarPropietario() override {
            cout << "\n[ENVIAR TOKEN AL PROPIETARIO]" << endl;
            cout << "Propietario: " << propietario << endl;
            cout << "Token generado: " << tokenGenerado << endl;
            cout << "Mensaje asociado: " << mensaje << endl;
            cout << "Estado: Token enviado al propietario" << endl;
        }

        void reenviar(const string& nuevoDest) override {
            cout << "\n[REENVIAR TOKEN]" << endl;
            cout << "Original para: " << destinatario << endl;
            cout << "Reenviado a: " << nuevoDest << endl;
            cout << "Token generado: " << tokenGenerado << " (reenvio)" << endl;
            cout << "Mensaje asociado: " << mensaje << endl;
            cout << "Estado: Token reenviado" << endl;
        }
};

int main() {
    cout << "=== SISTEMA DE NOTIFICACIONES MULTICANAL ===" << endl;

    // se crean notificaciones para cada canal
    Correo correo("Su pedido ha sido enviado", "Igurow@gmail.com", "admin@empresa.com");
    SMS sms("Su codigo es 123456", "987654321", "999888777");
    Token token("Acceso autorizado", "usuario123", "supervisor");

    // se envian al destinatario
    cout << "\n--- Enviando notificaciones ---" << endl;
    correo.enviar();
    sms.enviar();
    token.enviar();

    // se envian al propietario
    cout << "\n--- Enviando al propietario ---" << endl;
    correo.enviarPropietario();
    sms.enviarPropietario();
    token.enviarPropietario();

    // se reenvian a otro destinatario
    cout << "\n--- Reenviando a otro destinatario ---" << endl;
    correo.reenviar("jefe@empresa.com");
    sms.reenviar("555666777");
    token.reenviar("usuario456");

    return 0;
}