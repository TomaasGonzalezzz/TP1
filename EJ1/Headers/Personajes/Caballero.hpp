#ifndef CABALLERO_HPP
#define CABALLERO_HPP

#include "Guerrero.hpp"
#include "../Efectos/EfectosDmg.hpp"

class Caballero : public Guerrero {
public:
    Caballero(Rango rango);

    void estocadaDivina(std::shared_ptr<InterfazDePersonaje> rival);
    void proteccionSagrada();

    void mostrarInfo() const override;
};

#endif
