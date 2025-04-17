#ifndef LANZA_HPP
#define LANZA_HPP

#include "ArmaCombate.hpp"


class Lanza : public ArmaCombate {
public:
    Lanza(Rareza rareza);
    void mostrarInfo() const override;
    void usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) override;

    void estocadaPrecisa(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival);
};

#endif
