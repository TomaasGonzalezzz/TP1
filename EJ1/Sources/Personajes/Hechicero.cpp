#include "../../Headers/Personajes/Hechicero.hpp"
#include "../../Utilities/rangos.hpp"

Hechicero::Hechicero(Rango rango)
    : Mago("Hechicero", rango, 100, 140, 60, {nullptr, nullptr}) {
    this->clase = "Mago";
}

void Hechicero::selloMental(std::shared_ptr<InterfazDePersonaje> rival) {
    if (this->mana < 20) {
        std::cout << nombre << " no tiene suficiente mana para lanzar Sello Mental." << std::endl;
        return;
    }

    this->consumirMana(20);
    rival->aplicarEfecto(Efecto::ASUSTADO, 2);
    std::cout << nombre << " lanza Sello Mental. " << rival->getNombre() << " queda asustado por 2 turnos." << std::endl;
}

void Hechicero::ritualArcano() {
    if (this->mana < 10) {
        std::cout << nombre << " no tiene suficiente mana para ejecutar Ritual Arcano." << std::endl;
        return;
    }

    this->consumirMana(10);
    this->curarVida(30);
    this->regenerarMana(20);

    std::cout << nombre << " ejecuta Ritual Arcano: recupera 30 de vida y 20 de mana." << std::endl;
}

void Hechicero::mostrarInfo() const {
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Clase: " << this->clase << std::endl;
    std::cout << "Rango: " << Rangos::getNombreRango(this->rango) << std::endl;
    std::cout << "Vida: " << this->vida << std::endl;
    std::cout << "Mana: " << this->mana << std::endl;
    std::cout << "Resistencia: " << this->resistencia << std::endl;
    std::cout << "Habilidades: Sello Mental, Ritual Arcano" << std::endl;
}
