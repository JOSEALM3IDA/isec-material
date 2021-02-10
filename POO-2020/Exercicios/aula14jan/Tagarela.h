#ifndef TAGARELA_H
#define TAGARELA_H

#include "Tarifario.h"

class Tagarela: public Tarifario {
   
public:
    
    bool autoriza(int val) { return val > -0.5 ? true : false; }
    
    int calculaPreco(int minutos) { return minutos > 0 ? 0.5 + (minutos - 1) * 0.02 : 0; }
    
    bool carregaValor(float& valor);

    virtual Tagarela* clone() { return new Tagarela(*this); }
};

#endif /* TAGARELA_H */

