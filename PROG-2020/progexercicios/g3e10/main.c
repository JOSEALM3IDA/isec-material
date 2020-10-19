
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente pessoa;

struct cliente{
    char nome[200];
    char morada[200];
    int conta;
    int montante;
};

void listar(char *nomeF){
    FILE *f;
    pessoa x;

    f = fopen(nomeF, "rb");
    if(f==NULL){
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    while(fread(&x, sizeof(pessoa), 1, f) == 1){
        printf("%s\t%s\t%d\t%d\n", x.nome, x.morada, x.conta, x.montante);
    }
    fclose(f);
}

int obtemMaiorDiferenca(char *nomeF){
    FILE *f;
    int dif = 0, maior, menor;
    pessoa x;

    f = fopen(nomeF, "rb");
    if(f==NULL){
        printf("Erro no acesso ao ficheiro\n");
        return dif;
    }

    fread(&x, sizeof(pessoa), 1, f);
    maior = x.montante;
    menor = x.montante;

    while (fread(&x, sizeof(pessoa), 1, f)) {
        if (x.montante > maior)
            maior = x.montante;
        if (x.montante < menor)
            menor = x.montante;
    }

    dif = maior - menor;

    return dif;
}

void listarInverso(char *nomeF){
    FILE *f;
    pessoa x;

    f = fopen(nomeF, "rb");
    if(f==NULL){
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    fseek(f, -sizeof(pessoa), SEEK_END);

    while (1) {
        fread(&x, sizeof(pessoa), 1, f);
        printf("%s\t%s\t%d\t%d\n", x.nome, x.morada, x.conta, x.montante);

        if (ftell(f) == sizeof(pessoa))
            break;

        fseek(f, -2*sizeof(pessoa), SEEK_CUR);
    }

    fclose(f);
}


void printInfoFich(char *nomeF){
    FILE *f;

    f = fopen(nomeF, "rb");
    if(f==NULL){
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    fseek(f, 0, SEEK_END);
    printf("Tamanho em bytes: %ld\n", ftell(f));
    printf("Numero de Clientes: %ld\n", ftell(f)/sizeof(pessoa));
    fclose(f);

}


void eliminarCliente(char *nomeF, char *nomeC) {
    FILE *f, *g;
    pessoa x;

    f = fopen(nomeF, "rb");
    if (f == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    g = fopen("temp.bin", "wb");
    if (g == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        fclose(f);
        return;
    }


    while (fread(&x, sizeof(pessoa), 1, f)) {
        if (strcmp(x.nome, nomeC) != 0)
            fwrite(&x, sizeof(pessoa), 1, g);
    }

    while (fread(&x, sizeof(pessoa), 1, f)) {

        fwrite(&x, sizeof(pessoa), 1, f);

        fseek(f, sizeof(pessoa), SEEK_CUR);
    }

    fclose(f);
    fclose(g);

    remove(nomeF);
    rename("temp.bin", nomeF);
}


void aplicaJuro(char *nomeF, float juro) {
    FILE *f;
    pessoa x;

    f = fopen(nomeF, "rb+");
    if (f == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    while(fread(&x, sizeof(pessoa), 1, f)) {
        x.montante *= juro;

        fseek(f, -sizeof(pessoa), SEEK_CUR);

        fwrite(&x, sizeof(pessoa), 1, f);

        fseek(f, 0, SEEK_CUR);
    }

    fclose(f);
}

void adicionaCliente(char *nomeF, pessoa x) {
    FILE *f, *g;
    pessoa y;
    int escrito = 0;

    f = fopen(nomeF, "rb");
    if (f == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }

    g = fopen("temp.bin", "wb");
    if (g == NULL) {
        printf("Erro no acesso ao ficheiro\n");
        fclose(f);
        return;
    }

    while(fread(&y, sizeof(pessoa), 1, f)) {
        if ((strcmp(y.nome, x.nome) < 0) && !escrito) {
            escrito = 1;
            fwrite(&x, sizeof(pessoa), 1, g);
        }
        fwrite(&y, sizeof(pessoa), 1, g);
    }

    fclose(f);
    fclose(g);

    remove(nomeF);
    rename("temp.bin", nomeF);
}

int main(){
    int x;

    printInfoFich("clientes1_ex10.dat");        // b)

    printf("\nConteudo do ficheiro 1: \n");
    listar("clientes1_ex10.dat");       // a)

    //x = obtemMaiorDiferenca("clientes1_ex10.dat");  // Devolve a diferença entre o maior e menor montantes
    //printf("\nDiferenca: %d\n", x);

    //printf("\nConteudo do ficheiro 1 (inverso): \n");
    //listarInverso("clientes1_ex10.dat");        // c)

    //eliminarCliente("clientes1_ex10.dat", "Bernado Rio");

    pessoa ola;
    ola.nome[0] = 'b';
    ola.morada[0] = 'c'; ola.morada[1] = 'd'; ola.morada[2] = 'e';
    ola.montante = 10;
    ola.conta = 69;
    adicionaCliente("clientes1_ex10.dat", ola);

    //aplicaJuro("clientes1_ex10.dat", 1.1);

    printf("\nConteudo do ficheiro 1 (novo): \n");
    listar("clientes1_ex10.dat");




    return 0;

}