#ifndef PESCARIA_H
#define PESCARIA_H

#include "ilha.h"

class Pescaria : public Ilha {
    static int count;
    
public:
    Pescaria() : Ilha(9, "pescaria" + to_string(count++), 0, 2) {}
    
    virtual errcode atualizar(int turno);

    virtual Pescaria* clone() { return new Pescaria(*this); }
};

#endif /* PESCARIA_H */

