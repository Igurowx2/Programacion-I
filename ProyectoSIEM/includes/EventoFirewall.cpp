#ifndef EVENTOFIREWALL_CPP
#define EVENTOFIREWALL_CPP

#include <string>
#include <iostream>

namespace Seguridad {

class EventoFirewall : public EventoLog {
    int puerto;
    std::string accion;
public:
    EventoFirewall(const std::string& ts, const std::string& ipO, const std::string& ipD,
                   int puerto, const std::string& accion);
    void mostrar() const override;
    NivelCriticidad evaluarRiesgo() const override;
    std::string getTipo() const override;
    int getPuerto() const;
    const std::string& getAccion() const;
};

EventoFirewall::EventoFirewall(const std::string& ts, const std::string& ipO, const std::string& ipD,
                               int puerto, const std::string& accion)
    : EventoLog(ts, ipO, ipD), puerto(puerto), accion(accion) {
    setNivel(evaluarRiesgo());
}

void EventoFirewall::mostrar() const {
    std::cout << "[FIREWALL] " << getTimestamp() << " | Origen: " << getIpOrigen()
              << " -> Destino: " << getIpDestino() << ":" << puerto
              << " | Acción: " << accion << " | Criticidad: "
              << nivelCriticidadToString(getNivel()) << std::endl;
}

NivelCriticidad EventoFirewall::evaluarRiesgo() const {
    if (accion == "BLOQUEADO") return NivelCriticidad::BAJO;
    if (accion == "ALERTAR") return NivelCriticidad::MEDIO;
    return NivelCriticidad::INFORMATIVO;
}

std::string EventoFirewall::getTipo() const { return "FIREWALL"; }
int EventoFirewall::getPuerto() const { return puerto; }
const std::string& EventoFirewall::getAccion() const { return accion; }

} // namespace Seguridad

#endif