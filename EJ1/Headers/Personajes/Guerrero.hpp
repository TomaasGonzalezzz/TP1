#ifndef GUERRERO_HPP
#define GUERRERO_HPP

#include "InterfazPersonajes.hpp"
#include "../Armas/InterfazArma.hpp"

class InterfazArma; 
class Rangos;

using namespace std;
class Guerrero : public InterfazDePersonaje, public enable_shared_from_this<Guerrero> {
    protected:
        string nombre;
        string clase = "Guerrero";
        Rango rango;
        int vida;
        int mana;
        int resistencia;
        pair<unique_ptr<InterfazArma>,unique_ptr<InterfazArma>> armas;
        vector<pair<Efecto,int>> estados; //Efecto y turnos restantes

    public:
        Guerrero(string nombre, Rango rango, int vida, int mana, int resistencia, pair<unique_ptr<InterfazArma>,unique_ptr<InterfazArma>> armas);
        bool estaVivo() const override;
        string getNombre() const override;
        Rango getRango() const override;
        bool compatibilidad(InterfazArma* arma) const override;
        int getVida() const override;
        int getMana() const override;
        int getResistencia() const override;
        void mostrarInfo() const override;
        vector<pair<Efecto,int>> getEstados() const override;//
        void actualizarEfectos() override;
        void aplicarEfecto(Efecto efecto, int duracion) override;
        const pair<unique_ptr<InterfazArma>, unique_ptr<InterfazArma>>& getArmas() const override;
        void recibirDmg(int dmg) override;
        void curarVida(int curacion) override;
        void consumirResistencia(int consumo) override;
        void regenerarResistencia(int regeneracion) override;
        void consumirMana(int consumo) override;
        void regenerarMana(int regeneracion) override;
        void AtaqueMelee(shared_ptr<InterfazDePersonaje> rival); //Cuando se le caen las armas hace esto 

        void setArmas(std::pair<std::unique_ptr<InterfazArma>, std::unique_ptr<InterfazArma>> nuevasArmas) override {
            this->armas = std::move(nuevasArmas);
        }

};

#endif