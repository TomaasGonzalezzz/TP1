#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/Pocion.hpp"
#include "../../Utilities/rarezas.hpp"

Pocion::Pocion(Rareza rareza) :
    ArmaMagica("Pocion", rareza, 0, 25, 5, 0, {make_shared<Regeneracion>(), make_shared<Envenenar>()}) { //utilidad_base, consumo_mana_base, usos, probabilidad_critico
    this->dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->consumo_mana_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->usos *= Rarezas::getMultiplicadorRareza(rareza);
    this->probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);  

}

void Pocion::mostrarInfo() const {
    cout << "Pocion: " << Rarezas::getNombreRareza(this->getRareza()) << endl;
    cout << "Dmg base: " << this->getDmgBase() << endl;
    cout << "Consumo de mana base: " << this->getConsumoManaBase() << endl;
    cout << "Usos: " << this->getUsos() << endl;
    cout << "Probabilidad de critico: " << this->getTasaCritico() << endl;
    cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) cout << efectos.first->getNombre() << endl;
    if (efectos.second) cout << efectos.second->getNombre() << endl;
}

void Pocion::usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    ArmaMagica::usar(personaje, rival);
    cout << "Ingresa el efecto a utilizar: " << endl;
    cout << "1. Regeneracion" << endl;
    cout << "2. Envenenar" << endl;
    cout << "3. Ninguno" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1) {
        if (this->efectos.first) {
            this->efectos.first->aplicar(personaje, rival);
        }
    } else if (opcion == 2) {
        if (this->efectos.second) {
            this->efectos.second->aplicar(personaje, rival);
        }
    } else if (opcion == 3) {
        cout << "No se aplicara ningun efecto." << endl;
    } else {
        cout << "Opcion invalida." << endl;
    }
    
    rival->actualizarEfectos();
}
void Pocion::recuperarVida(shared_ptr<InterfazDePersonaje> personaje, int cantidad) {
    if (usos <= 0) {
        std::cout << "No quedan usos de la poción." << std::endl;
        return;
    }
    personaje->curarVida(cantidad);
    usos--;
}

void Pocion::recuperarMana(shared_ptr<InterfazDePersonaje> personaje, int cantidad) {
    if (usos <= 0) {
        std::cout << "No quedan usos de la poción." << std::endl;
        return;
    }
    personaje->regenerarMana(cantidad);
    usos--;
}

void Pocion::recuperarResistencia(shared_ptr<InterfazDePersonaje> personaje, int cantidad) {
    if (usos <= 0) {
        std::cout << "No quedan usos de la poción." << std::endl;
        return;
    }
    personaje->regenerarResistencia(cantidad);
    usos--;
}
