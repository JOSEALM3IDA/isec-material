#ifndef MONTANHA_H
#define MONTANHA_H

#include "continente.h"

class Montanha : public Continente {
    static int count;
    
public:
    Montanha() : Continente(6, "montanha" + to_string(count++), 0, 0) {}
    
    virtual errcode atualizar(int turno);

    virtual Montanha* clone() { return new Montanha(*this); }
};

#endif /* MONTANHA_H */

