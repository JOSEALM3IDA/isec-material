#pragma once

#include <vector>
#include <iostream>

#include "Imovel.h"

class Imobiliaria {
    std::string nome;
    std::vector<Imovel*> v;
public:
    Imobiliaria(std::string s) : nome(s) {}
    
    void addImovel(Imovel *p);
    
    std::string getAsString() const;
};

std::ostream& operator<<(std::ostream& out, const Imobiliaria& a);