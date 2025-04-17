#ifndef PALADIN_HPP
#define PALADIN_HPP

#include "Guerrero.hpp"

class Paladin : public Guerrero {
public:
    Paladin(Rango rango);

    void justiciaRadiante(std::shared_ptr<InterfazDePersonaje> rival);
    void oracionSanadora();

    void mostrarInfo() const override;
};

#endif
