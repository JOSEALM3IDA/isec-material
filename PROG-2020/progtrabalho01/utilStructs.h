// Trabalho Pratico Programacao - LEICE
// DEIS-ISEC 2019-2020
// José Almeida - 2019129077

#ifndef PROGTRABALHO01_UTILSTRUCTS_H
#define PROGTRABALHO01_UTILSTRUCTS_H

#include "utils.h"

// Lista a informação de um local
void listLocal(local local1);

// Verifica se existe um local com o id idLocal. Se sim, devolve a sua posicao no vetor
int posLocal(plocal vetor, int tam, int idLocal);

// Verifica se todos os locais do vetor correspondem ao formato desejado. Devolve 1 se sim, 0 se não
int verificarLocais(plocal vetor, int tam);

// Lista a informação de uma pessoa
void listPessoa(pessoa pessoa1, FILE* f);

// Lista toda a informação da populacao
void listPopulacao(plocal vetor, int tam, FILE* f);

// Devolve um ponteiro para pessoa preenchida pelo utilizador. Se o parametro for 1, assume que é doente e nao pede o estado.
pPessoa pedirPessoa(int doente);

// Verifica se a populacao corresponde ao formato desejado. Devolve 1 se sim, 0 se não
int verificarPessoas(pessoa* p);

// Insere uma pessoa no fim da lista ligada
pPessoa inserirFimPessoas(pPessoa lista, pPessoa p);

// Cria uma copia exata da origem e devolve um ponteiro para ela
plocal deepcopy(plocal origem, int tam);

// Cria uma estrutura com a informacao de uma iteracao
pstat gerarStat(plocal vetor, int tam, int iteracao, const int nTotais[3]);

// Apresenta informacao a ultima iteracao
void apresentarStat(pstat info, FILE* f);

// Inserir estatistica no inicio da lista ligada
pstat inserirStat(pstat stats, pstat novaStat);

// Devolve o numero de nós numa lista ligada
int numPessoas(pPessoa lista);

// Designa cada pessoa da lista num dos espaço
void designarPessoas(plocal vetor, int tam, pPessoa lista, int* nTotais);

// Verificar se a pessoa se recuperou e, se sim, aplicar a chance de ficar imune. Devolve 1 se foi curada, 0 se não
int tentarCurar(pPessoa individuo, int* nTotais);

// Remover pessoa com endereço p da lista ligada (sem a libertar)
pPessoa removerPessoa(pPessoa lista, pPessoa p);

// Escolhe uma pessoa da população aleatoriamente e devolve o seu endereço
pPessoa escolherPessoaAleatorio(pPessoa pop, int nPessoas);

// Liberta toda uma lista ligada
void freeLigada(pPessoa lista);

// Liberta um vetor de locais, incluindo a lista de pessoas
void freeLocais(plocal vetor, int tam);

// Liberta uma estrutura do tipo stat. tam é a quantidade de espaços no seu vetor locais
void freeStat(pstat stat, int tam);

#endif //PROGTRABALHO01_UTILSTRUCTS_H
