#ifndef EFECTOSDMG_HPP
#define EFECTOSDMG_HPP

#include "InterfazDeEfectos.hpp"

using namespace std;


class Asustar: public InterfazDeEfecto{
    private:
        static const int probabilidad = 60; //Este efecto tiene un 60% de probabilidad de hacer que el rival no ataque
    public:
        Asustar();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getProbabilidad();
};

class Envenenar: public InterfazDeEfecto{
    private:
        static const int cantidad = 15; //dano que baja por turno
    public:
        Envenenar();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getCantidad();
};

class Sangrado: public InterfazDeEfecto{
    private:
        static const int porcentaje = 15; //porcentaje de vida que resta
    public:
        Sangrado();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getPorcentaje();
};

class ReduccionDeDano: public InterfazDeEfecto{
    private:
        static const int porcentaje = 30; //porcentaje de dano que se reduce
    public:
        ReduccionDeDano();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getPorcentaje();
};

#endif