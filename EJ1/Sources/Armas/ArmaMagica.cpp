#include "../../Headers/Armas/ArmaMagica.hpp"
#include "../../Headers/Personajes/InterfazPersonajes.hpp"
#include "../../Headers/Efectos/InterfazDeEfectos.hpp"

using namespace std;

ArmaMagica::ArmaMagica(string nombre, Rareza rareza, int dmg_base, int consumo_mana_base, int usos, int probabilidad_critico, pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> efectos) :
    nombre(nombre),
    rareza(rareza),
    dmg_base(dmg_base),
    consumo_mana_base(consumo_mana_base),
    usos(usos),
    probabilidad_critico(probabilidad_critico),
    efectos(efectos) {}

    string ArmaMagica::getNombre() const {
        return nombre;
    }
    string ArmaMagica::getTipo() const {
        return this->tipo;
    }
    Rareza ArmaMagica::getRareza() const {
        return rareza;
    }
    int ArmaMagica::getDmgBase() const {
        return dmg_base; 
    }
    int ArmaMagica::getUsos() const {
        return usos;
    }
    int ArmaMagica::getConsumoManaBase() const {
        return consumo_mana_base;
    }
    int ArmaMagica::getTasaCritico() const {
        return probabilidad_critico;
    }
    pair<shared_ptr<InterfazDeEfecto>,shared_ptr<InterfazDeEfecto>> ArmaMagica::getEfectos() const {
        return efectos;//queda por miedo
    }

    void ArmaMagica::usar(shared_ptr<InterfazDePersonaje> personaje, shared_ptr<InterfazDePersonaje> rival) {
        if (usos <= 0) {
            cout << "El ítem mágico no tiene más usos." << endl;
            return;
        }
    
        if (personaje->getMana() < consumo_mana_base) {
            cout << personaje->getNombre() << " no tiene suficiente mana." << endl;
            return;
        }
        int mana_consumo = this->consumo_mana_base;
        int dmg = this->dmg_base;

        if(personaje->compatibilidad(this)) {
            dmg *= 1.3; // Aumentar el daño si el personaje es compatible
        } else{
            dmg *= 0.7; // Reducir el daño si el personaje no es compatible
        }

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
                mana_consumo = mana_consumo * Sobrecarga::getCantidad() / 100;
            }
        }

        for (const auto& efecto : rival->getEstados()) {
            auto efecto_rival = efecto.first;
            
            if (efecto_rival == Efecto::INMUNE) {
                cout << "El personaje " << rival->getNombre() << " tiene inmunidad." << endl;
                return;
            }
        }
        if (rand() % 100 < probabilidad_critico) {
            dmg *= 2;
            cout << "¡Hechizo crítico!" << endl;
        }
        // Aplicar consumo de mana
        personaje->consumirMana(mana_consumo);
    
        // Reducir usos
        this->usos -= 1; 
    
        // Aplicar daño al rival
        rival->recibirDmg(dmg);
        cout << personaje->getNombre() << " usó " << this->nombre << " e hizo " << dmg << " de daño a " << rival->getNombre() << "." << endl;
    }
