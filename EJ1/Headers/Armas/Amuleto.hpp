#ifndef AMULETO_HPP
#define AMULETO_HPP

#include "ArmaMagica.hpp"

using namespace std;

class Amuleto : public ArmaMagica {
    public:
        Amuleto(Rareza rareza);
        void usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        void mostrarInfo() const override;
};

#endif