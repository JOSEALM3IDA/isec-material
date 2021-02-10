#ifndef FALAPOUCO_H
#define FALAPOUCO_H

#include "Tarifario.h"

class FalaPouco: public Tarifario {
   
public:
    
    bool autoriza(int val) { return val > -(0.25 * 10) ? true : false; }
    
    int calculaPreco(int minutos) { return minutos > 0 ? minutos * 0.25 : 0; }
    
    bool carregaValor(float& valor);

    virtual FalaPouco* clone() { return new FalaPouco(*this); }
};

#endif /* FALAPOUCO_H */

