#ifndef TERR_INICIAL_H
#define TERR_INICIAL_H

#include "territorio.h"

class Terr_Inicial : public Territorio {
    const int pontos = 0;
    
public:
    Terr_Inicial() : Territorio(9, "territorio_inicial", 1, 1) {}
    
    virtual int getPontos() const { return pontos; }

    virtual Terr_Inicial* clone() { return new Terr_Inicial(*this); }
};

#endif /* TERR_INICIAL_H */

