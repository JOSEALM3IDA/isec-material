#ifndef PEIXE_H
#define PEIXE_H

#include <string>
#include <iostream>
#include <sstream>

class Aquario; // Avisar que existe. No Peixe.h, nao podemos usar qualquer metodo / campo do Aquario

using namespace std;

class Peixe {
    string nome, cor;
    int peso;
    int id;
    static int conta;
    const Aquario *aq;

public:
    Peixe(string a, string b = "Cinzento");

    Peixe (const Peixe& ref);

    virtual ~Peixe();

    string getNome() const;

    string getCor() const;

    int getID() const;

    void setAq(Aquario *a);
    
    string getAsString() const;
   
};

ostream& operator<<(ostream& out, const Peixe& a);

#endif /* PEIXE_H */

