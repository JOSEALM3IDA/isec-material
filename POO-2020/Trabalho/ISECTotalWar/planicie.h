#ifndef PLANICIE_H
#define PLANICIE_H

#include "continente.h"

class Planicie : public Continente {
    static int count;
    
public:
    Planicie() : Continente(5, "planicie" + to_string(count++), 1, 1) {}
    
    virtual errcode atualizar(int turno);

    virtual Planicie* clone() { return new Planicie(*this); }
};

#endif /* PLANICIE_H */

