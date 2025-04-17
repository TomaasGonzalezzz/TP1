#include "../../Headers/Personajes/Nigromante.hpp"
#include "../../Utilities/rangos.hpp"

Nigromante::Nigromante(Rango rango)
    : Mago("Nigromante", rango, 105, 120, 65, {nullptr, nullptr}) {
    this->clase = "Mago";
}

void Nigromante::invocarEspectro(std::shared_ptr<InterfazDePersonaje> rival) {
    if (mana < 30) {
        std::cout << nombre << " no tiene suficiente mana." << std::endl;
        return;
    }

    this->consumirMana(30);
    rival->recibirDmg(20);
    propagarEfecto(Efecto::ENVENENADO, rival);

    std::cout << nombre << " invoca un Espectro: daña y envenena a " << rival->getNombre() << std::endl;
}

void Nigromante::ritualCaidos() {
    if (mana < 20) {
        std::cout << nombre << " no tiene suficiente mana." << std::endl;
        return;
    }

    this->consumirMana(20);
    this->curarVida(40);

    std::cout << nombre << " realiza el Ritual de los Caídos: recupera 40 de vida." << std::endl;
}

void Nigromante::mostrarInfo() const {
    std::cout << "Nombre: " << nombre << "\nClase: " << clase
              << "\nRango: " << Rangos::getNombreRango(rango) << "\nVida: " << vida
              << "\nMana: " << mana << "\nResistencia: " << resistencia
              << "\nHabilidades: Invocar Espectro, Ritual de los Caídos" << std::endl;
}
