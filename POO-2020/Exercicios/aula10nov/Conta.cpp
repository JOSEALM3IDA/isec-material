#include "conta.h"

using namespace std;

bool Conta::variarSaldo(int a) {
    if (saldo + a < 0)
        return false;
    else {
        saldo += a;
    
        return true;
    }
}

string Conta::getAsString() const {
    stringstream ss;

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