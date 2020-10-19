
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paragem stop;

struct paragem{
    char nome[50];
    int minutos;
};


void listaTudo(char *nomeFich){
    FILE *f;
    stop c;

    f = fopen(nomeFich, "rb");
    if(f == NULL){
        printf("Erro ao abrir ficheiro\n");
        return;
    }
    // Ler estruturas uma a uma e escrever na consola o nome e minutos de cada uma delas

    while(fread(&c, sizeof(stop), 1, f)){
        printf("Paragem: %s\tDemorou: %d minutos\n", c.nome, c.minutos);
    }

    fclose(f);

}

int duracaoTotal(char *nomeFich){
    int total=0;
    FILE *f;
    stop c;

    f = fopen(nomeFich, "rb");
    if(f == NULL){
        printf("Erro ao abrir ficheiro\n");
        return 0;
    }
    while(fread(&c, sizeof(stop), 1, f)){
        total += c.minutos;
    }

    return total;
}

int existeParagem(char *nomeFich, char *local){
    FILE *f;
    stop c;

    f = fopen(nomeFich, "rb");
    if(f == NULL){
        printf("Erro ao abrir ficheiro\n");
        return 0;
    }

    while(fread(&c, sizeof(stop), 1, f))
        if(!strcmp(c.nome,local))
            return 1;

    return 0;
}

int existePercurso(char *nomeFich, char *local1, char *local2){
    FILE *f;
    stop c;
    int i, pos1 = -1, pos2 = -1;

    f = fopen(nomeFich, "rb");
    if(f == NULL){
        printf("Erro ao abrir ficheiro\n");
        return 0;
    }

    i = 0;
    while(fread(&c, sizeof(stop), 1, f)){
        if(!strcmp(c.nome,local1))
            pos1 = i;

        if(!strcmp(c.nome,local2))
            pos2 = i;

        i++;
    }

    if(pos2 > pos1 && pos1 != -1 && pos2 != -1)
        return 1;

    return 0;
}

int main(){
    char p1[50], p2[50];

    // a) Listar todas as paragens
    listaTudo("cp_ex1.dat");

    // b) Duraçao total do trajeto
    printf("\nDuracao: %d minutos\n", duracaoTotal("cp_ex1.dat"));

    // NOVA - Verificar se existe uma paragem
    printf("Indique uma paragem: ");
    scanf(" %s", &p1);
    printf("Existe paragem: %d\n", existeParagem("cp_ex1.dat", p1));

    // c) Verifica se ha percurso entre duas paragens
    printf("Indique outra paragem: ");
    scanf(" %s", &p2);
    printf("Existe percurso: %d", existePercurso("cp_ex1.dat", p1, p2));

    return 0;
}

