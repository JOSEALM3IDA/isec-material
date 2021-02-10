#include "conta.h"

bool Conta::variarSaldo(int a) {
    if (saldo + a < 0)
        return 0;
    else {
        saldo += a;
    
        return 1;
    }
}

std::string Conta::getAsString() const {
    std::stringstream ss;

    ss << "Titular: " << (*titular).getNome() << "\tSaldo: " << saldo;

    return ss.str();
}

Pessoa* Conta::getTitular() const {
    return titular;
}

bool Conta::trocarTitular(Pessoa *t) {
    Pessoa *temp = titular;

    titular = t;

    if (titular != NULL)
        return 1;
    else {
        titular = temp;

        return 0;
    }  
}