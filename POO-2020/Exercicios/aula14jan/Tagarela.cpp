#include "Tagarela.h"

bool Tagarela::carregaValor(float& valor) {
    if (valor < 25)
        return false;

    valor = valor < 50 ? valor : valor + 5;
    return true;
}