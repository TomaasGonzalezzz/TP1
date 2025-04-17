#ifndef LIBRODEHECHIZOS_HPP
#define LIBRODEHECHIZOS_HPP

#include "ArmaMagica.hpp"

class LibroDeHechizos : public ArmaMagica {
public:
    LibroDeHechizos(Rareza rareza);

    void mostrarInfo() const override;
    void usar(std::shared_ptr<InterfazDePersonaje> personaje, std::shared_ptr<InterfazDePersonaje> rival) override;

    void recuperacion(std::shared_ptr<InterfazDePersonaje> personaje);
};

#endif
