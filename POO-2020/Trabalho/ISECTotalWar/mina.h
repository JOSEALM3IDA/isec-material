#ifndef MINA_H
#define MINA_H

#include "continente.h"

class Mina : public Continente {
    static int count;
    
public:
    Mina() : Continente(5, "mina" + to_string(count++), 1, 0) {}
    
    virtual errcode atualizar(int turno);

    virtual Mina* clone() { return new Mina(*this); }
};

#endif /* MINA_H */

