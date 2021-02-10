#pragma once

#include <string>
#include <sstream>
#include <iostream>

class Livro {
    std::string titulo, autor, isbn;
public:
    Livro(std::string a, std::string b, std::string c) : titulo(a), autor(b), isbn(c) {}
    
    virtual ~Livro() { std::cout << "D " << titulo << std::endl; }
    
    std::string getISBN() const { return isbn; }
    
    bool operator==(const Livro& r) { return isbn == r.isbn; }
    
    virtual std::string getAsString() const;

    virtual Livro* clone() { return new Livro(*this); }
};

std::ostream& operator<<(std::ostream& out, const Livro& l);