#ifndef SOCIAVEL_H
#define SOCIAVEL_H

#include "Cliente.h"
#include "Ginasio.h"

class Sociavel: public Cliente {
    
public:
    
    Sociavel(std::string a, int b, Tarifario* c) : Cliente(a, b, c){}
    
    virtual void reageEntrada();      // OK
    virtual void reageSaida();        // Se ficou sozinho, vai-se embora

    virtual Sociavel* clone() { return new Sociavel(*this); }
};

#endif /* SOCIAVEL_H */

