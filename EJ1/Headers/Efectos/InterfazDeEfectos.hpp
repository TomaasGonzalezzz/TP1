#ifndef INTERFAZDEEFECTOS_HPP
#define INTERFAZDEEFECTOS_HPP

#include <string>
#include <memory>

using namespace std;

class InterfazDePersonaje; 

class InterfazDeEfecto{
    public:
        virtual void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) = 0;
        virtual string getNombre() const = 0;
        virtual ~InterfazDeEfecto() = default;
};

#endif