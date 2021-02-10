#ifndef REFUGIO_H
#define REFUGIO_H

#include "ilha.h"

class Refugio : public Ilha {
    static int count;
    
public:
    Refugio() : Ilha(9, "refugio" + to_string(count++), 1, 0) {}

    virtual Refugio* clone() { return new Refugio(*this); }
};

#endif /* REFUGIO_H */

