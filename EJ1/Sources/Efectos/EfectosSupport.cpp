#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Efectos/EfectosSupport.hpp"
#include "../../Utilities/utilities.hpp"

using namespace std;


Robo_de_HP::Robo_de_HP() {}

void Robo_de_HP::aplicar(shared_ptr<InterfazDePersonaje> usuario, shared_ptr<InterfazDePersonaje> rival) {
    // Calculo de vida robada
    int vidaRobada = rival->getVida() * Robo_de_HP::getPorcentaje() / 100;
    cout << usuario->getNombre() << " roba " << vidaRobada << " de vida a " << rival->getNombre() << endl;
    // Curacion del usuario
    usuario->curarVida(vidaRobada);

    // Daño al objetivo
    rival->recibirDmg(vidaRobada);
}

string Robo_de_HP::getNombre() const {
    return "Robo de HP";
}

int Robo_de_HP::getPorcentaje() {
    return porcentaje;
}

Robo_de_Mana::Robo_de_Mana() {}

void Robo_de_Mana::aplicar(shared_ptr<InterfazDePersonaje> usuario, shared_ptr<InterfazDePersonaje> rival) {
    int ManaRobado = rival->getMana() * Robo_de_Mana::getPorcentaje() / 100;
    cout << usuario->getNombre() << " roba " << ManaRobado << " de Mana a " << rival->getNombre() << endl;
    
    usuario->regenerarMana(ManaRobado);

    rival->consumirMana(ManaRobado);
}

string Robo_de_Mana::getNombre() const {
    return "Robo de Mana";
}

int Robo_de_Mana::getPorcentaje() {
    return porcentaje;
}

Agotamiento::Agotamiento() {}

void Agotamiento::aplicar(shared_ptr<InterfazDePersonaje> usuario, shared_ptr<InterfazDePersonaje> rival) {
    int ConsumoDeResistencia = Agotamiento::getCantidadResistencia();
    cout << usuario->getNombre() << " pierde " << ConsumoDeResistencia << " de Resistencia " << endl;
    
    int ConsumoDeMana = Agotamiento::getCantidadMana();
    cout << usuario->getNombre() << " pierde " << ConsumoDeMana << " de Mana " << endl;

    rival->consumirMana(ConsumoDeMana);

    rival->consumirResistencia(ConsumoDeResistencia);
}

string Agotamiento::getNombre() const {
    return "Agotado";
}

int Agotamiento::getCantidadResistencia() {
    return cantidad_resist;
}

int Agotamiento::getCantidadMana() {
    return cantidad_mana;
}

Regeneracion::Regeneracion() {}

void Regeneracion::aplicar(shared_ptr<InterfazDePersonaje> usuario, shared_ptr<InterfazDePersonaje> rival) {
    cout << usuario->getNombre() << " cura " << Regeneracion::getCantidad() << " de vida a " << rival->getNombre() << endl;
    rival->curarVida(Regeneracion::getCantidad());
}

string Regeneracion::getNombre() const {
    return "Regeneracion";
}

int Regeneracion::getCantidad() {
    return cantidad;
}

Inmunidad::Inmunidad() {}

void Inmunidad::aplicar(shared_ptr<InterfazDePersonaje> usuario, shared_ptr<InterfazDePersonaje> rival) {
    if (rand() % 100 >  Inmunidad::getProbabilidad()) return;

    cout << usuario->getNombre() << " se vuelve inmune a los ataques de " << rival->getNombre() << endl;
    usuario->aplicarEfecto(Efecto::INMUNE, 1);
}

string Inmunidad::getNombre() const {
    return "Inmunidad";
}

int Inmunidad::getProbabilidad() {
    return probabilidad;
}

Sobrecarga::Sobrecarga() {}

void Sobrecarga::aplicar(shared_ptr<InterfazDePersonaje> usuario, shared_ptr<InterfazDePersonaje> rival) {
    if (rand() % 100 > Sobrecarga::getExito()) return;

    cout << usuario->getNombre() << " sobrecarga a " << rival->getNombre() << endl;
    usuario->aplicarEfecto(Efecto::SOBRECARGA, 2);
}

string Sobrecarga::getNombre() const {
    return "Sobrecarga";
}

int Sobrecarga::getCantidad() {
    return cantidad;
}

int Sobrecarga::getExito() {
    return exito;
}

Ninguno::Ninguno() {}

void Ninguno::aplicar(shared_ptr<InterfazDePersonaje>, shared_ptr<InterfazDePersonaje>) {
    cout << "No se aplica ningun efecto" << endl;
}

string Ninguno::getNombre() const {
    return "Ninguno";
}