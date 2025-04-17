#include "../../Headers/Personajes/Caballero.hpp"
#include "../../Utilities/rangos.hpp"

Caballero::Caballero(Rango rango)
    : Guerrero("Caballero", rango, 150, 50, 110, {nullptr, nullptr}) {
    this->clase = "Guerrero";
}

void Caballero::estocadaDivina(std::shared_ptr<InterfazDePersonaje> rival) {
    int costo = 25;
    if (resistencia < costo) {
        std::cout << nombre << " no tiene suficiente resistencia." << std::endl;
        return;
    }

    this->consumirResistencia(costo);
    rival->recibirDmg(45);

    std::cout << nombre << " lanza Estocada Divina: 45 de daño a " << rival->getNombre() << std::endl;
}

void Caballero::proteccionSagrada() {
    aplicarEfecto(Efecto::REDUCCION_DE_DANO, 2);
    std::cout << nombre << " invoca Protección Sagrada: reduce el daño recibido por 2 turnos." << std::endl;
}

void Caballero::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Estocada Divina, Protección Sagrada" << std::endl;
}
