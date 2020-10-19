#include <stdio.h>
#include <stdlib.h>

void listarTodos(char *nomeFich){
    FILE *f;
    int num;

    f = fopen(nomeFich, "rb");
    if(f == NULL){
        printf("Erro ao abrir ficheiro\n");
        return;
    }

    while(fread(&num, sizeof(int), 1, f)){
        printf("%d ", num);
    }

    fclose(f);
}

void calculaSomaMedia(char *nomeFich, int *soma, float *media){
    FILE *f;
    int num, i = 0;

    f = fopen(nomeFich, "rb");
    if(f == NULL){
        printf("\nErro ao abrir ficheiro\n");
        return;
    }

    while(fread(&num, sizeof(int), 1, f)){
        *soma += num;
        i++;
    }

    *media = *soma;
    *media /= i;

    fclose(f);
}

int* criaVetor(char *nomeFich, int *tam){
    FILE *f;
    int *a = NULL, *b, num;

    *tam = 0;

    f = fopen(nomeFich, "rb");
    if(f == NULL){
        printf("\nErro ao abrir ficheiro\n");
        return NULL;
    }

    while(fread(&num, sizeof(int), 1, f)){
        if(num%2 == 0){
            b = realloc(a, sizeof(int) * (*tam + 1));
            if(b == NULL){
                printf("Erro no realloc!");
                fclose(f);
                free(a);
                *tam = 0;
                return NULL;
            }
            a = b;
            a[*tam] = num;
            (*tam)++;
        }
    }
    fclose(f);
    return a;
}


void listarVetor(int *vetor, int tam) {
    int i;
    putchar('[');

    for(i = 0; i < tam-1; i++)
        printf("%d, ", vetor[i]);

    printf("%d", vetor[tam - 1]);
    putchar(']');
}

void criarFicheiros(char *nomeFich, char *nomeAbaixo, char *nomeAcima){
    FILE *fRead, *fAbaixo, *fAcima;
    int num, soma = 0;
    float media = 0.0;

    ////////////////////////////////////////////////////////////// Abertura de ficheiros
    fRead = fopen(nomeFich, "rb");
    if(fRead == NULL){
        printf("Erro ao abrir ficheiro\n");
        return;
    }
    fAbaixo = fopen(nomeAbaixo, "wb");
    if(fAbaixo == NULL){
        printf("Erro ao abrir ficheiro\n");
        fclose(fRead);
        return;
    }
    fAcima = fopen(nomeAcima, "wb");
    if(fAcima == NULL){
        printf("Erro ao abrir ficheiro\n");
        fclose(fRead);
        fclose(fAbaixo);
        return;
    }
    ////////////////////////////////////////////////////////////// Abertura de ficheiros

    calculaSomaMedia(nomeFich, &soma, &media);

    while(fread(&num, sizeof(int), 1, fRead)){
        if((float)num < media){
            fwrite(&num, sizeof(int), 1, fAbaixo);
        }
        else
            fwrite(&num, sizeof(int), 1, fAcima);
    }

    fclose(fRead);
    fclose(fAbaixo);
    fclose(fAcima);
}

int main() {
    float media = 0.0;
    int tam = 0, *vetor, soma;
    char fileName[20] = "valoresEx2.bin", fileAbaixo[20] = "abaixo.bin", fileAcima[20] = "acima.bin";

    listarTodos(fileName);

    calculaSomaMedia(fileName, &soma, &media);
    printf("\nSoma: %d\tMedia: %.2f\n", soma, media);

    vetor = criaVetor(fileName, &tam);
    printf("\nNumeros pares (vetor): ");
    listarVetor(vetor, tam);

    criarFicheiros(fileName, fileAbaixo, fileAcima);

    printf("\nNumeros abaixo da media (ficheiro): ");
    listarTodos(fileAbaixo);

    printf("\nNumeros acima da media (ficheiro): ");
    listarTodos(fileAcima);
    
    putchar('\n');
    return 0;
}
