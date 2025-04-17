#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/Baston.hpp"
#include "../../Utilities/rarezas.hpp"

Baston::Baston(Rareza rareza) :
    ArmaMagica("Baston", rareza, 20, 25, 10, 15, {make_shared<ReduccionDeDano>(), make_shared<Ninguno>()}) {
    dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    consumo_mana_base *= Rarezas::getMultiplicadorRareza(rareza);
    usos *= Rarezas::getMultiplicadorRareza(rareza);
    probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);
}

void Baston::mostrarInfo() const {
    cout << "Baston: " << Rarezas::getNombreRareza(this->getRareza()) << endl;
    cout << "Dmg base: " << this->getDmgBase() << endl;
    cout << "Consumo de mana base: " << this->getConsumoManaBase() << endl;
    cout << "Usos: " << this->getUsos() << endl;
    cout << "Probabilidad de critico: " << this->getTasaCritico() << endl;
    cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) cout << efectos.first->getNombre() << endl;
    if (efectos.second) cout << efectos.second->getNombre() << endl;
}

void Baston::usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    ArmaMagica::usar(personaje, rival);
    cout << "Ingresa el efecto a utilizar: " << endl;
    cout << "1. Reduccion de dano" << endl;
    cout << "2. Ninguno" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1) {
        if (this->getEfectos().first) {
            this->getEfectos().first->aplicar(personaje, rival);
        }
    } else if (opcion == 2) {
        if (this->getEfectos().second) {
            this->getEfectos().second->aplicar(personaje, rival);
        }
    } else {
        cout << "Opcion invalida." << endl;
    }
    
    rival->actualizarEfectos();
}   

void Baston::MagiaNegra(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    int dmg_magia_negra = this->getDmgBase() * 1.5;
    int costo_magia_negra = this->getConsumoManaBase() * 1.5;
    int consumo_usos_magia_negra = 1;

    if (this->getUsos() < consumo_usos_magia_negra) {
        std::cout << personaje->getNombre() << " no tiene usos suficientes para lanzar Magia Negra." << std::endl;
        return;
    }

    if (personaje->getMana() < costo_magia_negra) {
        std::cout << personaje->getNombre() << " no tiene suficiente mana para Magia Negra." << std::endl;
        return;
    }

    personaje->consumirMana(costo_magia_negra);
    this->usos -= consumo_usos_magia_negra;

    rival->recibirDmg(dmg_magia_negra);
    std::cout << personaje->getNombre() << " lanza Magia Negra y causa " << dmg_magia_negra << " de daño a " << rival->getNombre() << std::endl;
}


