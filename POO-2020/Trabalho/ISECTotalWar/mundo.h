#ifndef MUNDO_H
#define MUNDO_H

#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "territorio.h"
#include "castelo.h"
#include "duna.h"
#include "fortaleza.h"
#include "mina.h"
#include "montanha.h"
#include "pescaria.h"
#include "planicie.h"
#include "refugio.h"
#include "terr_inicial.h"

#include "imperio.h"
#include "tecnologia.h"
#include "error_codes.h"

using namespace std;

class Mundo {
    vector<Territorio*> territorios;
    Imperio imp;
    int turno = 1;
    vector<string> eventos = {"Sem Evento", "Recurso Abandonado", "Invasao", "Alianca Diplomatica"};
    vector<Tecnologia> tecnologias = { {"Drones Militares", 3, "Faz passar o limite maximo da forca militar para 5."},
                                       {"Misseis Teleguiados", 4, "Permite conquistar ilhas."},
                                       {"Defesas Territoriais", 4, "Aumenta em 1 a resistencia do territorio invadido durante uma invasao."},
                                       {"Bolsa de Valores", 2, "Torna possiveis as trocas entre produtos e ouro na fase de recolha."},
                                       {"Banco Central", 3, "Expande cofre e armazem para um maximo de 5 unidades."} };
    
    // Executa a logica de fim de jogo
    void fimJogo();

    // Evento Recurso Abandonado
    string recAbandonado();

    // Evento Invasao
    string invasao();

    // Evento Alianca Diplomatica
    string aliDiplomatica();

public:
    Mundo();
    Mundo(const Mundo& ref);
    ~Mundo();

#if DEBUG
    // Forca o final de jogo
    void forceFimJogo() { fimJogo(); }

    // Modifica o cofre do imperio para a quantidade especificada
    void modificaOuroImp(int q) { imp.setOuro(q); }

    // Modifica o armazem do imperio para a quantidade especificada
    void modificaProdImp(int q) { imp.setProd(q); }
    
    // Da uma tecnologia am imperio, ignorando custos de compra
    errcode giveTec(string n);

    // Da um territorio ao imperio, ignorando a logica e restricoes de conquista
    errcode giveTerr(string n);

    // Escolhe um evento aleatoriamente (ou nao)
    errcode escolheEvento(string& desc, string nome = "");

    // Realiza um evento aleatoriamente (ou nao), preenchendo s com a explicacao do ocorrido
    errcode realizaEvento(string& s, int e = -1);
#else
    // Realiza um evento aleatoriamente, preenchendo s com a explicacao do ocorrido
    errcode realizaEvento(string& s);
#endif
    // Executa a logica de passagem de turno
    errcode proxTurno();

    // Devolve o turno atual
    int getTurno() const { return turno; }

    // Muda ou devolve a string com informacao sobre o fim do jogo
    string infoFimJogo(string s = "");

    // Pede ao imperio para fazer a recolha de produtos
    errcode recolha() { return imp.recolha(); }
    
    // Executa a logica de conquista de um territorio
    errcode conquista(string terrName, int& sorte);

    // Cria n territorios do tipo especificado (caso seja válido)
    errcode cria(string tipo, int n);

    // Pede ao imperio para adicionar a tecnologia especificada, caso exista
    errcode adquire(string tec);

    // Verifica se o imperio tem a tecnologia necessaria para fazer trocas de ouro e produtos
    bool hasTecTrocaImp() { return imp.hasTec("Bolsa de Valores"); }
    
    // Pede ao imperio para executar uma troca de produtos por ouro
    errcode trocaOuroImp() { return imp.troca(0); }

    // Pede ao imperio para executar uma troca de ouro por produtos
    errcode trocaProdImp() { return imp.troca(1); }

    // Pede ao imperio para executar uma troca de ouro e produtos por forca militar
    errcode trocaMilitarImp() { return imp.troca(2); }

    // Devolve a informacao relativa a um territorio, caso exista
    string getTerrInfo(string terrName) const;

    // Devolve a lista de territorios nao conquistados
    string getFreeTerritorios() const;

    // Devolve o numero de territorios no mundo
    int getNTerritorios() const { return territorios.size(); }

    // Devolve tudo sobre as tecnologias nao compradas
    string getAvailableTec() const;

    // Devolve a forca militar do imperio
    int getForcaImp() const { return imp.getForca(); }

    // Devolve a quantidade de ouro nos cofres do imperio
    int getCofreImp() const { return imp.getCofre(); }

    // Devolve a quantidade de produtos no armazem do imperio
    int getArmazemImp() const { return imp.getArmazem(); }

    string getAsString() const;
    
    Mundo& operator=(const Mundo& dir);
};

ostream& operator<<(ostream& out, const Mundo& a);


#endif /* MUNDO_H */