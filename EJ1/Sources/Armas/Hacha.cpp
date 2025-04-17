#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/Hacha.hpp"
#include "../../Utilities/rarezas.hpp"

Hacha::Hacha(Rareza rareza) :
    ArmaCombate("Hacha", rareza, 25, 20, 8, 15, {std::make_shared<Sangrado>(), std::make_shared<Ninguno>()}) {
    this->dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->consumo_resist_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->durabilidad *= Rarezas::getMultiplicadorRareza(rareza);
    this->probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);
}

void Hacha::mostrarInfo() const {
    std::cout << "Hacha: " << Rarezas::getNombreRareza(this->getRareza()) << std::endl;
    std::cout << "Dmg base: " << this->getDmgBase() << std::endl;
    std::cout << "Consumo de resistencia: " << this->getConsumoRestBase() << std::endl;
    std::cout << "Durabilidad: " << this->getDurabilidad() << std::endl;
    std::cout << "Probabilidad de critico: " << this->getTasaCritico() << std::endl;
    std::cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) std::cout << efectos.first->getNombre() << std::endl;
    if (efectos.second) std::cout << efectos.second->getNombre() << std::endl;
}

void Hacha::usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (this->getDurabilidad() <= 0) {
        std::cout << "El hacha está destruida y no puede usarse." << std::endl;
        return;
    }

    ArmaCombate::usar(personaje, rival);

    std::cout << "Selecciona efecto adicional:\n1. Sangrado\n2. Ninguno" << std::endl;
    int opcion;
    std::cin >> opcion;

    if (opcion == 1 && efectos.first) efectos.first->aplicar(personaje, rival);
    else if (opcion == 2 && efectos.second) efectos.second->aplicar(personaje, rival);
    else std::cout << "Opción inválida." << std::endl;

    rival->actualizarEfectos();
}

void Hacha::golpeEnfurecido(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        std::cout << "El hacha está destruida y no puede usarse." << std::endl;
        return;
    }

    int costo = this->getConsumoRestBase() * 2;
    if (personaje->getResistencia() < costo) {
        std::cout << personaje->getNombre() << " no tiene suficiente resistencia para el golpe enfurecido." << std::endl;
        return;
    }

    personaje->consumirResistencia(costo);
    int dmg = this->getDmgBase() * 2;
    rival->recibirDmg(dmg);
    this->durabilidad--;

    std::cout << personaje->getNombre() << " realiza un golpe enfurecido con el Hacha y causa " << dmg << " de daño." << std::endl;
}
