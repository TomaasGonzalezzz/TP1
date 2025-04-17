#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include "../Headers/Efectos/EfectosSupport.hpp"
#include "../Headers/Efectos/EfectosDmg.hpp"

enum class Efecto {
    REGENERACION, //Me cura por X cant de turnos
    ASUSTADO, //El rival no puede atacar por X cant de turnos
    ENVENENADO,
    SANGRADO,
    REDUCCION_DE_DANO,
    AGOTADO, //Reduce resistencia y mana rival por X cant de turnos
    INMUNE, 
    ROBO_DE_MANA,
    ROBO_DE_HP, 
    NINGUNO,
    SOBRECARGA
};

enum class Rareza {
    COMUN,
    POCO_COMUN,
    RARO,
    EPICO,
    LEGENDARIO,
};

enum class Rango{
    NOVATO,
    INTERMEDIO,
    AVANZADO,
    EXPERTO,
    DIOS,
};

void propagarEfecto(Efecto efecto, shared_ptr<InterfazDePersonaje> personaje);

#endif