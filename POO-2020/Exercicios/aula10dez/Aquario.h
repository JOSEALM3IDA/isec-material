#ifndef AQUARIO_H
#define AQUARIO_H

#include <vector>
#include <iostream>

#include "Peixe.h"

using namespace std;

class Aquario {
    string nome;
    vector<Peixe*> v;

public:
    Aquario(string a);

    Aquario(const Aquario& ref, string novoNome);

    ~Aquario();

    string getNome() const;
    
    bool addPeixe(Peixe *p);
    
    string getAsString() const;
    
    bool existePeixe(int num) const;

    Aquario& operator=(const Aquario& dir);
};

ostream& operator<<(ostream& out, const Aquario& a);

#endif /* AQUARIO_H */

