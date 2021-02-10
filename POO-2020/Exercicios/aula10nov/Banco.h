#pragma once
#include <string>
#include <sstream>
#include <vector>
#include "Conta.h"

using namespace std;

class Banco {
    const string nome;
    vector<Conta> listaContas;

    public:

    Banco(string nome) : nome(nome) {};

    string getNome() {return nome;}

    bool addConta(Pessoa p);

    bool atualizaSaldo(int cc, int dep);

    float obterSaldo(int cc) const;

    float getTotalSaldos() const;

    string getAsString() const;

    void eliminarConta(int cc);

    bool transferencia(int cc1, int cc2, int montante, Banco &bd);
};
