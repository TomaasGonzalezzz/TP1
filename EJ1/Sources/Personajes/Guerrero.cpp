#include "../../Headers/Personajes/Guerrero.hpp"
#include "../../Headers/Efectos/InterfazDeEfectos.hpp"
#include "../../Utilities/rangos.hpp"

using namespace std;

Guerrero::Guerrero(string nombre, Rango rango, int vida, int mana, int resistencia, pair<unique_ptr<InterfazArma>,unique_ptr<InterfazArma>> armas) : 
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

string Guerrero::getNombre() const {
    return this->nombre;
}
Rango Guerrero::getRango() const {
    return this->rango;
}
int Guerrero::getMana() const {
    return this->mana;
}
int Guerrero::getVida() const {
    return this->vida;
}
int Guerrero::getResistencia() const {
    return this->resistencia;
}
bool Guerrero::estaVivo() const {
    return this->vida > 0;
}
bool Guerrero::compatibilidad(InterfazArma* arma) const {
    return arma->getTipo() == "combate";
}

void Guerrero::mostrarInfo() const {
    cout << "Nombre: " << this->nombre << endl;
    cout << "Clase: " << this->clase << endl;
    cout << "Rango: " << Rangos::getNombreRango(this->rango) << endl;
    cout << "Vida: " << this->vida << endl;
    cout << "Mana: " << this->mana << endl;
    cout << "Resistencia: " << this->resistencia << endl;

}

const pair<unique_ptr<InterfazArma>, unique_ptr<InterfazArma>>& Guerrero::getArmas() const {
    return this->armas;
}
void Guerrero::recibirDmg(int dmg) {
    this->vida -= dmg;
}
void Guerrero::curarVida(int curacion) {
    this->vida += curacion;
}
void Guerrero::consumirResistencia(int consumo) {
    this->resistencia -= consumo;
}
void Guerrero::regenerarResistencia(int regeneracion) {
    this->resistencia += regeneracion;
}
void Guerrero::consumirMana(int consumo) {
    this->mana -= consumo;
}
void Guerrero::regenerarMana(int regeneracion) {
    this->mana += regeneracion;
}

void Guerrero::aplicarEfecto(Efecto efecto, int duracion) {
    this->estados.push_back(make_pair(efecto, duracion));
}

void Guerrero::actualizarEfectos() {
    for (auto& estado : this->estados) {
        if (estado.second <= 0) {
            continue;
        }
        propagarEfecto(estado.first, shared_from_this());
        estado.second--;
    }
}

vector<pair<Efecto,int>> Guerrero::getEstados() const {
    return this->estados;
}

void Guerrero::AtaqueMelee(shared_ptr<InterfazDePersonaje> rival) {
    if (this->resistencia >= 10) { //10 resistencia
        this->consumirResistencia(10);
        rival->recibirDmg(15); //15 de daño
    } else {
        cout << "No tienes suficiente resistencia para atacar." << endl;
    }
}

 