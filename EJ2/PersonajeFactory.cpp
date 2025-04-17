#include "PersonajeFactory.hpp"

#include "../EJ1/Headers/Personajes/Hechicero.hpp"
#include "../EJ1/Headers/Personajes/Brujo.hpp"
#include "../EJ1/Headers/Personajes/Conjurador.hpp"
#include "../EJ1/Headers/Personajes/Nigromante.hpp"
#include "../EJ1/Headers/Personajes/Barbaro.hpp"
#include "../EJ1/Headers/Personajes/Caballero.hpp"
#include "../EJ1/Headers/Personajes/Paladin.hpp"
#include "../EJ1/Headers/Personajes/Mercenario.hpp"
#include "../EJ1/Headers/Personajes/Gladiador.hpp"

#include "../EJ1/Headers/Armas/Amuleto.hpp"
#include "../EJ1/Headers/Armas/Baston.hpp"
#include "../EJ1/Headers/Armas/LibroDeHechizos.hpp"
#include "../EJ1/Headers/Armas/Pocion.hpp"
#include "../EJ1/Headers/Armas/Espada.hpp"
#include "../EJ1/Headers/Armas/Hacha.hpp"
#include "../EJ1/Headers/Armas/HachaDoble.hpp"
#include "../EJ1/Headers/Armas/Lanza.hpp"
#include "../EJ1/Headers/Armas/Garrote.hpp"

#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

// Crear un personaje con nombre y rango
shared_ptr<InterfazDePersonaje> PersonajeFactory::crearPersonaje(const string& nombre, Rango rango) {
    if (nombre == "Hechicero") return make_shared<Hechicero>(rango);
    if (nombre == "Brujo") return make_shared<Brujo>(rango);
    if (nombre == "Conjurador") return make_shared<Conjurador>(rango);
    if (nombre == "Nigromante") return make_shared<Nigromante>(rango);
    if (nombre == "Barbaro") return make_shared<Barbaro>(rango);
    if (nombre == "Caballero") return make_shared<Caballero>(rango);
    if (nombre == "Paladin") return make_shared<Paladin>(rango);
    if (nombre == "Mercenario") return make_shared<Mercenario>(rango);
    if (nombre == "Gladiador") return make_shared<Gladiador>(rango);

    throw invalid_argument("Nombre de personaje no válido: " + nombre);
}

// Crear un arma con nombre y rareza
unique_ptr<InterfazArma> PersonajeFactory::crearArma(const string& nombre, Rareza rareza) {
    if (nombre == "Amuleto") return make_unique<Amuleto>(rareza);
    if (nombre == "Baston") return make_unique<Baston>(rareza);
    if (nombre == "LibroDeHechizos") return make_unique<LibroDeHechizos>(rareza);
    if (nombre == "Pocion") return make_unique<Pocion>(rareza);
    if (nombre == "Espada") return make_unique<Espada>(rareza);
    if (nombre == "Hacha") return make_unique<Hacha>(rareza);
    if (nombre == "HachaDoble") return make_unique<HachaDoble>(rareza);
    if (nombre == "Lanza") return make_unique<Lanza>(rareza);
    if (nombre == "Garrote") return make_unique<Garrote>(rareza);

    throw invalid_argument("Nombre de arma no válido: " + nombre);
}

// Crear un personaje armado con nombre, rango y armas aleatorias
shared_ptr<InterfazDePersonaje> PersonajeFactory::crearPersonajeArmado(const string& nombre, Rango rango) {
    auto personaje = crearPersonaje(nombre, rango);

    int cantidad_armas = rand() % 3; // 0, 1 o 2
    unique_ptr<InterfazArma> arma1 = nullptr;
    unique_ptr<InterfazArma> arma2 = nullptr;

    vector<string> nombresArmas = {
        "Amuleto", "Baston", "LibroDeHechizos", "Pocion",
        "Espada", "Hacha", "HachaDoble", "Lanza", "Garrote"
    };

    if (cantidad_armas >= 1)
        arma1 = crearArma(nombresArmas[rand() % nombresArmas.size()], Rareza(rand() % 5));
    if (cantidad_armas == 2)
        arma2 = crearArma(nombresArmas[rand() % nombresArmas.size()], Rareza(rand() % 5));

    personaje->setArmas({std::move(arma1), std::move(arma2)});
    return personaje;
}