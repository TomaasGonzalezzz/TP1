#ifndef EFECTOSSUP_HPP
#define EFECTOSSUP_HPP

#include "InterfazDeEfectos.hpp"

using namespace std;


class Regeneracion: public InterfazDeEfecto{
    private:
        static const int cantidad = 25; //cura 25hp por turno
    public:
        Regeneracion();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getCantidad();
};

class Agotamiento: public InterfazDeEfecto{
    private:
        static const int cantidad_resist = 10; //cantidad de resistencia que baja
        static const int cantidad_mana = 15; //cantidad de mana que baja
    public:
        Agotamiento();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getCantidadResistencia();
        static int getCantidadMana();
};

class Inmunidad: public InterfazDeEfecto{
    private:
        static const int probabilidad = 70; //probabilidad de que se aplica el efecto cuando lo uso (sino estaria muy roto)
    public:
        Inmunidad();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getProbabilidad();
};

class Robo_de_Mana: public InterfazDeEfecto{
    private:
        static const int porcentaje = 20; //roba un 20% de la reserva magica rival
    public:
        Robo_de_Mana();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getPorcentaje();
};

class Sobrecarga: public InterfazDeEfecto{
    private:
        static const int cantidad = 30; //boostea el dano en un 30%
        static const int exito = 75; //probabilidad de que se aplica el efecto cuando lo uso (sino estaria muy roto)
    public:
        Sobrecarga();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getCantidad();
        static int getExito();
};

class Robo_de_HP: public InterfazDeEfecto{
    private:
        static const int porcentaje = 20; //porcentaje de vida que roba
    public:
        Robo_de_HP();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
        static int getPorcentaje();
};

class Ninguno: public InterfazDeEfecto{
    public:
        Ninguno();
        void aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) override;
        string getNombre() const override;
};

#endif