#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/Espada.hpp"
#include "../../Utilities/rarezas.hpp"

Espada::Espada(Rareza rareza) :
    ArmaCombate("Espada", rareza, 18, 15, 10, 20, {std::make_shared<Sangrado>(), std::make_shared<Ninguno>()}) {
    this->dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->consumo_resist_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->durabilidad *= Rarezas::getMultiplicadorRareza(rareza);
    this->probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);  
}

void Espada::mostrarInfo() const {
    std::cout << "Espada: " << Rarezas::getNombreRareza(this->getRareza()) << std::endl;
    std::cout << "Dmg base: " << this->getDmgBase() << std::endl;
    std::cout << "Consumo de resistencia: " << this->getConsumoRestBase() << std::endl;
    std::cout << "Durabilidad: " << this->getDurabilidad() << std::endl;
    std::cout << "Probabilidad de critico: " << this->getTasaCritico() << std::endl;
    std::cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) std::cout << efectos.first->getNombre() << std::endl;
    if (efectos.second) std::cout << efectos.second->getNombre() << std::endl;
}

void Espada::usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) {
    ArmaCombate::usar(personaje, rival);

    std::cout << "Selecciona efecto adicional a aplicar:" << std::endl;
    std::cout << "1. Sangrado" << std::endl;
    std::cout << "2. Ninguno" << std::endl;

    int opcion;
    std::cin >> opcion;
    if (opcion == 1 && efectos.first) {
        efectos.first->aplicar(personaje, rival);
    } else if (opcion == 2 && efectos.second) {
        efectos.second->aplicar(personaje, rival);
    } else {
        std::cout << "Opcion invalida. No se aplicará efecto." << std::endl;
    }

    rival->actualizarEfectos();
}

void Espada::cortePreciso(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        std::cout << "La espada está rota y no puede usarse." << std::endl;
        return;
    }

    int dmg = dmg_base * 0.6;
    int costo = consumo_resist_base * 0.5;

    if (personaje->getResistencia() < costo) {
        std::cout << personaje->getNombre() << " no tiene suficiente resistencia para Corte Preciso." << std::endl;
        return;
    }

    personaje->consumirResistencia(costo);
    rival->recibirDmg(dmg);
    durabilidad--;

    std::cout << personaje->getNombre() << " realiza un Corte Preciso y causa " << dmg << " de daño a " << rival->getNombre() << std::endl;
}

