#ifndef BATALLA_SIMULADOR_HPP
#define BATALLA_SIMULADOR_HPP

#include <string>
#include "../EJ1/Headers/Personajes/InterfazPersonajes.hpp"

// Opciones de combate
enum class EstiloGolpe { GOLPE_FUERTE, GOLPE_RAPIDO, DEFENZA_Y_GOLPE };

// Declaración de funciones del simulador
bool entradaCorrecta();
void limpiarPantalla();
void menuPersonajes();
void menuArmas();
void menuGolpes();
EstiloGolpe elegirGolpe();
EstiloGolpe golpeAleatorioCPU();
std::string descripcionGolpe(EstiloGolpe golpe);
int elegirPersonaje();
int elegirArma();
std::string barraDeVida(int hp);
void mostrarEstado(const shared_ptr<InterfazDePersonaje>& pj1, const shared_ptr<InterfazDePersonaje>& pj2, int hp1, int hp2);
void ejecutarCombate(shared_ptr<InterfazDePersonaje>& pj1, shared_ptr<InterfazDePersonaje>& pj2);

#endif
