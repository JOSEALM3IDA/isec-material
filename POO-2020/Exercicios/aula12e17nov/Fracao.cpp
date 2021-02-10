
#include "Fracao.h"
#include <iostream>

Fracao operator*(const Fracao& a, const Fracao& b) { // Passado por referencia para evitar copias desnecessarias. const por razoes de seguranca
    Fracao x;

    x.setNum(a.getNum() * b.getNum());
    x.setDen(a.getDen() * b.getDen());

    return x;
}

Fracao& Fracao::operator*=(const Fracao& b) {
    setNum(getNum() * b.getNum());
    setDen(getDen() * b.getDen());

    return *this;
};

Fracao& Fracao::operator++() { // ++x
    num += den;
    return *this;
}

const Fracao Fracao::operator++(int) { // x++
    Fracao temp = *this;
    num += den;
    return temp;
}

ostream& operator<<(ostream& out, const Fracao& a) {
    out << a.getAsString();

    return out;
}

bool operator==(const Fracao a, const Fracao b) { return a.getNum()/a.getDen() == b.getNum()/b.getDen(); }

bool operator<(const Fracao a, const Fracao b) { return a.getNum()/a.getDen() < b.getNum()/b.getDen(); }

bool operator>(const Fracao a, const Fracao b) { return !(a < b || a == b); }

bool operator<=(const Fracao a, const Fracao b) { return !(a > b); }

bool operator>=(const Fracao a, const Fracao b) { return !(a < b); }

bool operator!=(const Fracao a, const Fracao b) { return !(a == b); }