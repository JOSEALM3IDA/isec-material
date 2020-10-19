// Trabalho Pratico Programacao - LEICE
// DEIS-ISEC 2019-2020
// José Almeida - 2019129077

#include "utilStructs.h"


void listLocal(local local1) {
    int i;

    printf("\nId: %d\nCapacidade: %d", local1.id, local1.capacidade);

    printf("\nLigacoes:");
    for (i = 0; i < 3; i++)
        printf(" %d", local1.liga[i]);
}

int posLocal(plocal vetor, int tam, int idLocal) {
    int i, pos = -1;

    for (i = 0; i < tam; i++) {
        if (idLocal == vetor[i].id) {
            pos = i;
            break;
        }
    }

    return pos;
}

int verificarLocais(plocal vetor, int tam) {
    int i, j, k, aux, ligacao, pos;

    for (i = 0; i < tam; i++) {  // Percorrer todos os locais

        if (vetor[i].id < 1) {
            printf("\nERRO: Detetado local com id nao positivo (%d)!\n", vetor[i].id);
            return 0;
        }

        if (vetor[i].capacidade < 1) {
            printf("\nERRO: Detetado local (%d) com capacidade nao positiva (%d)!\n", vetor[i].id, vetor[i].capacidade);
            return 0;
        }

        for (j = i+1; j < tam; j++)
            if (vetor[j].id == vetor[i].id) {
                printf("\nERRO: ID %d repetido!\n", vetor[j].id);
                return 0;
            }

        for (j = 0; j < 3; j++) {  // Percorrer todas as ligações de um determinado local

            ligacao = vetor[i].liga[j];

            if(vetor[i].id == ligacao) {
                printf("\nERRO: Detetado local %d com ligacao a ele proprio!\n", vetor[i].id);
                return 0;
            }

            if (ligacao == -1) // Passar à proxima ligacao
                continue;

            pos = posLocal(vetor, tam, ligacao);  // Procurar o local com id pretendido
            if (pos == -2) {
                printf("\nERRO: Local %d tem ligacao a um local %d inexistente!\n", vetor[i].id, ligacao);
                return 0;
            }

            aux = 0;
            for (k = 0; k < 3; k++)                       // Percorrer todas as ligações do local que está ligado ao inicial
                if (vetor[pos].liga[k] == vetor[i].id) {  // Verificar se uma determinada ligação liga ao local original
                    aux = 1;
                    break;
                }

            if (!aux) {
                printf("\nERRO: Ligacao %d do local %d nao se encontra correspondida!\n", ligacao, vetor[i].id);
                return 0;
            }

        }
    }
    return 1;
}

void listPessoa(pessoa pessoa1, FILE* f) {
    fprintf(f, "%-15s\t%d\t%c", pessoa1.id, pessoa1.idade, pessoa1.estado);

    if (pessoa1.estado == 'D') {
        fprintf(f, "\t%d", pessoa1.duracao);
    } else {
        fprintf(f, "\t-");
    }

    fprintf(f, "\n");
}

void listLigada(pPessoa lista, FILE* f) {
    while (lista != NULL) {
        listPessoa(*lista, f);
        lista = lista->prox;
    }
}

void listPopulacao(plocal vetor, int tam, FILE* f) {
    int i;
    float doentes;
    pPessoa aux;

    for (i = 0; i < tam; i++) {
        fprintf(f, "\n---LOCAL: %d\tLIGACOES: %2d %2d %2d\tCAPACIDADE TOTAL: %d---\nID\t\tIDADE\tESTADO\tDURACAO\n", vetor[i].id, vetor[i].liga[0], vetor[i].liga[1], vetor[i].liga[2], vetor[i].capacidade);
        listLigada(vetor[i].lista, f);
        printf("\nNumero de Pessoas do Local %d: %d\n", vetor[i].id, vetor[i].numPessoas);

        doentes = 0;
        aux = vetor[i].lista;
        while (aux != NULL) {
            if (aux->estado == 'D')
                doentes++;
            aux = aux->prox;
        }

        doentes = doentes/(float)vetor[i].numPessoas;

        printf("Taxa de Doentes do Local %d: %.2f\n", vetor[i].id, doentes);
    }
}

pPessoa pedirPessoa(int doente) {
    pPessoa p = malloc(sizeof(pessoa));
    if (p == NULL) {
        printf("ERRO: Alocacao de memoria falhou!\n");
        return NULL;
    }

    printf("Identificador: ");
    scanf(" %s", p->id);

    printf("Idade: ");
    scanf(" %d", &p->idade);

    if (doente) {
        p->estado = 'D';
    } else { // Apenas pede o estado se não for um doente
        printf("Estado: ");
        scanf(" %c", &p->estado);
    }

    printf("Duracao: ");
    scanf(" %d", &p->duracao);

    p->prox = NULL;

    getchar();
    return p;
}

int verificarPessoas(pPessoa p) {
    pPessoa aux;

    while(p->prox != NULL) {
        aux = p->prox;

        // Confirmar a não existência de IDs repetidos
        while (aux->prox != NULL) {
            if (!strcmp(aux->id, p->id)) {
                printf("ERRO: Nome %s repetido!\n", p->id);
                return 0;
            }
            aux = aux->prox;
        }

        // Confirmar a não existência de idades negativas
        if (p->idade < 0) {
            printf("ERRO: Idade de %s nao positiva!\n", p->id);
            return 0;
        }

        // Confirmar a não existência de estados errados
        if (!(p->estado == 'S' || p->estado == 'I' || p->estado == 'D')) {
            printf("ERRO: Estado de %s invalido!\n", p->id);
            return 0;
        }

        if (p->estado == 'D') {
            if (p->duracao < 1) {
                printf("ERRO: Duracao de infecao de %s nao positiva!\n", p->id);
                return 0;
            }
        }

        p = p->prox;
    }
    return 1;
}

pPessoa inserirFimPessoas(pPessoa lista, pPessoa p) {
    pPessoa aux;

    p->prox = lista;
    lista = p;

    /*
    if (lista == NULL) {
        lista = p;
    } else {
        aux = lista;
        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = p;
    }
     */
    return lista;
}

plocal deepcopy(plocal origem, int tam) { // tudo fodido
    int i;
    pPessoa listaOrigem, novaPessoa;
    plocal novo = malloc(tam*sizeof(local));

    if (novo == NULL) {
        printf("ERRO: Alocacao de memoria falhou!\n");
        return NULL;
    }
    
    for (i = 0; i < tam; i++) {
        novo[i] = origem[i];

        listaOrigem = origem[i].lista;
        novo[i].lista = NULL;
        while (listaOrigem != NULL) {
            novaPessoa = malloc(sizeof(pessoa));

            *novaPessoa = *listaOrigem;
            novaPessoa->prox = NULL;

            novo[i].lista = inserirFimPessoas(novo[i].lista, novaPessoa);

            listaOrigem = listaOrigem->prox;
        }

    }
    return novo;
}

pstat gerarStat(plocal vetor, int tam, int iteracao, const int nTotais[3]) {
    int nPessoas = nTotais[0], nInfetados = nTotais[1], nImunes = nTotais[2];

    pstat ps = malloc(sizeof(stat));
    if (ps == NULL) {
        printf("ERRO: Alocacao de memoria falhou!\n");
        return NULL;
    }

    ps->locais = deepcopy(vetor, tam);
    ps->tam = tam;
    ps->iteracao = iteracao;
    ps->nPessoas = nPessoas;
    ps->tInfetados = (float)nInfetados/(float)nPessoas;
    ps->tImunes = (float)nImunes/(float)nPessoas;
    ps->tSaudaveis = ((float)nPessoas-(float)nInfetados-(float)nImunes)/(float)nPessoas;
    ps->prox = NULL;

    return ps;
}

void apresentarStat(pstat info, FILE* f) {
    fprintf(f, "-----ESTATISTICA: ITERACAO %d-----\n", info->iteracao);
    listPopulacao(info->locais, info->tam, f);
    fprintf(f, "\nTaxa de Saudaveis: %.2f\n", info->tSaudaveis);
    fprintf(f, "Taxa de Imunes: %.2f\n", info->tImunes);
    fprintf(f, "Taxa de Infetados: %.2f\n", info->tInfetados);
    fprintf(f, "\nTotal de Individuos: %d\n", info->nPessoas);
}

pstat inserirStat(pstat stats, pstat novaStat) {
    novaStat->prox = stats;
    stats = novaStat;

    return stats;
}

int numPessoas(pPessoa lista) {
    int tam = 0;

    while (lista != NULL) {
        tam++;
        lista = lista->prox;
    }

    return tam;
}

void designarPessoas(plocal vetor, int tam, pPessoa lista, int* nTotais) {
    pPessoa ant = NULL;
    int pos;                // Posição no array dinâmico do espaço escolhido aleatoriamente
    int i, cheio;

    putchar('\n');
    while (lista != NULL) { // Atribuir um espaco a cada pessoa
        cheio = 1;
        do {
            for(i = 0; i < tam; i++)
                if (vetor[i].capacidade - vetor[i].numPessoas != 0)
                    cheio = 0;

            printf("teste2");
            if (cheio) {
                printf("\nERRO: Populacao demasiado grande!\n\n");
                return;
            } else
                pos = intUniformRnd(0, tam-1);

        } while (vetor[pos].capacidade - vetor[pos].numPessoas == 0); // Continuar a gerar posicoes aleatorias enquanto o espaço escolhido estiver cheio

        //vetor[pos].capacidade--;
        vetor[pos].numPessoas++;

        ant = lista;
        lista = lista->prox;
        ant->prox = NULL;

        nTotais[0]++;
        if (ant->estado == 'D')
            nTotais[1]++;
        if (ant->estado == 'I')
            nTotais[2]++;

        vetor[pos].lista = inserirFimPessoas(vetor[pos].lista, ant);

        printf("%s inserido(a) no local %d\n", ant->id, vetor[pos].id);
    }

    freeLigada(lista);
    putchar('\n');
}

int tentarCurar(pPessoa individuo, int* nTotais) {
    int dMaxima = 5 + (individuo->idade/10);; // Duracao maxima da infeção
    float pRecuperacao = 1/(float)individuo->idade; // Probabilidade de recuperação
    int curada = 0;

    if (individuo->duracao > dMaxima || probEvento(pRecuperacao)) { // Se passou a duração máxima da infeção ou se se recuperou
        individuo->duracao = 0;
        nTotais[1]--;
        curada = 1;

        printf("%s recuperou", individuo->id);
        if (probEvento(TIMUN)) { // Pessoa foi curada, tem chance de ficar imune
            individuo->estado = 'I';
            nTotais[2]++;
            printf(" e tornou-se imune!\n");
        }
        else {
            individuo->estado = 'S';
            printf(".\n");
        }
    }

    return curada;
}

pPessoa removerPessoa(pPessoa lista, pPessoa p) {
    pPessoa aux = lista;

    if (lista == p)
        lista = p->prox;
    else {
        while (aux->prox != p) {
            aux = aux->prox;
        }

        if (aux->prox == NULL) {
            printf("ERRO: Pessoa nao encontrada!\n");
            return NULL;
        }

        aux->prox = p->prox; // Remover p da lista
    }

    p->prox = NULL;
    return lista;
}

pPessoa escolherPessoaAleatorio(pPessoa pop, int nPessoas) {
    int num = intUniformRnd(0, nPessoas-1);

    for (; num > 0; num--)
        pop = pop->prox;

    return pop;
}

void freeLigada(pPessoa lista) {
    pessoa* aux;

    while(lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }
}

void freeLocais(plocal vetor, int tam) {
    int i;

    for (i = 0; i < tam; i++) {
        freeLigada(vetor[i].lista);
    }

    free(vetor);
}

void freeStat(pstat stat, int tam) {
    freeLocais(stat->locais, tam);
    free(stat);
}
