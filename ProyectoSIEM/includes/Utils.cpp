#ifndef UTILS_CPP
#define UTILS_CPP

#include <string>
#include <ctime>
#include <cstdio>

namespace Seguridad {

enum class NivelCriticidad { INFORMATIVO, BAJO, MEDIO, ALTO, CRITICO };
enum class EstadoIncidente { NUEVO, INVESTIGACION, RESUELTO, FALSO_POSITIVO };
enum class TipoLog { FIREWALL, AUTH, ANTIVIRUS };

std::string nivelCriticidadToString(NivelCriticidad n) {
    switch (n) {
        case NivelCriticidad::INFORMATIVO: return "INFORMATIVO";
        case NivelCriticidad::BAJO: return "BAJO";
        case NivelCriticidad::MEDIO: return "MEDIO";
        case NivelCriticidad::ALTO: return "ALTO";
        case NivelCriticidad::CRITICO: return "CRITICO";
    }
    return "DESCONOCIDO";
}

std::string estadoIncidenteToString(EstadoIncidente e) {
    switch (e) {
        case EstadoIncidente::NUEVO: return "NUEVO";
        case EstadoIncidente::INVESTIGACION: return "INVESTIGACION";
        case EstadoIncidente::RESUELTO: return "RESUELTO";
        case EstadoIncidente::FALSO_POSITIVO: return "FALSO_POSITIVO";
    }
    return "?";
}

std::string tipoLogToString(TipoLog t) {
    switch (t) {
        case TipoLog::FIREWALL: return "FIREWALL";
        case TipoLog::AUTH: return "AUTH";
        case TipoLog::ANTIVIRUS: return "ANTIVIRUS";
    }
    return "";
}

NivelCriticidad stringToNivelCriticidad(const std::string& s) {
    if (s == "INFORMATIVO") return NivelCriticidad::INFORMATIVO;
    if (s == "BAJO") return NivelCriticidad::BAJO;
    if (s == "MEDIO") return NivelCriticidad::MEDIO;
    if (s == "ALTO") return NivelCriticidad::ALTO;
    if (s == "CRITICO") return NivelCriticidad::CRITICO;
    return NivelCriticidad::INFORMATIVO;
}

time_t parseTimestamp(const std::string& ts) {
    int y, m, d, h, min, s;
    if (sscanf(ts.c_str(), "%d-%d-%d %d:%d:%d", &y, &m, &d, &h, &min, &s) != 6)
        return -1;
    struct tm tm = {};
    tm.tm_year = y - 1900;
    tm.tm_mon = m - 1;
    tm.tm_mday = d;
    tm.tm_hour = h;
    tm.tm_min = min;
    tm.tm_sec = s;
    tm.tm_isdst = -1;
    return mktime(&tm);
}

} // namespace Seguridad

#endif