
#include <stdio.h>
#include <string.h>


void ex4(char *nomeF){
    FILE *f;
    int c;

    f = fopen(nomeF, "r");
    if(f == NULL)
        printf("Ficheiro nao existe\n");
    else{
        // int feof(FILE *f);       -> Função
        // EOF - constante que assinala o fim de um ficheiro de texto     
        while( (c = fgetc(f)) != EOF)
            putchar(c);

        fclose(f);
    }
}


void ex5(char *nomeF, char *nomeD){
    FILE *f, *d;
    int c;

    f = fopen(nomeF, "r");
    if (f == NULL) {
        printf("Problema na abertura de um ficheiro\n");
        return;
    }

    d = fopen(nomeD, "w");
    if (d == NULL) {
        printf("Problema na abertura de um ficheiro!\n");
        fclose(f);
        return;
    }

    while ((c = fgetc(f)) != EOF) {
        fprintf(d, "%c", c);
    }

    fclose(f);
    fclose(d);
}


void ex6(char *nomeF, char *nomeD){
    FILE *f, *d;
    int c;
    int i = 2;

    f = fopen(nomeF, "r");
    if (f == NULL) {
        printf("Problema na abertura de um ficheiro\n");
        return;
    }

    d = fopen(nomeD, "w");
    if (d == NULL) {
        printf("Problema na abertura de um ficheiro!\n");
        fclose(f);
        return;
    }

    fprintf(d, "1. ");
    while ((c = fgetc(f)) != EOF) {
        fprintf(d, "%c", c);

        if (c == '\n')
            fprintf(d, "%d. ", i++);
    }

    fclose(f);
    fclose(d);
}


int main(){

    ex4("main.c");
    ex5("main.c", "Novo.txt");
    ex6("main.c", "NovoNumerado.txt");

    return 0;
}