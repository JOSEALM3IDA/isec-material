#pragma once

#include "Imovel.h"

class Apartamento : public Imovel {
    int quartos;
public:
    Apartamento(int a, int b, int n) : Imovel(a, b, a * 10), quartos(n) {}
    ~Apartamento() { std::cout << "D " << getID() << std::endl; }

    virtual std::string getID() const { return "AP" + std::to_string(getCodigo()); }

    virtual std::string getAsString() const;
};
