#ifndef IMPERIO_H
#define IMPERIO_H

#include <string>
#include <vector>

#include "territorio.h"
#include "tecnologia.h"
#include "error_codes.h"

using namespace std;

class Imperio {
    vector<Territorio *> territorios;
    vector<Tecnologia *> tecnologias;
    int cofre = 0, armazem = 0, forca = 0;
    
    // Verifica se e possivel adicionar q unidades de algo
    // Tipo - 0: ao cofre; 1: ao armazem; 2: a forca militar
    bool canAdd(int q, int tipo);

public:

    // Perde uma unidade de forca caso esta seja superior a 0
    void perderForca() { if (forca > 0) { forca--; } }

    // Percorre os territorios e recolhe ouro e produto
    errcode recolha();

    // Adiciona q unidades de ouro ao cofre
    errcode addOuro(int q);

    // Adiciona q unidades de produto ao armazem
    errcode addProd(int q);

    // Adiciona q unidades a forca militar
    errcode addForca(int q);

    // Compra a tecnologia especificada, caso seja possivel
    errcode addTec(Tecnologia &newTec);

#if DEBUG
    // Adiciona a tecnologia especificada, ignorando custos
    errcode forceAddTec(Tecnologia &newTec);

    // Modifica o cofre do imperio para a quantidade especificada
    void setOuro(int q) { cofre = q; }

    // Modifica o armazem do imperio para a quantidade especificada
    void setProd(int q) { armazem = q; }
#endif

    // Verifica se a tecnologia especificada esta adquirida ou nao
    bool hasTec(string nome) const;

    // Executa uma troca do tipo passado por parametro (caso seja possivel)
    // Tipo - 0: compra ouro com produtos; 1: compra produtos com ouro; 2: compra forca militar com ouro e produtos
    errcode troca(int tipo);

    // Adiciona um territorio ao imperio
    errcode addTerr(Territorio *t);

    // Remove um territorio do imperio usando o nome
    errcode rmTerr(string nome);

    // Remove um territorio do imperio usando o ponteiro para o territorio
    void rmTerr(Territorio *t);

    // Devolve o numero de territorios conquistados
    int getNTerr() const { return territorios.size(); }

    // Devolve toda a informacao sobre os territorios conquistados
    string getTerritorios() const;

    // Devolve o nome das tecnologias adquiridas
    string getNomeTecnologias() const;

    // Devolve um ponteiro para o ultimo territorio conquistado
    Territorio* getLastConquistado() { return territorios[territorios.size() - 1]; }

    // Devolve a forca militar
    int getForca() const { return forca; }

    // Devolve a quantidade de ouro disponivel
    int getCofre() const { return cofre; }

    // Devolve a quantidade de produtos disponivel
    int getArmazem() const { return armazem; }

    // Devolve a producao de ouro atual dos territorios conquistados
    int getProdOuroTotal() const;

    // Devolve a producao de produtos atual dos territorios conquistados
    int getProdProdTotal() const;

    // Devolve a soma dos pontos de vitoria dos territorios conquistados
    int getSomaPontosTerr() const;

    // Devolve o numero de tecnologias adquiridas
    int getNTec() const { return tecnologias.size(); }

    // Devolve o numero de pontos devido a tecnologias
    int getSomaPontosTec() const { return getNTec(); }

    string getAsString() const;
};

ostream& operator<<(ostream& out, const Imperio& a);

#endif /* IMPERIO_H */