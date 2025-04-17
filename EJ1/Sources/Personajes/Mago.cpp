#include "../../Headers/Personajes/Mago.hpp"
#include "../../Headers/Efectos/InterfazDeEfectos.hpp"
#include "../../Utilities/rangos.hpp"

using namespace std;

Mago::Mago(string nombre, Rango rango, int vida, int mana, int resistencia, pair<unique_ptr<InterfazArma>,unique_ptr<InterfazArma>> armas) : 
    nombre(nombre),
    rango(rango),
    vida(vida),
    mana(mana),
    resistencia(resistencia),
    armas(std::move(armas)),
    estados()
    {
        this->vida *= Rangos::getMultiplicadorRangos(rango);
        this->mana *= Rangos::getMultiplicadorRangos(rango);
        this->resistencia *= Rangos::getMultiplicadorRangos(rango);
    }

string Mago::getNombre() const {
    return this->nombre;
}
Rango Mago::getRango() const {
    return this->rango;
}
int Mago::getMana() const {
    return this->mana;
}
int Mago::getVida() const {
    return this->vida;
}
int Mago::getResistencia() const {
    return this->resistencia;
}
bool Mago::estaVivo() const {
    return this->vida > 0;
}
bool Mago::compatibilidad(InterfazArma* arma) const {
    return arma->getTipo() == "magica";
}
void Mago::mostrarInfo() const {
    cout << "Nombre: " << this->nombre << endl;
    cout << "Clase: " << this->clase << endl;
    cout << "Rango: " << Rangos::getNombreRango(this->rango) << endl;
    cout << "Vida: " << this->vida << endl;
    cout << "Mana: " << this->mana << endl;
    cout << "Resistencia: " << this->resistencia << endl;

}

const pair<unique_ptr<InterfazArma>,unique_ptr<InterfazArma>>& Mago::getArmas() const {
    return this->armas;
}
void Mago::recibirDmg(int dmg) {
    this->vida -= dmg;
}
void Mago::curarVida(int curacion) {
    this->vida += curacion;
}
void Mago::consumirResistencia(int consumo) {
    this->resistencia -= consumo;
}
void Mago::regenerarResistencia(int regeneracion) {
    this->resistencia += regeneracion;
}
void Mago::consumirMana(int consumo) {
    this->mana -= consumo;
}
void Mago::regenerarMana(int regeneracion) {
    this->mana += regeneracion;
}

void Mago::aplicarEfecto(Efecto efecto, int duracion) {
    this->estados.push_back(make_pair(efecto, duracion));
}

void Mago::actualizarEfectos() {
    for (auto& estado : this->estados) {
        if (estado.second <= 0) {
            continue;
        }
        propagarEfecto(estado.first, shared_from_this());
        estado.second--;
    }
}

vector<pair<Efecto,int>> Mago::getEstados() const {
    return this->estados;
}

void Mago::usarHechizo(shared_ptr<InterfazDePersonaje> rival, int manaCoste, int dmg) {
    if (this->mana >= manaCoste) { //5 mana para usar el hechizo
        this->consumirMana(manaCoste);
        rival->recibirDmg(dmg); //10 de daño
    } else {
        cout << "No tienes suficiente mana para usar el hechizo." << endl;
    }
}


 

