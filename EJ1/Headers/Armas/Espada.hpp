#ifndef ESPADA_HPP
#define ESPADA_HPP

#include "ArmaCombate.hpp"

using namespace std;

class Espada : public ArmaCombate {
public:
    Espada(Rareza rareza);
    void mostrarInfo() const override;
    void usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) override;
    
    void cortePreciso(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival);
};

#endif
