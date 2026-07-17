#ifndef EVENTOANTIVIRUS_CPP
#define EVENTOANTIVIRUS_CPP

#include <string>
#include <iostream>

namespace Seguridad {

class EventoAntivirus : public EventoLog {
    std::string archivoAfectado;
    std::string hashMalware;
    std::string nombreMalware;
public:
    EventoAntivirus(const std::string& ts, const std::string& ipO,
                    const std::string& archivo, const std::string& hash,
                    const std::string& nombre);
    void mostrar() const override;
    NivelCriticidad evaluarRiesgo() const override;
    std::string getTipo() const override;
    const std::string& getArchivoAfectado() const;
    const std::string& getHashMalware() const;
    const std::string& getNombreMalware() const;
};

EventoAntivirus::EventoAntivirus(const std::string& ts, const std::string& ipO,
                                 const std::string& archivo, const std::string& hash,
                                 const std::string& nombre)
    : EventoLog(ts, ipO, "N/A"), archivoAfectado(archivo), hashMalware(hash), nombreMalware(nombre) {
    setNivel(evaluarRiesgo());
}

void EventoAntivirus::mostrar() const {
    std::cout << "[ANTIVIRUS] " << getTimestamp() << " | IP: " << getIpOrigen()
              << " | Archivo: " << archivoAfectado << " | Malware: " << nombreMalware
              << " (" << hashMalware << ") | Criticidad: "
              << nivelCriticidadToString(getNivel()) << std::endl;
}

NivelCriticidad EventoAntivirus::evaluarRiesgo() const {
    return NivelCriticidad::CRITICO;
}

std::string EventoAntivirus::getTipo() const { return "ANTIVIRUS"; }
const std::string& EventoAntivirus::getArchivoAfectado() const { return archivoAfectado; }
const std::string& EventoAntivirus::getHashMalware() const { return hashMalware; }
const std::string& EventoAntivirus::getNombreMalware() const { return nombreMalware; }

} // namespace Seguridad

#endif