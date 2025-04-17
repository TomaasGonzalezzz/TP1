#ifndef NIGROMANTE_HPP
#define NIGROMANTE_HPP

#include "Mago.hpp"
#include "../Efectos/EfectosDmg.hpp"

class Nigromante : public Mago {
public:
    Nigromante(Rango rango);

    void invocarEspectro(std::shared_ptr<InterfazDePersonaje> rival);
    void ritualCaidos();

    void mostrarInfo() const override;
};

#endif

