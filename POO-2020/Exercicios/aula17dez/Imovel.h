#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Imovel {
    int codigo;
    int area, andar, preco;
    static int conta;
public:
    Imovel(int a, int b, int c) : area(a), andar(b), preco(c), codigo(conta++) {}
    virtual ~Imovel() { std::cout << "D " << getID() << std::endl; }
    
    int getCodigo() const { return codigo; }
    
    virtual std::string getID() const { return "IM" + std::to_string(getCodigo()); }
    
    virtual std::string getAsString() const;
};

std::ostream& operator<<(std::ostream& out, const Imovel& a);

