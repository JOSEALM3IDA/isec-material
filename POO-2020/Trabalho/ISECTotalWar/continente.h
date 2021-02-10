#ifndef CONTINENTE_H
#define CONTINENTE_H

#include "territorio.h"

class Continente : public Territorio {
    const int pontos = 2;

public:
    Continente(int r, string n, int po, int pp) : Territorio(r, n, po, pp) {}

    virtual int getPontos() const { return pontos; }
};

#endif /* CONTINENTE_H */

