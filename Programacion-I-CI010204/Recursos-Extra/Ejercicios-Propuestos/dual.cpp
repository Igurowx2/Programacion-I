#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
    queue<string> cola1;
    queue<string> cola2;
    stack<string> historial;

    // clientes de ejemplo
    cola1.push("Ana");
    cola1.push("Carlos");
    cola1.push("Maria");
    cola1.push("Luis");
    cola1.push("Elena");
    cola2.push("Pedro");
    cola2.push("Juan");
    cola2.push("Sofia");

    int atendidosCola1 = 0;
    int atendidosCola2 = 0;

    while (!cola1.empty() || !cola2.empty()) {
        // se atiende de cola1 si hay y no se han atendido 3
        if (!cola1.empty() && atendidosCola1 < 3) {
            string cliente = cola1.front();
            cola1.pop();
            atendidosCola1++;
            cout << "Atendido de cola1: " << cliente << endl;
            historial.push("Atendido " + cliente + " (cola1)");
        }
        // se atiende de cola2 si hay y no se han atendido 2
        else if (!cola2.empty() && atendidosCola2 < 2) {
            string cliente = cola2.front();
            cola2.pop();
            atendidosCola2++;
            cout << "Atendido de cola2: " << cliente << endl;
            historial.push("Atendido " + cliente + " (cola2)");
        }
        // si se llego a 3 de cola1, se reinicia
        else if (atendidosCola1 == 3) {
            atendidosCola1 = 0;
        }
        // si se llego a 2 de cola2, se reinicia
        else if (atendidosCola2 == 2) {
            atendidosCola2 = 0;
        }
        // si no hay mas clientes, se sale
        else {
            break;
        }
    }

    cout << "\nHistorial de atenciones:" << endl;
    while (!historial.empty()) {
        cout << historial.top() << endl;
        historial.pop();
    }

    return 0;
}