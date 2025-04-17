#include <iostream>
#include <memory>
#include "Headers/Personajes/Hechicero.hpp"
#include "Headers/Personajes/Barbaro.hpp"
#include "Headers/Armas/Espada.hpp"
#include "Headers/Armas/Amuleto.hpp"
#include "Headers/Efectos/EfectosDmg.hpp"
#include "Headers/Efectos/EfectosSupport.hpp"
#include "Utilities/rangos.hpp"
#include "Utilities/rarezas.hpp"

using namespace std;

int main() {

    // Crear personajes
    shared_ptr<InterfazDePersonaje> mago = make_shared<Hechicero>(Rango::AVANZADO);
    shared_ptr<InterfazDePersonaje> guerrero = make_shared<Barbaro>(Rango::EXPERTO);

    // Crear armas
    unique_ptr<InterfazArma> armaCombate = make_unique<Espada>(Rareza::POCO_COMUN);
    unique_ptr<InterfazArma> armaMagica = make_unique<Amuleto>(Rareza::LEGENDARIO);

    // Crear efectos
    shared_ptr<InterfazDeEfecto> efecto1 = make_shared<Sangrado>();
    shared_ptr<InterfazDeEfecto> efecto2 = make_shared<Sobrecarga>();
    shared_ptr<InterfazDeEfecto> efecto3 = make_shared<ReduccionDeDano>();

    // Asignar armas
    mago->setArmas({std::move(armaMagica), nullptr});
    guerrero->setArmas({std::move(armaCombate), nullptr});

    // Mostrar información
    cout << "========== PERSONAJES ==========\n";
    mago->mostrarInfo();
    cout << endl;
    guerrero->mostrarInfo();

    cout << "\n========== ARMAS ==========\n";
    mago->getArmas().first->mostrarInfo();
    cout << endl;
    
    cout << endl;
    guerrero->getArmas().first->mostrarInfo();

    cout << "\n========== EFECTOS ==========\n";
    cout << efecto1->getNombre() << endl;
    cout << efecto2->getNombre() << endl;
    cout << efecto3->getNombre() << endl;

    return 0;
}
