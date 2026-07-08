#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Evento {
    string nombre;
    string fecha;
    string hora;
};

int main() {
    vector<Evento> agenda;
    int opcion;

    do {
        cout << "\nAGENDA DE EVENTOS" << endl;
        cout << "1. Agregar evento" << endl;
        cout << "2. Mostrar eventos" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion: "; cin >> opcion;

        if (opcion == 1) {
            Evento e;
            cout << "Nombre: ";
            cin >> e.nombre;
            cout << "Fecha (dd/mm/aaaa): ";
            cin >> e.fecha;
            cout << "Hora (hh:mm): "; cin >> e.hora;
            agenda.push_back(e);
            cout << "Evento agregado" << endl;
        } else if (opcion == 2) {
            if (agenda.empty()) {
                cout << "No hay eventos" << endl;
            } else {
                for (size_t i = 0; i < agenda.size(); i++) {
                    cout << "Evento " << i+1 << ": " << agenda[i].nombre << " - " << agenda[i].fecha << " - " << agenda[i].hora << endl;
                }
            }
        }
    } while (opcion != 3);

    return 0;
}