#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Efectos/EfectosDmg.hpp"

using namespace std;

Envenenar::Envenenar() {}

void Envenenar::aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    cout << personaje->getNombre() << " aplica veneno a " << rival->getNombre() << endl;
    rival->recibirDmg(Envenenar::getCantidad());
}

string Envenenar::getNombre() const {
    return "Efecto Envenenado";
}

int Envenenar::getCantidad() {
    return cantidad;
}

Sangrado::Sangrado() {}

void Sangrado::aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    cout << personaje->getNombre() << " aplica sangrado a " << rival->getNombre() << endl;
    int dmg = rival->getVida() * Sangrado::getPorcentaje() / 100;
    rival->recibirDmg(dmg);
}

string Sangrado::getNombre() const {
    return "Efecto Sangrado";
}

int Sangrado::getPorcentaje() {
    return porcentaje;
}

Asustar::Asustar() {}

void Asustar::aplicar(shared_ptr<InterfazDePersonaje>, shared_ptr<InterfazDePersonaje> rival) {
    // Si no se cumple la probabilidad, no se aplica el efecto
    if (rand() % 100 > Asustar::getProbabilidad()) return;

    rival->aplicarEfecto(Efecto::ASUSTADO, 1);
    cout << rival->getNombre() << " queda Asustado por 1 turno" << endl;
}

string Asustar::getNombre() const {
    return "ASUSTAR";
}

int Asustar::getProbabilidad() {
    return probabilidad;
}

ReduccionDeDano::ReduccionDeDano() {}

void ReduccionDeDano::aplicar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    if (rand() % 100 > ReduccionDeDano::getPorcentaje()) return;
    
    cout << personaje->getNombre() << " aplica reduccion de dano a " << rival->getNombre() << endl;
    rival->aplicarEfecto(Efecto::REDUCCION_DE_DANO, 3);
}

string ReduccionDeDano::getNombre() const {
    return "REDUCCION_DE_DANO";
}

int ReduccionDeDano::getPorcentaje() {
    return porcentaje;
}
