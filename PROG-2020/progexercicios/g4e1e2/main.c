

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa no, *pno;

struct pessoa{
    char nome[100];
    int id;
    float peso, altura;
    pno prox;
};

void preenche(pno novo){
    printf("Nome: ");
    scanf(" %[^\n]", novo->nome);
    printf("Id: ");
    scanf("%d", &(novo->id));
    printf("Peso e Altura: ");
    scanf("%f %f", &(novo->peso), &(novo->altura));
    novo->prox = NULL;
}

pno adicionaPessoa(pno p){    // alinea b)
    pno novo, aux, ant = p;
    int repetido;

    novo = malloc(sizeof(no));      // 1. Alocar Espaço

    do {
        aux = p;
        repetido = 0;
        preenche(novo);                 // 2. Preencher

        while (aux != NULL) {
            if (novo->id == aux->id) {
                repetido = 1;
                printf("Id repetido!\n");
                break;
            }
            ant = aux;
            aux = aux->prox;
        }
    } while (repetido);

    if (ant == NULL) {
        novo->prox = p;                 // 3. Inserir no inicio
        p = novo;
    } else
        ant->prox = novo;                  // 3. Inserir no fim

    return p;
}

void mostraLista(pno p, FILE* f) {
    float imc;
    while(p != NULL)  {
        imc = p->peso/(p->altura*p->altura);
        fprintf(f, "Nome: %s\nId: %d\tPeso: %.2f\tAltura: %.2f\tIMC: %.2f\n\n", p->nome, p->id, p->peso, p->altura, imc);
        p = p->prox;
    }
}


// alinea d)
void atualizaPeso(pno p, int id, float peso) {
    while (p != NULL && p->id != id)
        p = p->prox;

    if (p == NULL) {
        printf("Id nao encontrado!\n");
    } else {
        p->peso = peso;
    }
}

// alinea e)
pno retirarPessoa(pno p, int id) {
    pno aux = p, ant = p;

    while (aux != NULL && aux->id != id) {
        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("Id nao encontrado!\n");
    } else if (aux == p) {
        p = p->prox;
        free(aux);
    } else {
        ant->prox = aux->prox;
        free(aux);
    }

    return p;
}

// alinea f)
void libertarLista(pno p) { // pode nao estar totalmente correta
    pno aux;

    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

// alinea g)
pno eliminarPorIMC(pno p, float X) {
    pno aux = p, ant;
    float imc;

    do {
        do {
            imc = aux->peso/(aux->altura * aux->altura);

            if (imc > X)
                break;
            else {
                ant = aux;
                aux = aux->prox;
            }
        } while (aux != NULL);

        if (aux == NULL)
            return p;

        if (aux == p)
            p = p->prox;
        else
            ant->prox = aux->prox;

        free(aux);
        aux = p;

    } while (aux != NULL);

    return p;
}

// alinea a)
void gravaLista(pno p, char *nomeF) {
    FILE *f;

    f = fopen(nomeF, "w");
    if (f == NULL)
        return;
    mostraLista(p, f);
    fclose(f);
}

float getIMC (pno p) {
    return p->peso/(p->altura*p->altura);
}

pno recuperaLista(char *nomeF) {
    FILE *f;
    pno p = NULL, individuo, atual = NULL, ant = NULL;
    float imc1, imc2;
    char str[100];

    f = fopen(nomeF, "r");
    if (f == NULL) {
        return p;
    }

    while (fscanf(f, " Nome: %[^\n] ", str) != EOF) {
        individuo = malloc(sizeof(no));

        strcpy(individuo->nome, str);
        fscanf(f, " Id: %d Peso: %f Altura: %f IMC: %*f", &individuo->id, &individuo->peso, &individuo->altura);

        individuo->prox = NULL;

        if (p == NULL) {
            p = individuo;
        } else {
            atual = p;

            while (atual != NULL && getIMC(atual) < getIMC(individuo)) {
                ant = atual;
                atual = atual->prox;
            }

            if (p == atual) { // Inserir no inicio
                individuo->prox = atual;
                p = individuo;
            } else {
                individuo->prox = atual;
                ant->prox = individuo;
                atual = individuo;
            }
        }
    }
    return p;
}

int main() {
    pno lista = NULL;       // alinea a)
    int id;
    float peso, imc;

    lista = recuperaLista("listaDesordenada.txt");

    /*
    lista = adicionaPessoa(lista);
    lista = adicionaPessoa(lista);
    lista = adicionaPessoa(lista);
     */

    mostraLista(lista, stdout);
    putchar('\n');

    /*
    printf("Id e novo peso: ");
    scanf("%d %f", &id, &peso);
    atualizaPeso(lista, id, peso);

    putchar('\n');
    mostraLista(lista);
    */

    /*
    printf("Id a retirar: ");
    scanf("%d", &id);
    lista = retirarPessoa(lista, id);

    putchar('\n');
    mostraLista(lista);

     */

    /*
    printf("IMC: ");
    scanf("%f", &imc);
    lista = eliminarPorIMC(lista, imc);

    mostraLista(lista);
    putchar('\n');
     */

    gravaLista(lista, "listaOrdenada.txt");
    libertarLista(lista);

    return 0;
}