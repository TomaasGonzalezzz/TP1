#ifndef ARMAMAGICA_HPP
#define ARMAMAGICA_HPP

#include "InterfazArma.hpp"

using namespace std;

class InterfazDeEfectos;
class InterfazDePersonajes;

class ArmaMagica: public InterfazArma{
    protected:
        string nombre;
        string tipo = "magica";
        Rareza rareza;
        int dmg_base;
        int consumo_mana_base;
        int usos;
        int probabilidad_critico;
        pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> efectos;
    public:
        ArmaMagica(string nombre, Rareza rareza, int dmg_base, int consumo_mana_base, int usos, int probabilidad_critico, 
        pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> efectos);
        string getNombre() const override;
        string getTipo() const override;
        Rareza getRareza() const override;
        int getDmgBase() const override;
        int getConsumoManaBase() const;
        int getUsos() const;
        int getTasaCritico() const override;
        virtual void mostrarInfo() const override = 0;
        pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> getEfectos() const override;
        void usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override = 0;

};
#endif

