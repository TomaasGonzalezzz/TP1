#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/Garrote.hpp"
#include "../../Utilities/rarezas.hpp"

Garrote::Garrote(Rareza rareza) :
    ArmaCombate("Garrote", rareza, 22, 20, 10, 10, {std::make_shared<Asustar>(), std::make_shared<Ninguno>()}) {
    dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    consumo_resist_base *= Rarezas::getMultiplicadorRareza(rareza);
    durabilidad *= Rarezas::getMultiplicadorRareza(rareza);
    probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);
}

void Garrote::mostrarInfo() const {
    std::cout << "Garrote: " << Rarezas::getNombreRareza(this->getRareza()) << std::endl;
    std::cout << "Dmg base: " << this->getDmgBase() << std::endl;
    std::cout << "Consumo de resistencia: " << this->getConsumoRestBase() << std::endl;
    std::cout << "Durabilidad: " << this->getDurabilidad() << std::endl;
    std::cout << "Probabilidad de critico: " << this->getTasaCritico() << std::endl;
    std::cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) std::cout << efectos.first->getNombre() << std::endl;
    if (efectos.second) std::cout << efectos.second->getNombre() << std::endl;
}

void Garrote::usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        std::cout << "El garrote está roto y no puede usarse." << std::endl;
        return;
    }

    ArmaCombate::usar(personaje, rival);

    std::cout << "Selecciona efecto adicional a aplicar:\n1. Asustar\n2. Ninguno" << std::endl;
    int opcion;
    std::cin >> opcion;

    if (opcion == 1 && efectos.first) efectos.first->aplicar(personaje, rival);
    else if (opcion == 2 && efectos.second) efectos.second->aplicar(personaje, rival);
    else std::cout << "Opción inválida." << std::endl;

    rival->actualizarEfectos();
}

void Garrote::golpeCargado(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        std::cout << "El garrote está roto y no puede usarse." << std::endl;
        return;
    }

    int costo = this->getConsumoRestBase() * 1.5;
    if (personaje->getResistencia() < costo) {
        std::cout << personaje->getNombre() << " no tiene suficiente resistencia para el golpe cargado." << std::endl;
        return;
    }

    personaje->consumirResistencia(costo);
    rival->recibirDmg(this->getDmgBase() * 1.5);
    durabilidad--;

    std::cout << personaje->getNombre() << " realiza un golpe cargado con el Garrote y causa " << this->getDmgBase() * 1.5 << " de daño." << std::endl;
}
