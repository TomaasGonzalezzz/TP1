#include "../../Headers/Armas/Amuleto.hpp"
#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Utilities/rarezas.hpp"

Amuleto::Amuleto(Rareza rareza) : 
ArmaMagica("Amuleto", 
    rareza, 0, 15, 5, 10, {make_shared<Regeneracion>(), make_shared<Inmunidad>()
}) {
    dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    consumo_mana_base *= Rarezas::getMultiplicadorRareza(rareza);
    usos *= Rarezas::getMultiplicadorRareza(rareza);
    probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);
} //dmg_base, consumo_mana_base, usos, probabilidad_critico

void Amuleto::mostrarInfo() const {
    cout << "Amuleto: " << Rarezas::getNombreRareza(this->getRareza()) << endl;
    cout << "Dmg base: " << this->getDmgBase() << endl;
    cout << "Consumo de mana base: " << this->getConsumoManaBase() << endl;
    cout << "Usos: " << this->getUsos() << endl;
    cout << "Probabilidad de critico: " << this->getTasaCritico() << endl;
    cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) cout << efectos.first->getNombre() << endl;
    if (efectos.second) cout << efectos.second->getNombre() << endl;
}

void Amuleto::usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    ArmaMagica::usar(personaje, rival);
    cout << "Ingresa el efecto a utilizar: " << endl;
    cout << "1. Regeneracion" << endl;
    cout << "2. Inmunidad" << endl;
    cout << "3. Ninguno" << endl;
    int opcion;
    cin >> opcion;
    if (opcion == 1) {
        if (this->getEfectos().first) {
            this->getEfectos().first->aplicar(personaje, rival);
        }
    } else if (opcion == 2) {
        if (this->getEfectos().first) {
            this->getEfectos().first->aplicar(personaje, rival);
        }
    } else if (opcion == 3) {
        cout << "No se aplicara ningun efecto." << endl;
    } else {
        cout << "Opcion invalida." << endl;
    }
    
    rival->actualizarEfectos();
}