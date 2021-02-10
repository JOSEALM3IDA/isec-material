#ifndef CASTELO_H
#define CASTELO_H

#include "continente.h"

class Castelo : public Continente {
    static int count;
    
public:
    Castelo() : Continente(7, "castelo" + to_string(count++), 1, 0) {}
    
    virtual errcode atualizar(int turno);

    virtual Castelo* clone() { return new Castelo(*this); }
};

#endif /* CASTELO_H */

