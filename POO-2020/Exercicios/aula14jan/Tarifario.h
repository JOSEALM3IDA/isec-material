#ifndef TARIFARIO_H
#define TARIFARIO_H

class Tarifario {
   
public:
    
    virtual ~Tarifario() {}
    
    virtual bool autoriza(int val) = 0;
    
    virtual int calculaPreco(int minutos) = 0;
    
    virtual bool carregaValor(float& valor) = 0;

    virtual Tarifario* clone() = 0;
};

#endif /* TARIFARIO_H */

