#ifndef CONTA_H
#define CONTA_H

#include <string>
#include <iostream>
#include "Pessoa.h"

using namespace std;

class Conta {
    float saldo;
    Pessoa *titular;

public:
    Conta (Pessoa *t, int a = 0)
    : saldo(a), titular(t) {}

    bool variarSaldo(int a);
    bool trocarTitular(Pessoa *t);

    string getAsString() const;

    Pessoa* getTitular() const;

    float getSaldo() const {return saldo;}
};


#endif