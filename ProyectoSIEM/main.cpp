// ============================================================
// PROYECTO SIEM Lite - Sistema de Correlación de Logs
// main.cpp - Incluye todos los módulos .cpp (sin headers)
// ============================================================
#include <iostream>
#include <string>

// Inclusión de todos los módulos (archivos .cpp con include guards)
#include "includes/ExcepcionesSIEM.cpp"
#include "includes/Utils.cpp"
#include "includes/EventoLog.cpp"
#include "includes/EventoFirewall.cpp"
#include "includes/EventoAuth.cpp"
#include "includes/EventoAntivirus.cpp"
#include "includes/ReglaCorrelacion.cpp"
#include "includes/Analista.cpp"
#include "includes/Incidente.cpp"
#include "includes/MotorSIEM.cpp"

using namespace Seguridad;

int main() {
    MotorSIEM motor;  // Variable en STACK
    int opcion;
    bool logsCargados = false;

    do {
        std::cout << "\n============================================\n";
        std::cout << "==  SISTEMA SIEM LITE - CORRELACIÓN DE LOGS ==\n";
        std::cout << "============================================\n";
        std::cout << "1. Cargar archivos de logs (Firewall, Auth, Antivirus)\n";
        std::cout << "2. Cargar reglas de correlación\n";
        std::cout << "3. Ejecutar motor de correlación\n";
        std::cout << "4. Ver todos los incidentes generados\n";
        std::cout << "5. Buscar incidentes por IP\n";
        std::cout << "6. Filtrar incidentes por estado\n";
        std::cout << "7. Asignar un analista a un incidente\n";
        std::cout << "8. Cambiar estado de un incidente\n";
        std::cout << "9. Ver estadísticas (matriz [24][5] y contadores)\n";
        std::cout << "10. Generar reporte de incidentes\n";
        std::cout << "11. Guardar incidentes en archivo\n";
        std::cout << "12. Cargar incidentes desde archivo\n";
        std::cout << "13. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        std::cin.ignore(); // limpiar buffer

        try {
            switch (opcion) {
                case 1: {
                    try {
                        motor.cargarLogsFirewall("data/logs_firewall.txt");
                        motor.cargarLogsAuth("data/logs_auth.txt");
                        motor.cargarLogsAntivirus("data/logs_antivirus.txt");
                        logsCargados = true;
                    } catch (const SIEMException::LogFormatoInvalidoException& e) {
                        std::cerr << "Error al cargar logs: " << e.what() << "\n";
                    }
                    break;
                }
                case 2:
                    motor.cargarReglas("data/reglas.txt");
                    break;
                case 3:
                    if (!logsCargados) {
                        std::cout << "Primero cargue los logs (opción 1).\n";
                        break;
                    }
                    motor.ejecutarCorrelacion();
                    break;
                case 4:
                    motor.mostrarIncidentes();
                    break;
                case 5: {
                    std::string ip;
                    std::cout << "IP a buscar: ";
                    std::getline(std::cin, ip);
                    motor.buscarIncidentesPorIP(ip);
                    break;
                }
                case 6: {
                    int est;
                    std::cout << "Filtrar por estado (0=NUEVO, 1=INVESTIGACION, 2=RESUELTO, 3=FALSO_POSITIVO): ";
                    std::cin >> est;
                    std::cin.ignore();
                    if (est < 0 || est > 3) { std::cout << "Valor inválido.\n"; break; }
                    motor.filtrarIncidentesPorEstado(static_cast<EstadoIncidente>(est));
                    break;
                }
                case 7: {
                    std::string idInc;
                    int idAnalista;
                    std::cout << "ID del incidente: ";
                    std::getline(std::cin, idInc);
                    std::cout << "ID del analista (101=Alice, 102=Bob): ";
                    std::cin >> idAnalista;
                    std::cin.ignore();
                    motor.asignarAnalistaAIncidente(idInc, idAnalista);
                    break;
                }
                case 8: {
                    std::string idInc;
                    int nuevo;
                    std::cout << "ID del incidente: ";
                    std::getline(std::cin, idInc);
                    std::cout << "Nuevo estado (0=NUEVO,1=INVESTIGACION,2=RESUELTO,3=FALSO_POSITIVO): ";
                    std::cin >> nuevo;
                    std::cin.ignore();
                    if (nuevo < 0 || nuevo > 3) { std::cout << "Inválido.\n"; break; }
                    motor.cambiarEstadoIncidente(idInc, static_cast<EstadoIncidente>(nuevo));
                    break;
                }
                case 9: {
                    motor.mostrarEstadisticas();
                    motor.listarEventosConAritmetica();
                    break;
                }
                case 10:
                    motor.generarReporte("data/reporte_incidentes.txt");
                    break;
                case 11:
                    motor.guardarIncidentes("data/incidentes_guardados.txt");
                    break;
                case 12:
                    motor.cargarIncidentes("data/incidentes_guardados.txt");
                    break;
                case 13:
                    std::cout << "Saliendo...\n";
                    break;
                default:
                    std::cout << "Opción no válida.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Excepción capturada: " << e.what() << "\n";
        }
    } while (opcion != 13);

    return 0;
}

// URL del repositorio (placeholder)
// https://github.com/Igurowx2/Programacion-I/tree/main/ProyectoSIEM