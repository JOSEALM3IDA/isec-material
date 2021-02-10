#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <sstream>

#include "Tarifario.h"

class Cliente {
    std::string nome;
    int cc, start;
    Tarifario *t;
    bool emTreino = false;
    
public:
    Cliente(std::string a, int b, Tarifario* c) : nome(a), cc(b), t(c) {}
    Cliente(const Cliente& ref);
 
    virtual ~Cliente() { delete t; }
    
    void iniciaTreino(int x);
    void terminaTreino(int x);

    int paga() { return t->calculaPagamento(); }

    std::string getAsString() const;

    Cliente& operator=(const Cliente& dir);
};

std::ostream& operator<<(std::ostream& out, const Cliente& c);

#endif /* CLIENTE_H */

