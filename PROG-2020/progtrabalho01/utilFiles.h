// Trabalho Pratico Programacao - LEICE
// DEIS-ISEC 2019-2020
// José Almeida - 2019129077

#ifndef PROGTRABALHO01_UTILFILES_H
#define PROGTRABALHO01_UTILFILES_H

#include "utils.h"
#include "utilStructs.h"

// Pede um ficheiro, abre-o, verifica se tem extensão "ext" e devolve o nome por ponteiro
void pedirFicheiro(char *fileName, char ext[3], const char tipo[3]);

// Cria um vetor dinamico de locais a partir de um ficheiro binário
local* lerBinario(char fileName[MAX], int* tam);

// Cria uma lista ligada de pessoas a partir de um ficheiro de texto
pessoa* lerTxt(char fileName[MAX]);

// Trata de tudo para criar um novo ficheiro de espacos ou pessoas
void criarFicheiro(char tipo);

// Listar um ficheiro de espaços ou pessoas
void listarFicheiro(char tipo);

// Verificar um ficheiro de espaços ou pessoas
void verificarFicheiro(char tipo);

#endif //PROGTRABALHO01_UTILFILES_H
