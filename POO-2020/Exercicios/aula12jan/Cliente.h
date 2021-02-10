#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <sstream>

#include "Tarifario.h"

class Ginasio;

class Cliente {
    std::string nome;
    int cc, start;
    Tarifario *t;
    bool emTreino = false;
    Ginasio* g = nullptr;
    
public:
    Cliente(std::string a, int b, Tarifario* c) : nome(a), cc(b), t(c) {}
    Cliente(const Cliente& ref);
 
    virtual ~Cliente() { delete t; }

    void ligaGin(Ginasio* gptr);

    Ginasio* getG() { return g; }
    int getCC() { return cc; }
    
    bool iniciaTreino(int x);
    bool terminaTreino(int x);

    int paga() { return t->calculaPagamento(); }

    virtual void reageEntrada() = 0;
    virtual void reageSaida() = 0;

    std::string getAsString() const;

    virtual Cliente* clone() = 0;

    Cliente& operator=(const Cliente& dir);
};

std::ostream& operator<<(std::ostream& out, const Cliente& c);

#endif /* CLIENTE_H */

