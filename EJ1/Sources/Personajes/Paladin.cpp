#include "../../Headers/Personajes/Paladin.hpp"
#include "../../Utilities/rangos.hpp"

Paladin::Paladin(Rango rango)
    : Guerrero("Paladín", rango, 140, 60, 100, {nullptr, nullptr}) {
    this->clase = "Guerrero";
}

void Paladin::justiciaRadiante(std::shared_ptr<InterfazDePersonaje> rival) {
    int costo = 20;
    if (resistencia < costo) {
        std::cout << nombre << " no tiene suficiente resistencia." << std::endl;
        return;
    }

    this->consumirResistencia(costo);
    rival->recibirDmg(30);
    this->curarVida(10);

    std::cout << nombre << " usa Justicia Radiante: 30 de daño + 10 de curación." << std::endl;
}

void Paladin::oracionSanadora() {
    this->curarVida(20);
    this->regenerarResistencia(15);

    std::cout << nombre << " reza una Oración Sanadora: cura 20 de vida y 15 de resistencia." << std::endl;
}

void Paladin::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Justicia Radiante, Oración Sanadora" << std::endl;
}
