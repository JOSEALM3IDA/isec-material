#ifndef PEIXE_H
#define PEIXE_H

#include <string>
#include <iostream>
#include <sstream>

#include "randomgen.h"

class Aquario; // Avisar que existe. No Peixe.h, nao podemos usar qualquer metodo / campo do Aquario

using namespace std;

class Peixe {
    string nome, cor;
    int peso;
    int id;
    static int conta;
    Aquario *aq;
    bool isAlive = true;

public:
    Peixe(string a, string b = "Cinzento");

    Peixe (const Peixe& ref);

    virtual ~Peixe();

    string getNome() const;
    int getPeso() const { return peso; }
    string getCor() const;
    int getID() const;

    void setPeso(int p) { peso = p; }

    void setAq(Aquario *a);
    
    string getAsString() const;

    bool isDead() const { return !isAlive; }
   
    virtual void comer(int qtd); // Cada peixe atualiza o seu peso
};

ostream& operator<<(ostream& out, const Peixe& a);

#endif /* PEIXE_H */

