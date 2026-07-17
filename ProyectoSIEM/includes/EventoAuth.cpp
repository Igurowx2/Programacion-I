#ifndef EVENTOAUTH_CPP
#define EVENTOAUTH_CPP

#include <string>
#include <iostream>

namespace Seguridad {

class EventoAuth : public EventoLog {
    std::string usuario;
    bool exito;
public:
    EventoAuth(const std::string& ts, const std::string& ipO, const std::string& ipD,
               const std::string& usuario, bool exito);
    void mostrar() const override;
    NivelCriticidad evaluarRiesgo() const override;
    std::string getTipo() const override;
    const std::string& getUsuario() const;
    bool isExito() const;
};

EventoAuth::EventoAuth(const std::string& ts, const std::string& ipO, const std::string& ipD,
                       const std::string& usuario, bool exito)
    : EventoLog(ts, ipO, ipD), usuario(usuario), exito(exito) {
    setNivel(evaluarRiesgo());
}

void EventoAuth::mostrar() const {
    std::cout << "[AUTH] " << getTimestamp() << " | IP: " << getIpOrigen()
              << " -> Servidor: " << getIpDestino() << " | Usuario: " << usuario
              << " | " << (exito ? "EXITOSO" : "FALLIDO")
              << " | Criticidad: " << nivelCriticidadToString(getNivel()) << std::endl;
}

NivelCriticidad EventoAuth::evaluarRiesgo() const {
    return exito ? NivelCriticidad::INFORMATIVO : NivelCriticidad::ALTO;
}

std::string EventoAuth::getTipo() const { return "AUTH"; }
const std::string& EventoAuth::getUsuario() const { return usuario; }
bool EventoAuth::isExito() const { return exito; }

} // namespace Seguridad

#endif