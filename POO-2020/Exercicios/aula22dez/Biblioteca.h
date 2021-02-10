#pragma once

#include <vector>

#include "Livro.h"

class Biblioteca {
   std::vector<Livro*> v;
public:
    Biblioteca() = default;
    Biblioteca (const Biblioteca& ref);

    ~Biblioteca();
  
    bool addLivro(Livro* p);
    
    bool eliminaLivro(std::string x);
    
    std::string getAsString() const;

    Biblioteca& operator=(const Biblioteca& dir);
};

std::ostream& operator<<(std::ostream& out, const Biblioteca& b);
