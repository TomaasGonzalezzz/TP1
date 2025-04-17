#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "PersonajeFactory.hpp"

using namespace std;

int main() {
    srand(time(nullptr)); // semilla aleatoria

    vector<string> nombresMagos = {
        "Hechicero", "Brujo", "Conjurador", "Nigromante"
    };

    vector<string> nombresGuerreros = {
        "Barbaro", "Caballero", "Paladin", "Mercenario", "Gladiador"
    };

    int cantidadMagos = rand() % 5 + 3; // entre 3 y 7 magos
    int cantidadGuerreros = rand() % 5 + 3; // entre 3 y 7 guerreros

    vector<shared_ptr<InterfazDePersonaje>> magos;
    vector<shared_ptr<InterfazDePersonaje>> guerreros;

    // Generar magos armados aleatorios
    for (int i = 0; i < cantidadMagos; ++i) {
        string nombre = nombresMagos[rand() % nombresMagos.size()];
        Rango rango = static_cast<Rango>(rand() % 5); // rango aleatorio
        auto mago = PersonajeFactory::crearPersonajeArmado(nombre, rango);
        magos.push_back(mago);
    }

    // Generar guerreros armados aleatorios
    for (int i = 0; i < cantidadGuerreros; ++i) {
        string nombre = nombresGuerreros[rand() % nombresGuerreros.size()];
        Rango rango = static_cast<Rango>(rand() % 5); // rango aleatorio
        auto guerrero = PersonajeFactory::crearPersonajeArmado(nombre, rango);
        guerreros.push_back(guerrero);
    }

    // Mostrar todos los magos generados con sus armas
    cout << "\n===== Magos Generados =====\n" << endl;
    for (const auto& mago : magos) {
        mago->mostrarInfo();

        cout << "===== Armas Equipadas =====" << endl;

        const auto& armas = mago->getArmas();

        if (armas.first) {
            cout << "Arma 1: " << armas.first->getNombre()
                << " (Rareza: " << Rarezas::getNombreRareza(armas.first->getRareza()) << ")"
                << " -> Compatibilidad: " << (mago->compatibilidad(armas.first.get()) ? "Sí" : "No") << endl;
        } else {
            cout << "Arma 1: No equipada" << endl;
        }

        if (armas.second) {
            cout << "Arma 2: " << armas.second->getNombre()
                << " (Rareza: " << Rarezas::getNombreRareza(armas.second->getRareza()) << ")"
                << " -> Compatibilidad: " << (mago->compatibilidad(armas.second.get()) ? "Sí" : "No") << endl;
        } else {
            cout << "Arma 2: No equipada" << endl;
        }

        cout << "===========================\n" << endl;
    }

    // Mostrar todos los guerreros generados con sus armas
    cout << "\n===== Guerreros Generados =====\n" << endl;
    for (const auto& guerrero : guerreros) {
        guerrero->mostrarInfo();

        cout << "===== Armas Equipadas =====" << endl;

        const auto& armas = guerrero->getArmas();

        if (armas.first) {
            cout << "Arma 1: " << armas.first->getNombre()
                << " (Rareza: " << Rarezas::getNombreRareza(armas.first->getRareza()) << ")"
                << " -> Compatibilidad: " << (guerrero->compatibilidad(armas.first.get()) ? "Sí" : "No") << endl;
        } else {
            cout << "Arma 1: No equipada" << endl;
        }

        if (armas.second) {
            cout << "Arma 2: " << armas.second->getNombre()
                << " (Rareza: " << Rarezas::getNombreRareza(armas.second->getRareza()) << ")"
                << " -> Compatibilidad: " << (guerrero->compatibilidad(armas.second.get()) ? "Sí" : "No") << endl;
        } else {
            cout << "Arma 2: No equipada" << endl;
        }

        cout << "===========================\n" << endl;
    }
}