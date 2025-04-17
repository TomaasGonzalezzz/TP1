#include "../../Headers/Personajes/Barbaro.hpp"
#include "../../Utilities/rangos.hpp"

Barbaro::Barbaro(Rango rango)
    : Guerrero("Bárbaro", rango, 160, 40, 120, {nullptr, nullptr}) {
    this->clase = "Guerrero";
}

void Barbaro::golpeRabioso(std::shared_ptr<InterfazDePersonaje> rival) {
    int costo = 30;
    if (resistencia < costo) {
        std::cout << nombre << " no tiene suficiente resistencia para Golpe Rabioso." << std::endl;
        return;
    }

    this->consumirResistencia(costo);
    rival->recibirDmg(50);

    std::cout << nombre << " usa Golpe Rabioso: 50 de daño a " << rival->getNombre() << std::endl;
}

void Barbaro::gritoDeGuerra() {
    this->regenerarResistencia(25);

    std::cout << nombre << " lanza Grito de Guerra: recupera 25 de resistencia." << std::endl;
}

void Barbaro::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Golpe Rabioso, Grito de Guerra" << std::endl;
}

