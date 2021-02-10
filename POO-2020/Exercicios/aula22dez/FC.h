#pragma once

#include <string>
#include <sstream>
#include <iostream>

#include "Livro.h"

class FC : public Livro {
    std::string planeta;
    int ano;
    bool isRealista;
public:
    FC(std::string a, std::string b, std::string c, std::string d, int e) : Livro(a, b, c), planeta(d), ano(e) { isRealista = false; }
    
    virtual ~FC() {}
    
    virtual std::string getAsString() const;

    virtual FC* clone() { return new FC(*this); }
};