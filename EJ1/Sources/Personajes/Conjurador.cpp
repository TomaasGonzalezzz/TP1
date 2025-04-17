#include "../../Headers/Personajes/Conjurador.hpp"
#include "../../Utilities/rangos.hpp"

Conjurador::Conjurador(Rango rango)
    : Mago("Conjurador", rango, 110, 130, 70, {nullptr, nullptr}) {
    this->clase = "Mago";
}

void Conjurador::conjuroEspectral(std::shared_ptr<InterfazDePersonaje> rival) {
    if (mana < 25) {
        std::cout << nombre << " no tiene suficiente mana para Conjuro Espectral." << std::endl;
        return;
    }

    this->consumirMana(25);
    rival->recibirDmg(35);
    rival->aplicarEfecto(Efecto::SOBRECARGA, 2);

    std::cout << nombre << " lanza Conjuro Espectral, causa 35 de daño y sobrecarga a " << rival->getNombre() << std::endl;
}

void Conjurador::canalizacionAstral() {
    if (mana < 10) {
        std::cout << nombre << " no tiene suficiente mana." << std::endl;
        return;
    }

    this->consumirMana(10);
    this->curarVida(25);
    this->regenerarResistencia(20);

    std::cout << nombre << " canaliza energía astral: cura 25 de vida y gana 20 de resistencia." << std::endl;
}

void Conjurador::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Conjuro Espectral, Canalización Astral" << std::endl;
}
