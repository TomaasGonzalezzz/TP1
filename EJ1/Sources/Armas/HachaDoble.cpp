#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/HachaDoble.hpp"
#include "../../Utilities/rarezas.hpp"

HachaDoble::HachaDoble(Rareza rareza) :
    ArmaCombate("Hacha Doble", rareza, 28, 25, 7, 18, {std::make_shared<Sangrado>(), std::make_shared<Sobrecarga>()}) {
    this->dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->consumo_resist_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->durabilidad *= Rarezas::getMultiplicadorRareza(rareza);
    this->probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);
}

void HachaDoble::mostrarInfo() const {
    std::cout << "Hacha Doble: " << Rarezas::getNombreRareza(this->getRareza()) << std::endl;
    std::cout << "Dmg base: " << this->getDmgBase() << std::endl;
    std::cout << "Consumo de resistencia: " << this->getConsumoRestBase() << std::endl;
    std::cout << "Durabilidad: " << this->getDurabilidad() << std::endl;
    std::cout << "Probabilidad de critico: " << this->getTasaCritico() << std::endl;
    std::cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) std::cout << efectos.first->getNombre() << std::endl;
    if (efectos.second) std::cout << efectos.second->getNombre() << std::endl;
}

void HachaDoble::usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        std::cout << "El arma está rota y no puede usarse." << std::endl;
        return;
    }

    ArmaCombate::usar(personaje, rival);

    std::cout << "Selecciona efecto adicional:\n1. Sangrado\n2. Sobrecarga\n3. Ninguno" << std::endl;
    int opcion;
    std::cin >> opcion;

    if (opcion == 1 && efectos.first) efectos.first->aplicar(personaje, rival);
    else if (opcion == 2 && efectos.second) efectos.second->aplicar(personaje, rival);
    else if (opcion == 3) std::cout << "No se aplicará efecto adicional." << std::endl;
    else std::cout << "Opción inválida." << std::endl;

    rival->actualizarEfectos();
}

void HachaDoble::ataqueDoble(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad < 2) {
        std::cout << "El arma no tiene suficiente durabilidad para un ataque doble." << std::endl;
        return;
    }

    int costo = this->getConsumoRestBase() * 2;
    if (personaje->getResistencia() < costo) {
        std::cout << personaje->getNombre() << " no tiene suficiente resistencia para el ataque doble." << std::endl;
        return;
    }

    personaje->consumirResistencia(costo);
    int dmg_total = this->getDmgBase() * 2;
    rival->recibirDmg(dmg_total);
    this->durabilidad -= 2;

    std::cout << personaje->getNombre() << " realiza un ATAQUE DOBLE con Hacha Doble y causa " << dmg_total << " de daño a " << rival->getNombre() << "." << std::endl;
}
