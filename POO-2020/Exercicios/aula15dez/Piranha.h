#ifndef PIRANHA_H
#define PIRANHA_H

#include "Peixe.h"
#include "randomgen.h"

using namespace std;

class Piranha: public Peixe { // Classe derivada. Métodos public do peixe são métodos public da piranha

public:
    Piranha(string a, string b);

    virtual void comer(int qtd);
};

#endif /* PIRANHA_H */

