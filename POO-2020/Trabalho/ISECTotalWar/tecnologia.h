#ifndef TECNOLOGIA_H
#define TECNOLOGIA_H

#include <string>
#include <sstream>

using namespace std;

class Tecnologia {
    string nome, descr;
    int custo;
    bool isBought = false;

public:
    Tecnologia(string n, int c, string d) : nome(n), custo(c), descr(d) {}

    // Devolve o nome da tecnologia
    string getNome() const { return nome; }

    // Devolve a descricao da tecnologia
    string getDescr() const { return descr; }

    // Devolve o custo da tecnologia
    int getCusto() const { return custo; }

    string getAsString() const;
};

ostream& operator<<(ostream& out, const Tecnologia& a);

#endif /* TECNOLOGIA_H */