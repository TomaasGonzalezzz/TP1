#ifndef CONJURADOR_HPP
#define CONJURADOR_HPP

#include "Mago.hpp"
#include "../Efectos/EfectosSupport.hpp"

class Conjurador : public Mago {
public:
    Conjurador(Rango rango);

    void conjuroEspectral(std::shared_ptr<InterfazDePersonaje> rival);
    void canalizacionAstral();

    void mostrarInfo() const override;
};

#endif
