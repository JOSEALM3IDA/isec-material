#include "Movimento.h"
#include <iostream>

string Movimentos::getAsString() const {
    ostringstream os;

    os << "nome: " << nome << " saldo: " << saldo << " v:";

    for(int num : v)
        os << " " << num; 

    return os.str();
}

Movimentos Movimentos::operator+(int val) const {
    Movimentos temp = *this;

    temp.setSaldo(saldo + val);
    temp.v.push_back(val);

    return temp;
}

Movimentos Movimentos::operator-(int val) const {
    Movimentos temp = *this;

    if (saldo - val >= 0) {
        temp.setSaldo(saldo - val);
        temp.v.push_back(-val);
    }

    return temp;
}

Movimentos& Movimentos::operator+=(int val) {
    saldo += val;
    v.push_back(val);
    return *this;
}

bool operator==(const Movimentos a, const Movimentos b) { return a.getSaldo() == b.getSaldo(); }

ostream& operator<<(ostream& out, const Movimentos& a) {
    out << a.getAsString();

    return out;
}