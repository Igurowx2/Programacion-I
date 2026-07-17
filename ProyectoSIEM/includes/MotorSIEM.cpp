#ifndef MOTORSIEM_CPP
#define MOTORSIEM_CPP

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>

namespace Seguridad {

int totalIncidentesAtendidos = 0;

class MotorSIEM {
    std::vector<EventoLog*> eventosCargados; // HEAP
    std::vector<ReglaCorrelacion> reglas;
    std::vector<Incidente> incidentes;
    std::vector<Analista> analistas;
    int matrizIncidentes[24][5];

    void inicializarMatriz() {
        for (int h = 0; h < 24; ++h)
            for (int c = 0; c < 5; ++c)
                matrizIncidentes[h][c] = 0;
    }

    bool esMismaHora(const std::string& ts1, const std::string& ts2, int ventanaSegundos) const {
        time_t t1 = parseTimestamp(ts1);
        time_t t2 = parseTimestamp(ts2);
        if (t1 == -1 || t2 == -1) return false;
        return std::abs(difftime(t1, t2)) <= ventanaSegundos;
    }

    void correlacionFuerzaBruta() {
        int umbral = 3, ventana = 120;
        for (const auto& r : reglas)
            if (r.tipo == "FUERZA_BRUTA") { umbral = r.umbral; ventana = r.ventanaSegundos; break; }
        for (size_t i = 0; i < eventosCargados.size(); ++i) {
            EventoAuth* authEv = dynamic_cast<EventoAuth*>(eventosCargados[i]);
            if (!authEv || authEv->isExito()) continue;
            std::string ip = authEv->getIpOrigen();
            std::vector<EventoLog*> grupo;
            grupo.push_back(authEv);
            for (size_t j = i+1; j < eventosCargados.size(); ++j) {
                EventoAuth* otro = dynamic_cast<EventoAuth*>(eventosCargados[j]);
                if (!otro || otro->isExito() || otro->getIpOrigen() != ip) continue;
                if (esMismaHora(authEv->getTimestamp(), otro->getTimestamp(), ventana))
                    grupo.push_back(otro);
            }
            if (static_cast<int>(grupo.size()) > umbral) {
                incidentes.emplace_back("Ataque de fuerza bruta desde IP " + ip, grupo);
                incidentes.back().setNivel(NivelCriticidad::ALTO);
                break;
            }
        }
    }

    void correlacionEscaneoPuertos() {
        int umbral = 5, ventana = 60;
        for (const auto& r : reglas)
            if (r.tipo == "ESCANEO_PUERTOS") { umbral = r.umbral; ventana = r.ventanaSegundos; break; }
        std::map<std::string, std::vector<EventoFirewall*>> porIP;
        for (auto* ev : eventosCargados) {
            EventoFirewall* fw = dynamic_cast<EventoFirewall*>(ev);
            if (fw && fw->getAccion() == "BLOQUEADO") porIP[fw->getIpOrigen()].push_back(fw);
        }
        for (auto& par : porIP) {
            auto& lista = par.second;
            if (static_cast<int>(lista.size()) < umbral) continue;
            std::sort(lista.begin(), lista.end(), [](EventoFirewall* a, EventoFirewall* b) {
                return a->getTimestamp() < b->getTimestamp();
            });
            for (size_t i = 0; i < lista.size(); ++i) {
                std::vector<EventoLog*> ventanaEventos;
                ventanaEventos.push_back(lista[i]);
                for (size_t j = i+1; j < lista.size(); ++j) {
                    if (esMismaHora(lista[i]->getTimestamp(), lista[j]->getTimestamp(), ventana))
                        ventanaEventos.push_back(lista[j]);
                }
                if (static_cast<int>(ventanaEventos.size()) > umbral) {
                    incidentes.emplace_back("Escaneo de puertos desde IP " + par.first, ventanaEventos);
                    incidentes.back().setNivel(NivelCriticidad::MEDIO);
                    break;
                }
            }
        }
    }

    void correlacionInfeccionActiva() {
        int ventana = 30;
        for (const auto& r : reglas)
            if (r.tipo == "INFECCION_ACTIVA") { ventana = r.ventanaSegundos; break; }
        for (auto* ev : eventosCargados) {
            EventoAntivirus* av = dynamic_cast<EventoAntivirus*>(ev);
            if (!av) continue;
            for (auto* fwEv : eventosCargados) {
                EventoFirewall* fw = dynamic_cast<EventoFirewall*>(fwEv);
                if (!fw) continue;
                if (fw->getIpOrigen() == av->getIpOrigen() &&
                    parseTimestamp(fw->getTimestamp()) > parseTimestamp(av->getTimestamp()) &&
                    esMismaHora(av->getTimestamp(), fw->getTimestamp(), ventana)) {
                    std::vector<EventoLog*> relacionados = {av, fw};
                    incidentes.emplace_back("Posible exfiltración de datos tras infección en IP " + av->getIpOrigen(), relacionados);
                    incidentes.back().setNivel(NivelCriticidad::CRITICO);
                    break;
                }
            }
        }
    }

public:
    MotorSIEM() { inicializarMatriz(); registrarAnalista("Alice Torres", 101); registrarAnalista("Bob García", 102); }
    ~MotorSIEM() { for (auto* ev : eventosCargados) delete ev; }

    void cargarLogsFirewall(const std::string& ruta) {
        std::ifstream archivo(ruta);
        if (!archivo) throw SIEMException::LogFormatoInvalidoException("No se pudo abrir " + ruta);
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            std::istringstream ss(linea);
            std::string tipo, ts, ipO, ipD, accion;
            int puerto;
            std::getline(ss, tipo, '|');
            if (tipo != "FIREWALL") continue;
            std::getline(ss, ts, '|');
            std::getline(ss, ipO, '|');
            std::getline(ss, ipD, '|');
            ss >> puerto;
            ss.ignore(1, '|');
            std::getline(ss, accion);
            eventosCargados.push_back(new EventoFirewall(ts, ipO, ipD, puerto, accion));
        }
        std::cout << "Logs de Firewall cargados.\n";
    }

    void cargarLogsAuth(const std::string& ruta) {
        std::ifstream archivo(ruta);
        if (!archivo) throw SIEMException::LogFormatoInvalidoException("No se pudo abrir " + ruta);
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            std::istringstream ss(linea);
            std::string tipo, ts, ipO, ipD, usuario, estado;
            std::getline(ss, tipo, '|');
            if (tipo != "AUTH") continue;
            std::getline(ss, ts, '|');
            std::getline(ss, ipO, '|');
            std::getline(ss, ipD, '|');
            std::getline(ss, usuario, '|');
            std::getline(ss, estado);
            bool exito = (estado == "EXITOSO");
            eventosCargados.push_back(new EventoAuth(ts, ipO, ipD, usuario, exito));
        }
    }

    void cargarLogsAntivirus(const std::string& ruta) {
        std::ifstream archivo(ruta);
        if (!archivo) throw SIEMException::LogFormatoInvalidoException("No se pudo abrir " + ruta);
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            std::istringstream ss(linea);
            std::string tipo, ts, ipO, archivo, hash, nombre;
            std::getline(ss, tipo, '|');
            if (tipo != "ANTIVIRUS") continue;
            std::getline(ss, ts, '|');
            std::getline(ss, ipO, '|');
            std::getline(ss, archivo, '|');
            std::getline(ss, hash, '|');
            std::getline(ss, nombre);
            eventosCargados.push_back(new EventoAntivirus(ts, ipO, archivo, hash, nombre));
        }
    }

    void cargarReglas(const std::string& ruta) {
        std::ifstream archivo(ruta);
        if (!archivo) throw SIEMException::ReglaInvalidaException("No se pudo abrir " + ruta);
        std::string linea;
        while (std::getline(archivo, linea)) {
            if (linea.empty()) continue;
            std::istringstream ss(linea);
            std::string tipo, umbralStr, ventanaStr, crit;
            std::getline(ss, tipo, ',');
            std::getline(ss, umbralStr, ',');
            std::getline(ss, ventanaStr, ',');
            std::getline(ss, crit);
            reglas.emplace_back(tipo, std::stoi(umbralStr), std::stoi(ventanaStr), crit);
        }
    }

    void ejecutarCorrelacion() {
        incidentes.clear();
        inicializarMatriz();
        correlacionFuerzaBruta();
        correlacionEscaneoPuertos();
        correlacionInfeccionActiva();
        for (const auto& inc : incidentes) {
            if (!inc.getEventos().empty()) {
                std::string ts = inc.getEventos()[0]->getTimestamp();
                int hora = std::stoi(ts.substr(11,2));
                int idxCrit = static_cast<int>(inc.getNivel());
                if (hora >= 0 && hora < 24 && idxCrit >= 0 && idxCrit < 5)
                    matrizIncidentes[hora][idxCrit]++;
            }
        }
        std::cout << "Correlación completada. Incidentes: " << incidentes.size() << "\n";
    }

    void mostrarIncidentes() const { for (const auto& inc : incidentes) std::cout << inc; }
    Incidente* buscarIncidentePorID(const std::string& id) {
        for (auto& inc : incidentes) if (inc.getId() == id) return &inc;
        throw SIEMException::EventoNoEncontradoException("Incidente ID " + id);
    }

    void cambiarEstadoIncidente(const std::string& id, EstadoIncidente nuevoEstado) {
        buscarIncidentePorID(id)->cambiarEstado(nuevoEstado);
    }

    void asignarAnalistaAIncidente(const std::string& idIncidente, int idAnalista) {
        Incidente* inc = buscarIncidentePorID(idIncidente);
        Analista* analista = obtenerAnalista(idAnalista);
        if (!analista) throw std::runtime_error("Analista no encontrado");
        inc->setResponsable(analista);
    }

    void filtrarIncidentesPorEstado(EstadoIncidente estado) const {
        for (const auto& inc : incidentes)
            if (inc.getEstado() == estado) std::cout << inc;
    }

    void buscarIncidentesPorIP(const std::string& ip) const {
        for (const auto& inc : incidentes)
            for (const auto* ev : inc.getEventos())
                if (ev->getIpOrigen() == ip || ev->getIpDestino() == ip) { std::cout << inc; break; }
    }

    void mostrarEstadisticas() const {
        std::cout << "\n=== MATRIZ DE INCIDENTES POR HORA Y CRITICIDAD ===\n";
        std::cout << "Hora\\Crit | INF | BAJ | MED | ALT | CRI\n";
        for (int h = 0; h < 24; ++h) {
            std::cout << std::setw(2) << h << ":00    | ";
            for (int c = 0; c < 5; ++c) std::cout << std::setw(3) << matrizIncidentes[h][c] << " ";
            std::cout << "\n";
        }
        int fw = 0, auth = 0, av = 0;
        for (auto* ev : eventosCargados) {
            if (ev->getTipo() == "FIREWALL") fw++;
            else if (ev->getTipo() == "AUTH") auth++;
            else if (ev->getTipo() == "ANTIVIRUS") av++;
        }
        std::cout << "\nEventos: Firewall=" << fw << " Auth=" << auth << " Antivirus=" << av << "\n";
        std::cout << "Incidentes atendidos (RESUELTOS): " << totalIncidentesAtendidos << "\n";
    }

    void listarEventosConAritmetica() const {
        std::cout << "\nEventos (aritmética de punteros):\n";
        if (eventosCargados.empty()) return;
        EventoLog* const* datos = eventosCargados.data();
        for (size_t i = 0; i < eventosCargados.size(); ++i)
            (*(datos + i))->mostrar();
    }

    void generarReporte(const std::string& ruta) const {
        std::ofstream archivo(ruta);
        archivo << "REPORTE DE INCIDENTES - SIEM Lite\n";
        for (const auto& inc : incidentes) {
            archivo << inc.getId() << " | " << inc.getDescripcion() << "\n";
        }
    }

    void guardarIncidentes(const std::string& ruta) const {
        std::ofstream archivo(ruta);
        for (const auto& inc : incidentes) {
            archivo << inc.getId() << "|" << inc.getDescripcion() << "|"
                    << static_cast<int>(inc.getEstado()) << "|"
                    << static_cast<int>(inc.getNivel()) << "\n";
        }
    }

    void cargarIncidentes(const std::string& ruta) {
        std::ifstream archivo(ruta);
        incidentes.clear();
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream ss(linea);
            std::string id, desc, estStr, nivStr;
            std::getline(ss, id, '|');
            std::getline(ss, desc, '|');
            std::getline(ss, estStr, '|');
            std::getline(ss, nivStr);
            Incidente inc(desc, {});
            inc.cambiarEstado(static_cast<EstadoIncidente>(std::stoi(estStr)));
            inc.setNivel(static_cast<NivelCriticidad>(std::stoi(nivStr)));
            incidentes.push_back(inc);
        }
    }

    void registrarAnalista(const std::string& nombre, int id) { analistas.emplace_back(nombre, id); }
    Analista* obtenerAnalista(int id) {
        for (auto& a : analistas) if (a.getId() == id) return &a;
        return nullptr;
    }
};

} // namespace Seguridad

#endif