// Trabalho Pratico Programacao - LEICE
// DEIS-ISEC 2019-2020
// José Almeida - 2019129077

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#ifndef UTILS_H
#define UTILS_H

#define MAX 100
#define TDISS 0.3 // Percentagem da populacao do local que o doente infeta em cada iteracao
#define TIMUN 0.2 // Probabilidade de, ao ficar curada, ganhar imunidade

typedef struct individuo pessoa, *pPessoa;
struct individuo {
    char id[MAX];
    int idade;
    char estado;
    int duracao;

    pPessoa prox;
};

typedef struct enunciado sler; // Usada apenas para a leitura do ficheiro .bin
struct enunciado {
    int id; // id numérico do local
    int capacidade; // capacidade máxima
    int liga[3]; // id das ligações (-1 nos casos não usados)
};

typedef struct sala local, *plocal;
struct sala {
    int id; // id numérico do local
    int capacidade; // capacidade máxima
    int liga[3]; // id das ligações (-1 nos casos não usados)

    int numPessoas;

    pPessoa lista; // Lista das pessoas que se encontram no local
};

typedef struct estatistica stat, *pstat;
struct estatistica {
    plocal locais; // Informação da população e dos locais numa determinada iteração
    int tam; // Tamanho do vetor locais
    int nPessoas; // Numero de pessoas na iteracao
    int iteracao; // Iteracao a que se refere a estatistica
    float tSaudaveis, tInfetados, tImunes; // Taxa de pessoas saudáveis, infetadas e imunes

    pstat prox;
};

// Inicializa o gerador de numeros aleatorios.
// Esta funcao deve ser chamada apenas uma vez no inicio da execucao do programa
void initRandom();

//Devolve um valor inteiro aleatorio distribuido uniformemente entre [a, b]
int intUniformRnd(int a, int b);

// Devolve o valor 1 com probabilidade prob. Caso contrario, devolve 0
int probEvento(float prob);

// Avanca uma interacao na simulacao
void avancarIteracao(plocal vetor, int tam, int *iteracao, int *nTotais);

// Adiciona um doente a um local
void adicionarDoente(plocal vetor, int tam, int *nPessoas, int *nInfetados);

// Transfere pessoas de um local para outro
void transferirPessoas(plocal vetor, int tam);

// Recua X iterações
pstat recuarIteracoes(plocal *vetor, int tam, pstat stats, int* iteracao, int* nTotais);

// Guarda as informações em ficheiros (gerar relatorio)
void terminarSimulacao(pstat stats, int tam);

#endif /* UTILS_H */
