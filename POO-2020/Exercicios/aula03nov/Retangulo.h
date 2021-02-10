#ifndef RETANGULO_H
#define RETANGULO_H

#include <sstream>
#include <vector>
#include "Ponto.h"

using namespace std;

class Retangulo {
    Ponto cse;
    int larg, alt;

    public:

    Retangulo(Ponto a, int b, int c) : cse(a), larg(b), alt(c) {}

    string getAsString() const;

    float getArea() const { return larg * alt; }

    Ponto getCSE() const { return cse; }

    Ponto getCSD() const { return (cse.getX() + larg, cse.getY()); }

    Ponto getCIE() const { return (cse.getX(), cse.getY() - alt); }

    Ponto getCID() const { return (cse.getX() + larg, cse.getY() - alt); }

    vector<Ponto> getVertices() const;

    bool isSobreposto(Retangulo r2) const;

    bool hasInside(Ponto p) const;
};

#endif /* RETANGULO_H */