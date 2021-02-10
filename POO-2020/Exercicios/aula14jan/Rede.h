#ifndef REDE_H
#define REDE_H

#include <vector>

#include "Cartao.h"
#include "Tarifario.h"

using namespace std;

class Rede {
    vector<Cartao*> cartoes;
    vector<Tarifario*> tarifarios;

public:

    Rede(vector<Tarifario*> tarifs) : tarifarios(tarifs) {}
    Rede(const Rede& ref);

    ~Rede();

    void addC(Cartao *c, int tarif);

    int getSaldo(int num);

    void rmC(int num);

    bool autoriza(int num) const;

    void regista(int num, int min);

    bool carrega(int num, int val);

    string getAsString() const;

    Rede& operator=(const Rede& dir);
};

ostream& operator<<(ostream& out, const Rede& r);

#endif /* REDE_H */