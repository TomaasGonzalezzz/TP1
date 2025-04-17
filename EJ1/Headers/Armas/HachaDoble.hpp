#ifndef HACHADOBLE_HPP
#define HACHADOBLE_HPP

#include "ArmaCombate.hpp"


class HachaDoble : public ArmaCombate {
public:
    HachaDoble(Rareza rareza);
    void mostrarInfo() const override;
    void usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) override;

    void ataqueDoble(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival);
};

#endif
