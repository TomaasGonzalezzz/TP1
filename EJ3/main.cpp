#include "main.hpp"
#include "../EJ2/PersonajeFactory.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

vector<string> nombresPersonajes = {
    "Barbaro", "Caballero", "Mercenario", "Paladin", "Gladiador",
    "Nigromante", "Conjurador", "Hechicero", "Brujo"
};

vector<string> nombresArmas = {
    "Espada", "Hacha", "Lanza", "HachaDoble", "Garrote",
    "Amuleto", "Baston", "LibroDeHechizos", "Pocion"
};

bool entradaCorrecta() {
    if (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menuPersonajes() {
    cout << "\nElige tu personaje:\n";
    for (size_t i = 0; i < nombresPersonajes.size(); ++i)
        cout << i << ") " << nombresPersonajes[i] << '\n';
}

void menuArmas() {
    cout << "\nSelecciona un arma:\n";
    for (size_t i = 0; i < nombresArmas.size(); ++i)
        cout << i << ") " << nombresArmas[i] << '\n';
}

void menuGolpes() {
    cout << "(0) Golpe Fuerte | (1) Golpe Rapido | (2) Defenza y Golpe\n";
}

EstiloGolpe elegirGolpe() {
    int opcion;
    while (true) {
        menuGolpes();
        cout << "Tu elección: ";
        cin >> opcion;
        if (entradaCorrecta() && opcion >= 0 && opcion <= 2)
            return static_cast<EstiloGolpe>(opcion);
        cout << "Entrada inválida. Intentá de nuevo.\n";
    }
}

EstiloGolpe golpeAleatorioCPU() {
    return static_cast<EstiloGolpe>(rand() % 3);
}

string descripcionGolpe(EstiloGolpe golpe) {
    switch (golpe) {
        case EstiloGolpe::GOLPE_FUERTE: return "Golpe Fuerte";
        case EstiloGolpe::GOLPE_RAPIDO: return "Golpe Rapido";
        case EstiloGolpe::DEFENZA_Y_GOLPE: return "Contraaque";
        default: return "???";
    }
}

int elegirPersonaje() {
    int opcion;
    while (true) {
        menuPersonajes();
        cout << "Tu elección (0-" << nombresPersonajes.size() - 1 << "): ";
        cin >> opcion;
        if (entradaCorrecta() && opcion >= 0 && opcion < (int)nombresPersonajes.size())
            return opcion;
        limpiarPantalla();
        cout << "Opción no válida.\n";
    }
}

int elegirArma() {
    int opcion;
    while (true) {
        menuArmas();
        cout << "Tu elección (0-" << nombresArmas.size() - 1 << "): ";
        cin >> opcion;
        if (entradaCorrecta() && opcion >= 0 && opcion < (int)nombresArmas.size())
            return opcion;
        limpiarPantalla();
        cout << "Opción no válida.\n";
    }
}

string barraDeVida(int hp) {
    string barra = "[";
    for (int i = 0; i < 10; i++) {
        barra += (i < hp / 10) ? "♥" : " ";
    }
    barra += "] " + to_string(hp) + "/100";
    return barra;
}

void mostrarEstado(const shared_ptr<InterfazDePersonaje>& pj1, const shared_ptr<InterfazDePersonaje>& pj2, int hp1, int hp2) {
    cout << "\n===== ESTADO DEL DUELO =====\n";
    cout << pj1->getNombre() << " con " 
         << (pj1->getArmas().first ? pj1->getArmas().first->getNombre() : "Sin arma") 
         << ": " << barraDeVida(hp1) << '\n';
    cout << pj2->getNombre() << " con " 
         << (pj2->getArmas().first ? pj2->getArmas().first->getNombre() : "Sin arma") 
         << ": " << barraDeVida(hp2) << '\n';
    cout << "=============================\n";
}

void ejecutarCombate(shared_ptr<InterfazDePersonaje>& pj1, shared_ptr<InterfazDePersonaje>& pj2) {
    int hp1 = 100, hp2 = 100, turno = 1;

    int reglas[3][3] = {
        {0, 1, 2},
        {2, 0, 1},
        {1, 2, 0}
    };

    while (hp1 > 0 && hp2 > 0) {
        limpiarPantalla();
        mostrarEstado(pj1, pj2, hp1, hp2);
        cout << "\n--- Turno " << turno << " ---\n";

        EstiloGolpe golpeJugador = elegirGolpe();
        EstiloGolpe golpeRival = golpeAleatorioCPU();

        cout << pj1->getNombre() << " ataca con: " << descripcionGolpe(golpeJugador) << '\n';
        cout << pj2->getNombre() << " responde con: " << descripcionGolpe(golpeRival) << '\n';

        int resultado = reglas[(int)golpeJugador][(int)golpeRival];
        if (resultado == 0)
            cout << "Ambos ataques se anulan. Sin daño.\n";
        else if (resultado == 1) {
            hp2 -= 10;
            cout << pj1->getNombre() << " conecta el ataque. " << pj2->getNombre() << " pierde 10 HP.\n";
        } else {
            hp1 -= 10;
            cout << pj2->getNombre() << " logra golpear. " << pj1->getNombre() << " recibe 10 de daño.\n";
        }

        turno++;
        cout << "\n[Presioná ENTER para seguir]";
        cin.ignore(); cin.get();
    }

    cout << "\n=== FIN DEL COMBATE ===\n";
    if (hp1 > 0) cout << "¡" << pj1->getNombre() << " gana el duelo!\n";
    else cout << "¡" << pj2->getNombre() << " es el vencedor!\n";
}
int main() {
    srand(time(0));
    limpiarPantalla();
    cout << "=== SIMULADOR DE COMBATE ===\n";

    // Elección del jugador
    int idxPj = elegirPersonaje();
    int idxArma = elegirArma();

    // Crear el arma del jugador
    string nombreArmaJugador = nombresArmas[idxArma];
    unique_ptr<InterfazArma> armaJugador = PersonajeFactory::crearArma(nombreArmaJugador, Rareza::COMUN);
    pair<unique_ptr<InterfazArma>, unique_ptr<InterfazArma>> armasJugador;
    armasJugador.first = std::move(armaJugador);
    armasJugador.second = nullptr;

    // Crear el personaje del jugador
    string nombrePjJugador = nombresPersonajes[idxPj];
    auto pjJugador = PersonajeFactory::crearPersonajeArmado(nombrePjJugador, Rango::NOVATO);

    // Generación aleatoria del rival
    int idxPjRival = rand() % nombresPersonajes.size();
    int idxArmaRival = rand() % nombresArmas.size();

    // Crear el arma del rival
    string nombreArmaRival = nombresArmas[idxArmaRival];
    unique_ptr<InterfazArma> armaRival = PersonajeFactory::crearArma(nombreArmaRival, Rareza::COMUN);
    pair<unique_ptr<InterfazArma>, unique_ptr<InterfazArma>> armasRival;
    armasRival.first = std::move(armaRival);
    armasRival.second = nullptr;

    // Crear el personaje del rival
    string nombrePjRival = nombresPersonajes[idxPjRival];
    auto pjRival = PersonajeFactory::crearPersonajeArmado(nombrePjRival, Rango::NOVATO);

    // Ejecutar el combate
    ejecutarCombate(pjJugador, pjRival);
    return 0;
}
