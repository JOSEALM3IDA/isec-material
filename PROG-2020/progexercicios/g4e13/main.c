#include <stdio.h>
#include <stdlib.h>

typedef struct tipoA cliente, *pCliente;
typedef struct tipoB acesso, *pAcesso;

typedef struct {int h, m;} hora;

struct tipoA{
    int id;         // Identificador único
    int contador;   // Número de utilizações nesse dia
    pAcesso lista;  // Ponteiro para a lista de acessos
    pCliente prox;  // Ponteiro para o próximo cliente
};

struct tipoB{
    hora in, out;   // Horas de entrada e saída
    pAcesso prox;
};

void libertaTudo(pCliente p){
    pCliente auxC;
    pAcesso auxA;

    while(p != NULL){
        while(p->lista != NULL){
            auxA = p->lista;
            p->lista = p->lista->prox;
            free(auxA);
        }
        auxC = p;
        p = p->prox;
        free(auxC);
    }
}

pCliente criaExemploED(){
    int totC = 3, i, j, k=-1;
    cliente a[] = {{13, 2, NULL, NULL},{17,1,NULL,NULL},{22,3,NULL,NULL}};
    acesso b[] = {{{10,20},{11,52},NULL}, {{14,30},{17,2},NULL}, {{10,50},{-1,-1},NULL},
                  {{9,11},{9,12},NULL},{{10,5},{12,0},NULL},{{14,33},{-1,-1},NULL}};

    pCliente lista = NULL, novoC;
    pAcesso novoA;

    for(i=0; i<totC; i++){
        k+=a[i].contador;
    }
    for(i=totC-1; i>=0; i--){
        novoC = malloc(sizeof(cliente));
        if(novoC == NULL){
            libertaTudo(lista);
            return NULL;
        }
        *novoC = a[i];
        novoC->prox = lista;
        lista = novoC;
        for(j=0; j<novoC->contador; j++){
            novoA = malloc(sizeof(acesso));
            if(novoA == NULL){
                libertaTudo(lista);
                return NULL;
            }
            *novoA = b[k--];
            novoA->prox = novoC->lista;
            novoC->lista = novoA;
        }
    }
    return lista;
}

void mostraTudo(pCliente p){
    pAcesso aux;

    while(p != NULL){
        printf("Cliente com id %d efetuou %d acessos:\n", p->id, p->contador);
        aux = p->lista;
        while(aux != NULL){
            printf("%.2d:%.2d - %.2d:%.2d\n", aux->in.h, aux->in.m, aux->out.h, aux->out.m);
            aux = aux->prox;
        }
        p = p->prox;
    }
}

void mostraInfoCliente(pCliente lista, int id){
    pAcesso aux;

    while(lista->id != id && lista != NULL)
        lista = lista->prox;

    if (lista == NULL) {
        printf("Id %d nao encontrado.\n", id);
        return;
    }

    printf("Cliente com id %d efetuou %d acessos:\n", lista->id, lista->contador);
    aux = lista->lista;

    while (aux != NULL) {
        printf("%.2d:%.2d - %.2d:%.2d\n", aux->in.h, aux->in.m, aux->out.h, aux->out.m);
        aux = aux->prox;
    }

}

int getClientesNoParque(pCliente lista){
    pAcesso aux;
    int total = 0;

    while (lista != NULL) {
        aux = lista->lista;

        while (aux->prox != NULL)
            aux = aux->prox;

        if (aux->out.h == -1 && aux->out.m == -1)
            total++;

        lista = lista->prox;
    }

    return total;
}

// alinea b)
int maisMinutos(pCliente lista) {
    pAcesso aux;
    int id = -1, maior = -1, minutos;

    while (lista != NULL) {
        aux = lista->lista;
        minutos = 0;

        while (aux != NULL && aux->out.h != -1 && aux->out.m != -1) {
            minutos += (aux->out.h - aux->in.h)*60 + (aux->out.m - aux->in.m);

            aux = aux->prox;
        }

        if (minutos > maior && aux == NULL) {
            maior = minutos;
            id = lista->id;
        }

        lista = lista->prox;
    }
    return id;
}

// alinea d)
pCliente acessoParque(pCliente lista, int id, hora time) {
    pCliente p = lista, c, aux;
    pAcesso a, aux1;

    while (p != NULL && p->id != id) {
        p = p->prox;
    }

    if (p == NULL) { // Entrada de um novo cliente
        c = malloc(sizeof(cliente));
        a = malloc(sizeof(acesso));
        if (a == NULL || c == NULL)
            return lista;

        c->id = id;
        c->contador = 1;

        a->in = time;
        a->out.m = -1;
        a->out.h = -1;
        a->prox = NULL;

        c->lista = a;

        aux = lista;

        while (aux->prox != NULL && aux->prox->id < id)
            aux = aux->prox; // Colocado no elemento antes de onde tem de ocorrer a inserçao

        if (aux == lista) {
            c->prox = lista->prox;
            lista = c;
        } else {
            c->prox = aux->prox;
            aux->prox = c;
        }
    } else { // Cliente já conhecido
        aux1 = p->lista;

        while (aux1->prox != NULL)
            aux1 = aux1->prox;

        if (aux1->out.h == -1 && aux1->out.m == -1) { // Nova entrada de um cliente
            aux1->out = time;

        } else { // Saida de um cliente
            a = malloc(sizeof(acesso));
            if (a == NULL)
                return lista;

            a->in = time;
            a->out.h = a->out.m = -1;
            a->prox = NULL;
            aux1->prox = a;
        }
    }
    return lista;
}


int main(){

    pCliente lista = criaExemploED();
    int total, id;

    //mostraTudo(lista);

    //mostraInfoCliente(lista, 22);       // Mostra info do cliente com id 22

    //total = getClientesNoParque(lista);     // Devolve número de clientes no parque a)
    //printf("Estao %d clientes no parque\n", total);

    id = maisMinutos(lista);
    putchar('\n');
    mostraInfoCliente(lista, id);

    //mostraTudo(lista);

    //putchar('\n');

    //lista = acessoParque(lista, 13, (hora){18,00}); // Nova entrada de um cliente
    //lista = acessoParque(lista, 22, (hora){18,15}); // Saida de um cliente
    //lista = acessoParque(lista, 54, (hora){18,30}); // Novo cliente

    //mostraTudo(lista);

    libertaTudo(lista);
    return 0;
}