#ifndef HACHA_HPP
#define HACHA_HPP

#include "ArmaCombate.hpp"

class Hacha : public ArmaCombate {
public:
    Hacha(Rareza rareza);
    void mostrarInfo() const override;
    void usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) override;

    void golpeEnfurecido(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival);
};

#endif
