#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Armas/LibroDeHechizos.hpp"
#include "../../Utilities/rarezas.hpp"

LibroDeHechizos::LibroDeHechizos(Rareza rareza) :
    ArmaMagica("Libro de Hechizos", rareza, 15, 25, 15, 15, {make_shared<Agotamiento>(), make_shared<Sobrecarga>()}) { //dmg_base, consumo_mana_base, usos, probabilidad_critico
    this->dmg_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->consumo_mana_base *= Rarezas::getMultiplicadorRareza(rareza);
    this->usos *= Rarezas::getMultiplicadorRareza(rareza);
    this->probabilidad_critico *= Rarezas::getMultiplicadorRareza(rareza);  
}
void LibroDeHechizos::mostrarInfo() const {
    cout << "Libro de Hechizos: " << Rarezas::getNombreRareza(this->getRareza()) << endl;
    cout << "Dmg base: " << this->getDmgBase() << endl;
    cout << "Consumo de mana base: " << this->getConsumoManaBase() << endl;
    cout << "Usos: " << this->getUsos() << endl;
    cout << "Probabilidad de critico: " << this->getTasaCritico() << endl;
    cout << "Efectos: ";
    auto efectos = this->getEfectos();
    if (efectos.first) cout << efectos.first->getNombre() << endl;
    if (efectos.second) cout << efectos.second->getNombre() << endl;
}

void LibroDeHechizos::usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    ArmaMagica::usar(personaje, rival);
    cout << "Ingresa el efecto a utilizar: " << endl;
    cout << "1. Agotamiento" << endl;
    cout << "2. Sobrecarga" << endl;
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

void LibroDeHechizos::recuperacion(shared_ptr<InterfazDePersonaje> personaje) {
    personaje->regenerarMana(this->getDmgBase()); //uso el dano como parametro base (para alterarlo con la rareza)
    personaje->regenerarResistencia(this->getDmgBase());
}