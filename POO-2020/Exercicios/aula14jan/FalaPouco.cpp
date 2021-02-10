#include "FalaPouco.h"
#include <random>

bool FalaPouco::carregaValor(float& valor) {
    if (valor < 10)
        return false;

    float chance = ((float)rand()) / RAND_MAX;
    valor = chance < 0.2 ? valor * 2 : valor;
    return true;
}