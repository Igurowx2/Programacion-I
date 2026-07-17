#ifndef REGLACORRELACION_CPP
#define REGLACORRELACION_CPP

#include <string>

namespace Seguridad {

struct ReglaCorrelacion {
    std::string tipo;
    int umbral;
    int ventanaSegundos;
    std::string criticidad;
    ReglaCorrelacion() : umbral(0), ventanaSegundos(0) {}
    ReglaCorrelacion(const std::string& t, int u, int v, const std::string& c)
        : tipo(t), umbral(u), ventanaSegundos(v), criticidad(c) {}
};

} // namespace Seguridad

#endif