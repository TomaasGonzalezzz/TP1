#include "../../Headers/Armas/ArmaCombate.hpp"
#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Efectos/InterfazDeEfectos.hpp"
#include "../../Utilities/utilities.hpp"
#include "ArmaCombate.hpp"

using namespace std;

ArmaCombate::ArmaCombate(string nombre, Rareza rareza, int dmg_base, int consumo_resist_base, int durabilidad, int probabilidad_critico, pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> efectos) :
    nombre(nombre),
    rareza(rareza),
    dmg_base(dmg_base),
    consumo_resist_base(consumo_resist_base),
    durabilidad(durabilidad),
    probabilidad_critico(probabilidad_critico),
    efectos(efectos) 
{}

string ArmaCombate::getNombre() const {
    return nombre;
}
string ArmaCombate::getTipo() const {
    return this->tipo;
}
Rareza ArmaCombate::getRareza() const {
    return rareza;
}
int ArmaCombate::getDmgBase() const {
    return dmg_base; 
}
int ArmaCombate::getDurabilidad() const {
    return durabilidad;
}
int ArmaCombate::getConsumoRestBase() const {
    return consumo_resist_base;
}
int ArmaCombate::getTasaCritico() const {
    return probabilidad_critico;
}
pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> ArmaCombate::getEfectos() const {
    return efectos;
}

void ArmaCombate::usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
    if (durabilidad <= 0) {
        cout << "El arma está rota y no puede usarse." << endl;
        return;
    }

    if (personaje->getResistencia() < consumo_resist_base) {
        cout << personaje->getNombre() << " no tiene suficiente resistencia." << endl;
        return;
    }
    // Calcular daño base
    int dmg = this->dmg_base;
    int resistencia_consumo = this->consumo_resist_base;

    if(personaje->compatibilidad(this)) {
        dmg *= 1.3; // Aumentar el daño si el personaje es compatible
    } else{
        dmg *= 0.7; // Reducir el daño si el personaje no es compatible
    }
    
    // Revisar efectos del personaje
    for (const auto& estado : personaje->getEstados()) {
        auto efecto = estado.first;

        if (efecto == Efecto::ASUSTADO) {
            cout << personaje->getNombre() << " está asustado y no puede atacar." << endl;
            return;
        }

        if (efecto == Efecto::REDUCCION_DE_DANO) {
            cout << "El arma " << this->nombre << " tiene reducción de daño." << endl;
            dmg = dmg * 0.6; 
        }

        if (efecto == Efecto::SOBRECARGA) {
            cout << "El arma " << this->nombre << " tiene sobrecarga." << endl;
            dmg = dmg * Sobrecarga::getCantidad() / 100;
            resistencia_consumo = resistencia_consumo * Sobrecarga::getCantidad() / 100;
        }
    }

    for (const auto& efecto : rival->getEstados()) {
        auto efecto_rival = efecto.first;
        
        if (efecto_rival == Efecto::INMUNE) {
            cout << "El personaje " << rival->getNombre() << " tiene inmunidad." << endl;
            return;
        }
    }
    // Crítico
    if (rand() % 100 < probabilidad_critico) {
        dmg *= 2;
        cout << "¡Golpe crítico!" << endl;
    }

    // Aplicar consumo de resistencia
    personaje->consumirResistencia(resistencia_consumo);

    // Reducir durabilidad
    this->durabilidad -= 1; 

    // Aplicar daño al rival
    rival->recibirDmg(dmg);
    cout << personaje->getNombre() << " usó " << this->nombre << " e hizo " << dmg << " de daño a " << rival->getNombre() << "." << endl;
}



