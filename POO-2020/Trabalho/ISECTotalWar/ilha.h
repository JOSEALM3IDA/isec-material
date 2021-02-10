#ifndef ILHA_H
#define ILHA_H

#include "territorio.h"

class Ilha : public Territorio {
    const int pontos = 3;

public:
    Ilha(int r, string n, int po, int pp) : Territorio(r, n, po, pp) {}

    virtual int getPontos() const { return pontos; }
};

#endif /* ILHA_H */

