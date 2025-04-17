#include "../../Headers/Personajes/Mercenario.hpp"
#include "../../Utilities/rangos.hpp"
#include <cstdlib>

Mercenario::Mercenario(Rango rango)
    : Guerrero("Mercenario", rango, 130, 70, 90, {nullptr, nullptr}) {
    this->clase = "Guerrero";
}

void Mercenario::estiloLibre(std::shared_ptr<InterfazDePersonaje> rival) {
    int costo = 20;
    if (resistencia < costo) {
        std::cout << nombre << " no tiene suficiente resistencia." << std::endl;
        return;
    }

    int dmg = 20 + rand() % 21; // entre 20 y 40
    this->consumirResistencia(costo);
    rival->recibirDmg(dmg);

    std::cout << nombre << " usa Estilo Libre: " << dmg << " de daño a " << rival->getNombre() << std::endl;
}

void Mercenario::sobornoDeEnergia() {
    if (mana < 15) {
        std::cout << nombre << " no tiene suficiente mana." << std::endl;
        return;
    }

    this->consumirMana(15);
    this->regenerarResistencia(30);

    std::cout << nombre << " realiza Soborno de Energía: gana 30 de resistencia." << std::endl;
}

void Mercenario::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Estilo Libre, Soborno de Energía" << std::endl;
}
