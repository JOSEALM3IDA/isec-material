#ifndef FIXO_H
#define FIXO_H

#include "Tarifario.h"

class Fixo: public Tarifario {
public:

    virtual ~Fixo() {}

    virtual int calculaPagamento();

    virtual Fixo* clone() { return new Fixo(*this); }
};

#endif /* FIXO_H */

