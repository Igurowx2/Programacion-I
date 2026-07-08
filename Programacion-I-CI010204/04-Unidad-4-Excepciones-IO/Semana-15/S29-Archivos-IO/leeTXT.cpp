#include <iostream>
#include <fstream>
#include <exception>
using namespace std;

// excepcion para archivo no encontrado
class ArchivoNoEncontrado : public exception {
public:
    const char* what() const noexcept override {
        return "Error: el archivo no existe o no se puede abrir";
    }
};

void leerArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        throw ArchivoNoEncontrado();
    }

    string linea;
    cout << "Contenido del archivo:" << endl;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

int main() {
    string nombreArchivo;
    cout << "Ingrese el nombre del archivo .txt: "; cin >> nombreArchivo;

    try {
        leerArchivo(nombreArchivo);
    } catch (const ArchivoNoEncontrado& e) {
        cout << e.what() << endl;
    }

    return 0;
}