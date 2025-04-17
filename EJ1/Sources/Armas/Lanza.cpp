#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/Lanza.hpp"
#include "../../Utilities/rarezas.hpp"

Lanza::Lanza(Rareza rareza) :
    ArmaCombate("Lanza", rareza, 20, 15, 12, 25, {std::make_shared<ReduccionDeDano>(), std::make_shared<Sangrado>()}) {
    this->dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->consumo_resist_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->durabilidad *= Rarezas::getMultiplicadorRareza(rareza);
    this->probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);
}

void Lanza::mostrarInfo() const {
    std::cout << "Lanza: " << Rarezas::getNombreRareza(this->getRareza()) << std::endl;
    std::cout << "Dmg base: " << this->getDmgBase() << std::endl;
    std::cout << "Consumo de resistencia: " << this->getConsumoRestBase() << std::endl;
    std::cout << "Durabilidad: " << this->getDurabilidad() << std::endl;
    std::cout << "Probabilidad de critico: " << this->getTasaCritico() << std::endl;
    std::cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) std::cout << efectos.first->getNombre() << std::endl;
    if (efectos.second) std::cout << efectos.second->getNombre() << std::endl;
}

void Lanza::usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        std::cout << "La lanza está rota y no puede usarse." << std::endl;
        return;
    }

    ArmaCombate::usar(personaje, rival);

    std::cout << "Selecciona efecto adicional:\n1. Reducción de daño\n2. Sangrado\n3. Ninguno" << std::endl;
    int opcion;
    std::cin >> opcion;

    if (opcion == 1 && efectos.first) efectos.first->aplicar(personaje, rival);
    else if (opcion == 2 && efectos.second) efectos.second->aplicar(personaje, rival);
    else if (opcion == 3) std::cout << "No se aplicará efecto adicional." << std::endl;
    else std::cout << "Opción inválida." << std::endl;

    rival->actualizarEfectos();
}

void Lanza::estocadaPrecisa(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        std::cout << "La lanza está rota y no puede usarse." << std::endl;
        return;
    }

    int costo = this->getConsumoRestBase() * 0.6;
    int dmg = this->getDmgBase() * 0.75;

    if (personaje->getResistencia() < costo) {
        std::cout << personaje->getNombre() << " no tiene suficiente resistencia para la estocada precisa." << std::endl;
        return;
    }

    personaje->consumirResistencia(costo);
    rival->recibirDmg(dmg);

    this->durabilidad--;

    std::cout << personaje->getNombre() << " realiza una Estocada Precisa con la Lanza y causa " << dmg << " de daño ignorando defensas." << std::endl;
}
