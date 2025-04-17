#include "../../Headers/Personajes/Brujo.hpp"
#include "../../Utilities/rangos.hpp"

Brujo::Brujo(Rango rango)
    : Mago("Brujo", rango, 90, 160, 55, {nullptr, nullptr}) {
    this->clase = "Mago";
}

void Brujo::maleficio(std::shared_ptr<InterfazDePersonaje> rival) {
    if (mana < 20) {
        std::cout << nombre << " no tiene suficiente mana." << std::endl;
        return;
    }

    this->consumirMana(20);
    rival->recibirDmg(30);
    rival->aplicarEfecto(Efecto::REDUCCION_DE_DANO, 2);

    std::cout << nombre << " lanza Maleficio, causa 30 de daño y reduce el daño de " << rival->getNombre() << std::endl;
}

void Brujo::pactoOscuro() {
    if (vida < 15) {
        std::cout << nombre << " no tiene suficiente vida para realizar Pacto Oscuro." << std::endl;
        return;
    }

    vida -= 15;
    regenerarMana(35);

    std::cout << nombre << " realiza Pacto Oscuro: sacrifica 15 de vida y gana 35 de mana." << std::endl;
}

void Brujo::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Maleficio, Pacto Oscuro" << std::endl;
}
