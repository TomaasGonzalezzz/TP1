#ifndef RANGOS_UTILS_HPP
#define RANGOS_UTILS_HPP

#include "../Headers/Armas/InterfazArma.hpp"

class Rangos {
    public:
    static float getMultiplicadorRangos(Rango rango) {
        switch (rango) {
            case Rango::NOVATO: return 1.0;
            case Rango::INTERMEDIO: return 1.2;
            case Rango::AVANZADO: return 1.3;
            case Rango::EXPERTO: return 1.5;
            case Rango::DIOS: return 1.8;
            default: return 0;
        }
    }
    static string getNombreRango(Rango rango) {
        switch (rango) {
            case Rango::NOVATO: return "Novato";
            case Rango::INTERMEDIO: return "Intermedio";
            case Rango::AVANZADO: return "Avanzado";
            case Rango::EXPERTO: return "Experto";
            case Rango::DIOS: return "Dios";
            default: return "Desconocido";
        }
    }
};

#endif