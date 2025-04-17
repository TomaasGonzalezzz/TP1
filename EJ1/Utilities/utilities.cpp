#include "../Utilities/utilities.hpp"
#include "../Headers/Personajes/InterfazPersonajes.hpp"
#include "../Headers/Efectos/EfectosSupport.hpp"
#include "../Headers/Efectos/EfectosDmg.hpp"

void propagarEfecto(Efecto efecto, shared_ptr<InterfazDePersonaje> personaje) {
    switch (efecto) {
        case Efecto::REGENERACION:
            personaje->curarVida(Regeneracion::getCantidad());
            break;
        case Efecto::ENVENENADO:
            personaje->recibirDmg(Envenenar::getCantidad());
            break;
        case Efecto::SANGRADO:
            personaje->recibirDmg(personaje->getVida() * Sangrado::getPorcentaje() / 100);
            break;
        case Efecto::AGOTADO:
            personaje->consumirResistencia(Agotamiento::getCantidadResistencia());
            personaje->consumirMana(Agotamiento::getCantidadMana());
            break;
        default:
            break;
    }
} 