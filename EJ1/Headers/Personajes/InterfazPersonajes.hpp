#ifndef INTERFAZDEPERSONAJES_HPP
#define INTERFAZDEPERSONAJES_HPP

#include "../../Utilities/utilities.hpp"
#include <string>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;

class InterfazArma;

class InterfazDePersonaje{
    public:
        virtual bool estaVivo() const = 0; 
        virtual string getNombre() const = 0;
        virtual Rango getRango() const = 0;
        virtual bool compatibilidad(InterfazArma*) const = 0; 
        virtual int getVida() const = 0;
        virtual int getMana() const = 0;
        virtual int getResistencia() const = 0;
        virtual void mostrarInfo() const = 0;
        
        virtual vector<pair<Efecto,int>> getEstados() const = 0;
        virtual void actualizarEfectos() = 0; //actualiza los turnos restantes de los efectos
        virtual void aplicarEfecto(Efecto efecto, int duracion) = 0;

        virtual const pair<unique_ptr<InterfazArma>,unique_ptr<InterfazArma>>& getArmas() const = 0;

        virtual void recibirDmg(int dmg) = 0;
        virtual void curarVida(int curacion) = 0;
        virtual void consumirResistencia(int consumo) = 0;
        virtual void regenerarResistencia(int regeneracion) = 0;
        virtual void consumirMana(int consumo) = 0;
        virtual void regenerarMana(int regeneracion) = 0;

        virtual void setArmas(std::pair<std::unique_ptr<InterfazArma>, std::unique_ptr<InterfazArma>> nuevasArmas) = 0;


        virtual ~InterfazDePersonaje() = default;
};

#endif