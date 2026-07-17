#ifndef EXCEPCIONESSIEM_CPP
#define EXCEPCIONESSIEM_CPP

#include <string>
#include <exception>

namespace Seguridad {
namespace SIEMException {

class LogFormatoInvalidoException : public std::exception {
    std::string mensaje;
public:
    explicit LogFormatoInvalidoException(const std::string& linea)
        : mensaje("Formato de log inválido: " + linea) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class EventoNoEncontradoException : public std::exception {
    std::string mensaje;
public:
    explicit EventoNoEncontradoException(const std::string& detalle)
        : mensaje("Evento no encontrado: " + detalle) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class ReglaInvalidaException : public std::exception {
    std::string mensaje;
public:
    explicit ReglaInvalidaException(const std::string& detalle)
        : mensaje("Regla inválida: " + detalle) {}
    const char* what() const noexcept override { return mensaje.c_str(); }
};

class IncidenteSinEventosException : public std::exception {
public:
    const char* what() const noexcept override {
        return "El incidente no contiene eventos relacionados.";
    }
};

} // namespace SIEMException
} // namespace Seguridad

#endif