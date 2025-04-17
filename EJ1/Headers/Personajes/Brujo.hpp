#ifndef BRUJO_HPP
#define BRUJO_HPP

#include "Mago.hpp"
#include "../Efectos/EfectosDmg.hpp"

class Brujo : public Mago {
public:
    Brujo(Rango rango);

    void maleficio(std::shared_ptr<InterfazDePersonaje> rival);
    void pactoOscuro();

    void mostrarInfo() const override;
};

#endif

