#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 4

typedef struct concorrente no, *pno;

struct concorrente{
    char nome[200];		/* nome do concorrente */
    int id;			/* n. de aluno: identificador unico */
    float analise;		/* nivel de alcool no sangue */
    pno prox;
};

typedef struct {
    char nome[200];
    int id;
    int pontos;
} class;


// Funcao para criar a estrutura dinamica com base na informacao do ficheiro de texto
void cria_listas(pno tab[], char *n1)
{
    FILE *f;
    pno novo;
    int i, x, y;

    f = fopen(n1, "r");
    if(f==NULL)
    {
        printf("Erro no acesso ao ficheiro\n");
        return;
    }
    while(fscanf(f, " %d %d", &x, &y) == 2)
    {
        for(i=0; i<y; i++)
        {
            novo = malloc(sizeof(no));
            if(novo == NULL)
            {
                printf("Erro na alocacao de memoria\n");
                fclose(f);
                return;
            }
            fscanf(f, " %d %f %[^\n]", &novo->id, &novo->analise, novo->nome);
            novo->prox = tab[x];
            tab[x] = novo;
        }
    }
    fclose(f);
}

void mostraCorridas(pno t[]){
    int i , lugar;
    pno lista;

    for (i = 0; i < N; i++) {
        lista = t[i];
        printf("\n-----Corrida %d-----\n", i);
        lugar = 1;
        while (lista != NULL) {
            printf("Lugar %d: %s\tID: %d\tAnalise: %.2f\n", lugar, lista->nome, lista->id, lista->analise);
            lugar++;
            lista = lista->prox;
        }
    }
}


void libertaListas(pno t[]){
    int i;
    pno lista, ant;

    for (i = 0; i < N; i++) {
        lista = t[i];
        while (lista != NULL) {
            ant = lista;
            lista = lista->prox;
            free(ant);
        }
    }
}

void terminaramTodas(pno t[]) {
    int i, j, conta = 1;
    pno lista;

    for (i = 0; i < N; i++) { // Percorrer todas as corridas
        lista = t[i];

        while (lista != NULL) { // Percorrer todas as pessoas de uma corrida
            conta = 1;

            //contar o numero de vezes que a pessoa aparece

            lista = lista->prox;
        }
    }
}

// Calcular pontos
class* criaVetor(pno t[], int *total) {
    pno lista;
    class* v = NULL;
    int i, j, k, novo;

    for (i = 0; i < N; i++) { // Aceder a todas as corridas

        for (lista = t[i], j = 0; (lista != NULL && j < 3); j++, lista = lista->prox) { // Aceder aos 3 primeiros de cada corrida
            novo = 1;

            for (k = 0; k < *total; k++) { // Verificar se já se encontra no array dinamico
                if (v[k].id == lista->id) {
                    novo = 0;
                    v[k].pontos += 3 - j;
                }
            }

            if (novo) {
                v = realloc(v, sizeof(class) * (*total + 1));
                if (v == NULL) {
                    printf("Erro na realocacao.\n");
                    return NULL;
                }

                strcpy(v[*total].nome, lista->nome);
                v[*total].id = lista->id;
                v[*total].pontos = 3 - j;;

                (*total)++;
            }
        }
    }
    return v;
}

void mostraVetor(class* v, int total) {
    int i;

    putchar('\n');
    for (i = 0; i < total; i++) {
        printf("ID: %d\tNome: %s\tPontos: %d\n", v[i].id, v[i].nome, v[i].pontos);
    }
}


int compara(const void* a, const void* b) {
    const class *p1 = a, *p2 = b;

    if (p1->pontos < p2->pontos)
        return 1;
    else
        return -1;

}

int main()
{
    // Declaracao do array de ponteiros
    pno tab[N] = {NULL};

    class* v = NULL;
    int total = 0;

    // Criar ED
    cria_listas(tab, "dados_15.txt");

    mostraCorridas(tab);      // Alinea a)

    v = criaVetor(tab, &total);

    qsort(v, total, sizeof(class), compara);

    mostraVetor(v, total);

    //terminaramTodas(tab); boomer function

    libertaListas(tab);     // Libertar toda a estrutura dinâmica
    return 0;
}
