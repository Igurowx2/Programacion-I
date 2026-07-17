#ifndef EVENTOLOG_CPP
#define EVENTOLOG_CPP

#include <string>
#include <iostream>

namespace Seguridad {

// Forward declaration de enums (ya definidos en Utils.cpp)
enum class NivelCriticidad : int;
std::string nivelCriticidadToString(NivelCriticidad n);

class EventoLog {
private:
    std::string timestamp;
    std::string ipOrigen;
    std::string ipDestino;
protected:
    NivelCriticidad nivel;
public:
    EventoLog(const std::string& ts, const std::string& ipO, const std::string& ipD);
    virtual ~EventoLog() {}

    const std::string& getTimestamp() const;
    const std::string& getIpOrigen() const;
    const std::string& getIpDestino() const;
    NivelCriticidad getNivel() const;
    void setNivel(NivelCriticidad n);

    virtual void mostrar() const = 0;
    virtual bool esCorrelacionable(const EventoLog& otro) const;
    virtual NivelCriticidad evaluarRiesgo() const = 0;
    virtual std::string getTipo() const = 0;

    bool operator==(const EventoLog& otro) const;
};

// Implementaciones
EventoLog::EventoLog(const std::string& ts, const std::string& ipO, const std::string& ipD)
    : timestamp(ts), ipOrigen(ipO), ipDestino(ipD), nivel(NivelCriticidad::INFORMATIVO) {}

const std::string& EventoLog::getTimestamp() const { return timestamp; }
const std::string& EventoLog::getIpOrigen() const { return ipOrigen; }
const std::string& EventoLog::getIpDestino() const { return ipDestino; }
NivelCriticidad EventoLog::getNivel() const { return nivel; }
void EventoLog::setNivel(NivelCriticidad n) { nivel = n; }

bool EventoLog::esCorrelacionable(const EventoLog& otro) const {
    return ipOrigen == otro.ipOrigen;
}

bool EventoLog::operator==(const EventoLog& otro) const {
    return ipOrigen == otro.ipOrigen;
}

} // namespace Seguridad

#endif