#ifndef ANALISTA_CPP
#define ANALISTA_CPP

#include <string>

namespace Seguridad {

class Analista {
    std::string nombre;
    int id;
public:
    Analista(const std::string& nombre, int id) : nombre(nombre), id(id) {}
    const std::string& getNombre() const { return nombre; }
    int getId() const { return id; }
};

} // namespace Seguridad

#endif