#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa no, *pno;

struct pessoa{
    char nome[100];
    int id;
    float peso, altura;
    pno prox;
};

void dados(pno novo){
    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);
    //printf("Id: ");
    novo->id = 1;
    //scanf("%d", &(novo->id));
    //printf("Peso e Altura: ");
    novo->peso = 10;
    novo->altura = 10;
    //scanf("%f %f", &(novo->peso), &(novo->altura));
    novo->prox = NULL;
}

pno adicionaPessoaF(pno p){
    pno novo, aux;

    novo = malloc(sizeof(no));      // 1. Alocar Espaço
    if(novo == NULL)
        return p;
    dados(novo);                 // 2. Preencher

    // 3. Inserir no final
    if(p == NULL)
        p = novo;
    else{
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}


void mostraL(pno p){
    while(p != NULL){
        printf("%d: %s\nPeso: %.1f\tAltura: %.2f\tIMC: %.3f\n\n",
                p->id, p->nome, p->peso, p->altura, p->peso/(p->altura*p->altura));
        p = p->prox;
    }
}

pno eliminaPrimeiroUltimo(pno p){
    pno aux = p->prox;
    p = p->prox;

    while (aux->prox->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = NULL;

    return p;
}

pno inverteLista(pno p) {
    pno ant;
    pno aux = NULL;

    while (p != NULL) {
        ant = aux;
        aux = p;
        p = p->prox;
        aux->prox = ant;
    }

    p = aux;

    return p;
}

void eliminarPares(pno p) {
    pno aux;

    while (p != NULL && p->prox != NULL) {
        aux = p->prox->prox;
        free(p->prox);
        p->prox = aux;
        p = p->prox;
    }
}

int main() {
    pno lista = NULL;
    int i;

    for(i=0; i<2; i++)
        lista = adicionaPessoaF(lista);

    mostraL(lista);
    putchar('\n');

    //lista = eliminaPrimeiroUltimo(lista);      // Elimina o primeiro no e ultimo no da lista
    //mostraL(lista);

    //lista = inverteLista(lista);        // Inverter a ordem dos nos da lista
    //mostraL(lista);

    eliminarPares(lista); // Eliminar todos os nós pares da lista
    mostraL(lista);

    // Falta libertar a lista
    return 0;
}

