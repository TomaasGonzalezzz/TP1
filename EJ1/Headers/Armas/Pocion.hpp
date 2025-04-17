#ifndef POCION_HPP
#define POCION_HPP

#include "ArmaMagica.hpp"

using namespace std;

class Pocion : public ArmaMagica {
    public:
        Pocion(Rareza rareza);
        void usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        void mostrarInfo() const override;
        void recuperarVida(shared_ptr<InterfazDePersonaje> personaje, int cantidad);
        void recuperarMana(shared_ptr<InterfazDePersonaje> personaje, int cantidad);
        void recuperarResistencia(shared_ptr<InterfazDePersonaje> personaje, int cantidad);
};


#endif