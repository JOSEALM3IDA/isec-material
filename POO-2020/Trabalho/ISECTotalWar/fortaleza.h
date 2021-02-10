#ifndef FORTALEZA_H
#define FORTALEZA_H

#include "continente.h"

class Fortaleza : public Continente {
    static int count;
    
public:
    Fortaleza() : Continente(8, "fortaleza" + to_string(count++), 0, 0) {}

    virtual Fortaleza* clone() { return new Fortaleza(*this); }
};

#endif /* FORTALEZA_H */

