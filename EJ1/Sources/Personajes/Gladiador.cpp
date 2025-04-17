#include "../../Headers/Personajes/Gladiador.hpp"
#include "../../Utilities/rangos.hpp"

Gladiador::Gladiador(Rango rango)
    : Guerrero("Gladiador", rango, 145, 45, 100, {nullptr, nullptr}) {
    this->clase = "Guerrero";
}

void Gladiador::comboFatal(std::shared_ptr<InterfazDePersonaje> rival) {
    int costo = 30;
    if (resistencia < costo) {
        std::cout << nombre << " no tiene suficiente resistencia." << std::endl;
        return;
    }

    this->consumirResistencia(costo);
    rival->recibirDmg(20);
    rival->recibirDmg(25);

    std::cout << nombre << " realiza Combo Fatal: dos ataques seguidos por 20 y 25 de daño." << std::endl;
}

void Gladiador::provocacion(std::shared_ptr<InterfazDePersonaje> rival) {
    if (rival->getVida() < 50) {
        rival->aplicarEfecto(Efecto::ASUSTADO, 2);
        std::cout << rival->getNombre() << " se asusta : entra en estado ASUSTADO." << std::endl;
    } else {
        std::cout << rival->getNombre() << " no le afecta el susto." << std::endl;
    }
}

void Gladiador::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Combo Fatal, Provocación" << std::endl;
}
