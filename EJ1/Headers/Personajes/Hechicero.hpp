#ifndef HECHICERO_HPP
#define HECHICERO_HPP

#include "Mago.hpp"
#include "../Efectos/EfectosDmg.hpp"
#include "../Efectos/EfectosSupport.hpp"

class Hechicero : public Mago {
public:
    Hechicero(Rango rango);

    void selloMental(std::shared_ptr<InterfazDePersonaje> rival);         
    void ritualArcano();                                                  
    void mostrarInfo() const override;
};

#endif
