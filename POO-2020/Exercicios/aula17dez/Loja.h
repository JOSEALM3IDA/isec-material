#pragma once

#include "Imovel.h"

class Loja : public Imovel {
    
public:
    Loja(int a) : Imovel(a, 0, a * 15) {}
    ~Loja() { std::cout << "D " << getID() << std::endl; }
    
    virtual std::string getID() const{ return "L" + std::to_string(getCodigo()); }

};

