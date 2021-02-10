#ifndef CONTA_H
#define CONTA_H

#include <string>
#include <iostream>
#include "pessoa.h"

class Conta {
    float saldo;
    Pessoa *titular;

public:
    Conta (Pessoa *t, int a = 0)
    : saldo(a), titular(t) {}

    bool variarSaldo(int a);
    bool trocarTitular(Pessoa *t);

    std::string getAsString() const;

    Pessoa* getTitular() const;
};


#endif