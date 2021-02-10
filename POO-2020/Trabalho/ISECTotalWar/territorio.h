#ifndef TERRITORIO_H
#define TERRITORIO_H

#include <string>
#include <sstream>

#include "error_codes.h"

using namespace std;

class Territorio {
    string nome;
    int resistencia;
    static int count;
    int prodProdutos, prodOuro, tempoConquistado = 0;
    bool conquistado = false;

protected:
    // Muda a producao de produtos para q
    void setProd(int q) { prodProdutos = q; }

    // Muda a producao de ouro para q
    void setOuro(int q) { prodOuro = q; }

    // Incrementa tempoConquistado
    void incrTConquistado() { if (conquistado) tempoConquistado++; }

public:
    Territorio(int r, string n, int po, int pp) : resistencia(r), nome(n), prodOuro(po), prodProdutos(pp) {}

    // Muda o estado de conquista do territorio
    void setConquistado(bool b);

    // Verifica se o territorio esta conquistado
    bool isConquistado() const { return conquistado; }

    // Devolve ha quantos turnos o territorio foi conquistado
    int getTConquistado() const { return tempoConquistado; }

    // Devolve o numero de pontos de vitoria que o territorio da
    virtual int getPontos() const = 0;

    // Devolve o valor da producao de ouro do territorio
    int getOuro() const { return prodOuro; }

    // Devolve o valor de producao de produtos do territorio
    int getProd() const { return prodProdutos; }
    
    // Devolve o nome do territorio
    string getNome() const { return nome; }

    // Executa a logica de atualizacao, dado o turno
    virtual errcode atualizar(int turno);

    // Devolve a resistencia do territorio
    int getRes() const { return resistencia; }

    // Devolve um ponteiro para uma copia de si mesmo em memoria
    virtual Territorio* clone() = 0;

    virtual string getAsString() const;
};

ostream& operator<<(ostream& out, const Territorio& a);

#endif /* TERRITORIO_H */