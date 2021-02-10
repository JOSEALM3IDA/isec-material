#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "mundo.h"
#include "comando.h"
#include "save.h"
#include "error_codes.h"

using namespace std;

class Interface {
    Mundo& mnd;
    vector<Save*> saves;
    int proxFase; // -1 -> setup; 0 -> conquista; 1 -> recolha; 2 -> compra; 3 -> eventos; 4 -> fim de jogo;
    vector<Comando> comandos = { {"carrega", "Carrega a informacao sobre o mundo de um ficheiro (apenas territorios)", "<nome_fich>"},
                                 {"cria", "Cria n territorios do tipo especificado", "<tipo> <n>"},
                                 {"conquista", "Tenta conquistar um territorio", "<nome>"},
                                 {"passa", "Passa a chance de conquistar"}, 
                                 {"maisouro", "Compra 1 unidade de ouro ao preco de 2 unidades de produtos"},
                                 {"maisprod", "Compra 1 unidade produtos ao preco de 2 unidades de ouro"},
                                 {"maismilitar", "Compra 1 unidade militar ao preco de 1 unidade de ouro e 1 unidade de produtos"},
                                 {"adquire", "Compra uma determinada tecnologia", "<nome>"},
                                 {"lista", "Lista a informacao sobre o mundo ou sobre um territorio em especifico", "(<nome>)"},
                                 {"avanca", "Passa ao proximo turno"},
                                 {"grava", "Cria um save em memoria com a informacao sobre o jogo atual com o nome especificado", "<nome_save>"},
                                 {"ativa", "Carrega a informacao em memoria sobre o save com nome especificado", "<nome_save>"},
                                 {"apaga", "Apaga a informacao em memoria sobre o save especificado", "<nome_save>"},
                                 {"info", "Devolve as instrucoes e descricao de um comando especificado", "<nome_cmd>"},
#if DEBUG
                                 {"toma", "(DEBUG) Toma automaticamente uma tecnologia ou territorio, sem quaisquer restricoes ou custos", "<tec/terr> <nome>"},
                                 {"modifica", "(DEBUG) Modifica o armazem ou cofre do imperio" "<ouro/prod> <n>"},
                                 {"fevento", "(DEBUG) Forca o acontecimento do evento especificado", "<nome-evento>"},
                                 {"quit", "(DEBUG) Obriga o jogo a terminar"}
#endif
                                };

    // Divide a string em substrings separadas pelo char c
    vector<string> split(const string &s, char c);

    // Devolve a informacao sobre o turno atual
    string infoTurno();

public:
    Interface(Mundo& m);
    Interface(const Interface& ref);
    ~Interface();

    // Pede comandos ao utilizador
    errcode pedirComandos();

    // Controla a fase atual do jogo
    void jogo();

    errcode faseSetup();
    errcode faseConquista();
    errcode faseRecolha();
    errcode faseCompra();
    errcode faseEventos();

    // Le um ficheiro de texto e executa os comandos la disponiveis
    errcode carrega(string fileName);

    // Executa o comando em inputv[0], caso exista, com os argumentos incluidos no vetor
    errcode execute(vector<string> inputv);

    // Altera a disponibilidade do comando especificado para a nova disponibilidade
    errcode changeCMDDisp(string nomeCMD, bool novaDisp);

    // Devolve o nome dos comandos disponiveis
    string getComandosDisponiveis() const;

    Interface& operator=(const Interface& dir);
};

#endif /* INTERFACE_H */