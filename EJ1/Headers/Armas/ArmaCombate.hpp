#ifndef ARMACOMBATE_HPP
#define ARMACOMBATE_HPP

#include "InterfazArma.hpp"

class InterfazDeEfectos;
class InterfazDePersonajes;

class ArmaCombate: public InterfazArma {
    protected:
        string nombre;
        string tipo = "combate";
        Rareza rareza;
        int dmg_base;
        int consumo_resist_base;
        int durabilidad;
        int probabilidad_critico;
        pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> efectos;
    public:
        ArmaCombate(string nombre, Rareza rareza, int dmg_base, int consumo_resist_base, int durabilidad,int probabilidad_critico, pair<shared_ptr<InterfazDeEfecto>, shared_ptr<InterfazDeEfecto>> efectos);
        string getNombre() const override;
        string getTipo() const override;
        Rareza getRareza() const override;
        int getDmgBase() const override;
        int getConsumoRestBase() const;
        int getDurabilidad() const;
        int getTasaCritico() const override;
        virtual void mostrarInfo() const override = 0;
        pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> getEfectos() const override;
        void usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override = 0;

    };  

#endif