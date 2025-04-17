#ifndef BARBARO_HPP
#define BARBARO_HPP

#include "Guerrero.hpp"

class Barbaro : public Guerrero {
public:
    Barbaro(Rango rango);

    void golpeRabioso(std::shared_ptr<InterfazDePersonaje> rival);
    void gritoDeGuerra();

    void mostrarInfo() const override;
};

#endif
