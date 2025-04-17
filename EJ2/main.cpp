#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "PersonajeFactory.hpp"

using namespace std;

int main() {
    srand(time(nullptr)); // semilla aleatoria

    vector<string> nombresPersonajes = {
        "Hechicero", "Brujo", "Conjurador", "Nigromante",
        "Barbaro", "Caballero", "Paladin", "Mercenario", "Gladiador"
    };

    int cantidadPersonajes = rand() % 5 + 3; // entre 3 y 7 personajes
    vector<shared_ptr<InterfazDePersonaje>> personajes;

    // Generar personajes armados aleatorios
    for (int i = 0; i < cantidadPersonajes; ++i) {
        string nombre = nombresPersonajes[rand() % nombresPersonajes.size()];
        Rango rango = static_cast<Rango>(rand() % 5); // rango aleatorio
        auto personaje = PersonajeFactory::crearPersonajeArmado(nombre, rango);
        personajes.push_back(personaje);
    }

    // Mostrar todos los personajes generados con sus armas
    cout << "\n===== Personajes Generados =====\n" << endl;
    for (const auto& personaje : personajes) {
        personaje->mostrarInfo();

        cout << "===== Armas Equipadas =====" << endl;

        // Obtener referencia a las armas del personaje
        const auto& armas = personaje->getArmas();

        // Validar y mostrar el arma 1
        if (armas.first) {
            cout << "Arma 1: " << armas.first->getNombre()
                << " (Rareza: " << Rarezas::getNombreRareza(armas.first->getRareza()) << ")"
                << " -> Compatibilidad: " << (personaje->compatibilidad(armas.first.get()) ? "Sí" : "No") << endl;
        } else {
            cout << "Arma 1: No equipada" << endl;
        }

        // Validar y mostrar el arma 2
        if (armas.second) {
            cout << "Arma 2: " << armas.second->getNombre()
                << " (Rareza: " << Rarezas::getNombreRareza(armas.second->getRareza()) << ")"
                << " -> Compatibilidad: " << (personaje->compatibilidad(armas.second.get()) ? "Sí" : "No") << endl;
        } else {
            cout << "Arma 2: No equipada" << endl;
        }

        cout << "===========================\n" << endl;
    }
}