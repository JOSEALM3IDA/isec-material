#ifndef DUNA_H
#define DUNA_H

#include "continente.h"

class Duna : public Continente {
    static int count;
    
public:
    Duna() : Continente(4, "duna" + to_string(count++), 0, 1) {}

    virtual Duna* clone() { return new Duna(*this); }
};

#endif /* DUNA */

