#include <iostream>
#include <fstream>
#include <string>
#include "Persona.cpp"
#include "Curso.cpp"
using namespace std;

void pausa() {
    cout << "\nPresione ENTER para volver al menu...";
    cin.ignore();
    cin.get();
}

void guardarTodoEnUnArchivo(Persona docentes[], int cantDocentes, Persona alumnos[], int cantAlumnos, Curso cursos[], int cantCursos) {
    ofstream archivo("datos.txt");
    archivo << "===== DOCENTES =====\n";
    for (int i = 0; i < cantDocentes; i++) {
        archivo << "DNI: " << docentes[i].getDni() << "\n";
        archivo << "Nombre: " << docentes[i].getNombre() << "\n";
        archivo << "Tipo: " << docentes[i].getTipo() << "\n";
        archivo << "--------------------\n";
    }
    archivo << "\n===== ALUMNOS =====\n";
    for (int i = 0; i < cantAlumnos; i++) {
        archivo << "DNI: " << alumnos[i].getDni() << "\n";
        archivo << "Nombre: " << alumnos[i].getNombre() << "\n";
        archivo << "Tipo: " << alumnos[i].getTipo() << "\n";
        archivo << "--------------------\n";
    }
    archivo << "\n===== CURSOS =====\n";
    for (int i = 0; i < cantCursos; i++) {
        archivo << "Codigo: " << cursos[i].getCodigo() << "\n";
        archivo << "Nombre del curso: " << cursos[i].getNombreCurso() << "\n";
        archivo << "DNI docente: " << cursos[i].getDniDocente() << "\n";
        archivo << "Cantidad de alumnos: " << cursos[i].getCantidadAlumnos() << "\n";
        archivo << "--------------------\n";
    }
    archivo.close();
    cout << "\n>> Datos guardados exitosamente en 'datos.txt'.\n";
    pausa();
}

void mostrarDocentes(Persona docentes[], int cantDocentes) {
    cout << "\n--- DOCENTES REGISTRADOS ---\n";
    if (cantDocentes == 0)
        cout << "No hay docentes registrados.\n";
    else
        for (int i = 0; i < cantDocentes; i++) {
            cout << "\nDocente #" << i + 1 << "\n";
            docentes[i].mostrar();
        }
    pausa();
}

void mostrarAlumnos(Persona alumnos[], int cantAlumnos) {
    cout << "\n--- ALUMNOS REGISTRADOS ---\n";
    if (cantAlumnos == 0)
        cout << "No hay alumnos registrados.\n";
    else
        for (int i = 0; i < cantAlumnos; i++) {
            cout << "\nAlumno #" << i + 1 << "\n";
            alumnos[i].mostrar();
        }
    pausa();
}

void mostrarCursos(Curso cursos[], int cantCursos) {
    cout << "\n--- CURSOS REGISTRADOS ---\n";
    if (cantCursos == 0)
        cout << "No hay cursos registrados.\n";
    else
        for (int i = 0; i < cantCursos; i++) {
            cout << "\nCurso #" << i + 1 << "\n";
            cursos[i].mostrar();
        }
    pausa();
}

int main() {
    Persona docentes[5];
    Persona alumnos[5];
    Curso cursos[5];
    int cantDocentes = 0, cantAlumnos = 0, cantCursos = 0;
    int opcion;

    do {
        cout << "\n===================================\n";
        cout << "       GESTION ACADEMICA v1.0\n";
        cout << "===================================\n";
        cout << "[1] Registrar docente\n";
        cout << "[2] Registrar alumno\n";
        cout << "[3] Registrar curso\n";
        cout << "[4] Mostrar docentes\n";
        cout << "[5] Mostrar alumnos\n";
        cout << "[6] Mostrar cursos\n";
        cout << "[7] Guardar todo en archivo TXT\n";
        cout << "[8] Salir\n";
        cout << "-----------------------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            if (cantDocentes < 5) {
                string dni, nombre;
                cout << "\n>> REGISTRO DE DOCENTE\nDNI: ";
                cin >> dni; cin.ignore();
                cout << "Nombre completo: ";
                getline(cin, nombre);
                if (dni == "" || nombre == "")
                    cout << "Error: campos incompletos.\n";
                else {
                    docentes[cantDocentes].setDni(dni);
                    docentes[cantDocentes].setNombre(nombre);
                    docentes[cantDocentes].setTipo("Docente");
                    cantDocentes++;
                    cout << "Docente registrado correctamente.\n";
                }
            } else
                cout << "Limite de 5 docentes alcanzado.\n";
            pausa();
            break;
        }
        case 2: {
            if (cantAlumnos < 5) {
                string dni, nombre;
                cout << "\n>> REGISTRO DE ALUMNO\nDNI: ";
                cin >> dni; cin.ignore();
                cout << "Nombre completo: ";
                getline(cin, nombre);
                if (dni == "" || nombre == "")
                    cout << "Error: campos incompletos.\n";
                else {
                    alumnos[cantAlumnos].setDni(dni);
                    alumnos[cantAlumnos].setNombre(nombre);
                    alumnos[cantAlumnos].setTipo("Alumno");
                    cantAlumnos++;
                    cout << "Alumno registrado correctamente.\n";
                }
            } else
                cout << "Limite de 5 alumnos alcanzado.\n";
            pausa();
            break;
        }
        case 3: {
            if (cantCursos < 5) {
                string codigo, nombreCurso, dniDocente;
                int cant;
                cout << "\n>> REGISTRO DE CURSO\nCodigo del curso: ";
                cin >> codigo; cin.ignore();
                cout << "Nombre del curso: ";
                getline(cin, nombreCurso);
                cout << "DNI del docente: ";
                cin >> dniDocente;
                cout << "Cantidad de alumnos: ";
                cin >> cant;
                if (codigo == "" || nombreCurso == "" || dniDocente == "" || cant < 0)
                    cout << "Error: datos incorrectos.\n";
                else {
                    cursos[cantCursos].setCodigo(codigo);
                    cursos[cantCursos].setNombreCurso(nombreCurso);
                    cursos[cantCursos].setDniDocente(dniDocente);
                    cursos[cantCursos].setCantidadAlumnos(cant);
                    cantCursos++;
                    cout << "Curso registrado correctamente.\n";
                }
            } else
                cout << "Limite de 5 cursos alcanzado.\n";
            pausa();
            break;
        }
        case 4: mostrarDocentes(docentes, cantDocentes); break;
        case 5: mostrarAlumnos(alumnos, cantAlumnos); break;
        case 6: mostrarCursos(cursos, cantCursos); break;
        case 7: guardarTodoEnUnArchivo(docentes, cantDocentes, alumnos, cantAlumnos, cursos, cantCursos); break;
        case 8: cout << "\nSaliendo del sistema. Hasta pronto.\n"; break;
        default: cout << "\nOpcion no valida. Intente nuevamente.\n"; pausa(); break;
        }
    } while (opcion != 8);

    return 0;
}