#ifndef APRESSADO_H
#define APRESSADO_H

#include "Tarifario.h"

class Apressado: public Tarifario {
public:

    virtual ~Apressado() {}

    virtual int calculaPagamento();

    virtual Apressado* clone() { return new Apressado(*this); }
};

#endif /* APRESSADO_H */

