#ifndef RETANGULO_H
#define RETANGULO_H

#include <sstream>
#include "Ponto.h"

using namespace std;

class Retangulo {
    Ponto cse;
    int larg, alt;

    public:

    Retangulo(Ponto a, int b, int c) : cse(a), larg(b), alt(c) {}

    string getAsString() const;

    float getArea() const { return larg * alt; }
};

#endif /* RETANGULO_H */