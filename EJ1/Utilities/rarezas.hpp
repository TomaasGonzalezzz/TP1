#ifndef RAREZA_UTILS_HPP
#define RAREZA_UTILS_HPP

#include "../Headers/Armas/InterfazArma.hpp"
#include "utilities.hpp"

class Rarezas {
public:
    static float getMultiplicadorRareza(Rareza rareza) {
        switch (rareza) {
            case Rareza::COMUN: return 1.0;
            case Rareza::POCO_COMUN: return 1.2;
            case Rareza::RARO: return 1.3;
            case Rareza::EPICO: return 1.5;
            case Rareza::LEGENDARIO: return 1.8;
            default: return 0;
        }
    }
    static string getNombreRareza(Rareza rareza) {
        switch (rareza) {
            case Rareza::COMUN: return "Comun";
            case Rareza::POCO_COMUN: return "Poco Comun";
            case Rareza::RARO: return "Raro";
            case Rareza::EPICO: return "Epic";
            case Rareza::LEGENDARIO: return "Legendario";
            default: return "";
        }
    }
};

#endif