#ifndef INCIDENTE_CPP
#define INCIDENTE_CPP

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

namespace Seguridad {

extern int totalIncidentesAtendidos; // definida aquí mismo

class Analista; // forward

class Incidente {
    std::string idIncidente;
    std::vector<EventoLog*> eventosRelacionados;
    std::string descripcion;
    EstadoIncidente estado;
    NivelCriticidad nivel;
    Analista* responsable;
    static int contadorIDs;
    std::string generarID();
public:
    Incidente();
    Incidente(const std::string& desc, const std::vector<EventoLog*>& eventos);
    ~Incidente() = default;

    void agregarEvento(EventoLog* ev);
    void calcularNivelCriticidad();
    void cambiarEstado(EstadoIncidente nuevoEstado);
    const std::string& getId() const;
    const std::string& getDescripcion() const;
    EstadoIncidente getEstado() const;
    NivelCriticidad getNivel() const;
    const std::vector<EventoLog*>& getEventos() const;
    Analista* getResponsable() const;
    void setResponsable(Analista* a);
    void setNivel(NivelCriticidad n);

    friend std::ostream& operator<<(std::ostream& os, const Incidente& inc);
};

int Incidente::contadorIDs = 1000;

std::string Incidente::generarID() {
    std::ostringstream oss;
    oss << "INC-" << std::setw(5) << std::setfill('0') << contadorIDs++;
    return oss.str();
}

Incidente::Incidente() : estado(EstadoIncidente::NUEVO), nivel(NivelCriticidad::INFORMATIVO), responsable(nullptr) {
    idIncidente = generarID();
}

Incidente::Incidente(const std::string& desc, const std::vector<EventoLog*>& eventos)
    : eventosRelacionados(eventos), descripcion(desc), estado(EstadoIncidente::NUEVO),
      nivel(NivelCriticidad::INFORMATIVO), responsable(nullptr) {
    idIncidente = generarID();
    calcularNivelCriticidad();
}

void Incidente::agregarEvento(EventoLog* ev) {
    eventosRelacionados.push_back(ev);
    calcularNivelCriticidad();
}

void Incidente::calcularNivelCriticidad() {
    if (eventosRelacionados.empty()) return;
    NivelCriticidad maximo = NivelCriticidad::INFORMATIVO;
    for (auto* ev : eventosRelacionados) {
        if (ev->evaluarRiesgo() > maximo) maximo = ev->evaluarRiesgo();
    }
    nivel = maximo;
}

void Incidente::cambiarEstado(EstadoIncidente nuevoEstado) {
    estado = nuevoEstado;
    if (nuevoEstado == EstadoIncidente::RESUELTO) ++totalIncidentesAtendidos;
}

const std::string& Incidente::getId() const { return idIncidente; }
const std::string& Incidente::getDescripcion() const { return descripcion; }
EstadoIncidente Incidente::getEstado() const { return estado; }
NivelCriticidad Incidente::getNivel() const { return nivel; }
const std::vector<EventoLog*>& Incidente::getEventos() const { return eventosRelacionados; }
Analista* Incidente::getResponsable() const { return responsable; }
void Incidente::setResponsable(Analista* a) { responsable = a; }
void Incidente::setNivel(NivelCriticidad n) { nivel = n; }

std::ostream& operator<<(std::ostream& os, const Incidente& inc) {
    os << "\n========================================\n"
       << " INCIDENTE ID: " << inc.idIncidente << "\n"
       << " Descripción : " << inc.descripcion << "\n"
       << " Estado      : " << estadoIncidenteToString(inc.estado) << "\n"
       << " Criticidad  : " << nivelCriticidadToString(inc.nivel) << "\n"
       << " Eventos     : " << inc.eventosRelacionados.size() << "\n";
    for (size_t i = 0; i < inc.eventosRelacionados.size(); ++i) {
        os << "   " << (i+1) << ". [" << inc.eventosRelacionados[i]->getTipo() << "] "
           << inc.eventosRelacionados[i]->getTimestamp() << " IP:"
           << inc.eventosRelacionados[i]->getIpOrigen() << "\n";
    }
    os << " Analista    : ";
    if (inc.responsable) os << inc.responsable->getNombre() << " (ID:" << inc.responsable->getId() << ")";
    else os << "Sin asignar";
    os << "\n========================================\n";
    return os;
}

std::string operator+(const EventoFirewall& fw, const EventoAuth& auth) {
    std::ostringstream oss;
    oss << "Fusión: Firewall[" << fw.getTimestamp() << ", IP:" << fw.getIpOrigen()
        << ", Acción:" << fw.getAccion() << "] + Auth[" << auth.getTimestamp()
        << ", Usuario:" << auth.getUsuario() << ", Exito:" << (auth.isExito()?"Sí":"No") << "]";
    return oss.str();
}

} // namespace Seguridad

#endif