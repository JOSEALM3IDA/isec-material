#include "Piranha.h"

Piranha::Piranha(string a, string b) : Peixe(a, b) {}

void Piranha::comer(int qtd) {
    setPeso(getPeso() + 2 * qtd);
}