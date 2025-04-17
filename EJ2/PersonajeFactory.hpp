#ifndef PERSONAJEFACTORY_HPP
#define PERSONAJEFACTORY_HPP

#include "../EJ1/Headers/Personajes/InterfazPersonajes.hpp"
#include "../EJ1/Headers/Armas/InterfazArma.hpp"
#include "../EJ1/Utilities/rangos.hpp"
#include "../EJ1/Utilities/rarezas.hpp"
#include <memory>
#include <string>

class PersonajeFactory {
public:
    static std::shared_ptr<InterfazDePersonaje> crearPersonaje(const std::string& nombre, Rango rango);
    static std::unique_ptr<InterfazArma> crearArma(const std::string& nombre, Rareza rareza);
    static std::shared_ptr<InterfazDePersonaje> crearPersonajeArmado(const std::string& nombre, Rango rango);
};

#endif

