#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include "Livro.h"

class Policial : public Livro {
    std::string nomeDet;
    int nTiros;

public:
    Policial(std::string a, std::string b, std::string c, std::string d, int e) : Livro(a, b, c), nomeDet(d), nTiros(e) {}
    
    virtual ~Policial() {}
    
    virtual std::string getAsString() const;

    virtual Policial* clone() { return new Policial(*this); }
};