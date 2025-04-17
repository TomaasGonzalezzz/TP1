#ifndef GARROTE_HPP
#define GARROTE_HPP

#include "ArmaCombate.hpp"

class Garrote : public ArmaCombate {
public:
    Garrote(Rareza rareza);
    void mostrarInfo() const override;
    void usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) override;

    void golpeCargado(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival);
};

#endif
