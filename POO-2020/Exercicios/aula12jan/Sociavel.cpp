#include "Sociavel.h"

void Sociavel::reageEntrada() {}

void Sociavel::reageSaida() {
    Ginasio* g = Cliente::getG();
    if (g->getATreinar() == 1) {
        g->registaSaida(Cliente::getCC());
    }
}