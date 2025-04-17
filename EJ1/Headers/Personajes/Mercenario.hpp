#ifndef MERCENARIO_HPP
#define MERCENARIO_HPP

#include "Guerrero.hpp"

class Mercenario : public Guerrero {
public:
    Mercenario(Rango rango);

    void estiloLibre(std::shared_ptr<InterfazDePersonaje> rival);
    void sobornoDeEnergia();

    void mostrarInfo() const override;
};

#endif
