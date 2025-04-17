#ifndef GLADIADOR_HPP
#define GLADIADOR_HPP

#include "Guerrero.hpp"

class Gladiador : public Guerrero {
public:
    Gladiador(Rango rango);

    void comboFatal(std::shared_ptr<InterfazDePersonaje> rival);
    void provocacion(std::shared_ptr<InterfazDePersonaje> rival);

    void mostrarInfo() const override;
};

#endif
