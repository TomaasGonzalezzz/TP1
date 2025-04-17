#ifndef INTERFAZ_DE_ARMAS_HPP
#define INTERFAZ_DE_ARMAS_HPP

#include "../../Utilities/utilities.hpp"
#include "../Efectos/InterfazDeEfectos.hpp"
#include <string>
#include <memory>
#include <iostream>

using namespace std;

class InterfazDePersonaje; // como no uso sus metodos, con definirla alcanza

class InterfazArma {
    public:
        virtual string getNombre() const = 0;
        virtual string getTipo() const = 0;
        virtual Rareza getRareza() const = 0;
        virtual int getDmgBase() const = 0;
        virtual int getTasaCritico() const = 0;
        virtual void mostrarInfo() const = 0;
        virtual void usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) = 0;
        virtual pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> getEfectos() const = 0;
        virtual ~InterfazArma() = default;

};

#endif