#ifndef BASTON_HPP
#define BASTON_HPP

#include "ArmaMagica.hpp"

using namespace std;

class Baston : public ArmaMagica {
public:
    Baston(Rareza rareza);
    void mostrarInfo() const override;
    void usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) override;
    void MagiaNegra(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival);
};

#endif