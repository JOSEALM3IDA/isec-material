// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2019-2020
// José Almeida - 2019129077

#include "utils.h"
#include "utilStructs.h"
#include "utilFiles.h"

void initRandom() {
    srand(time(NULL));
}

int intUniformRnd(int a, int b) {
    return a + rand()%(b-a+1);
}

int probEvento(float prob) {
    return prob > ((float)rand()/RAND_MAX);
}

void disseminar(pPessoa pop, int nPessoas, int nDiss, int *nInfetados) {
    pPessoa aux;

    for(; nDiss > 0; nDiss--) {
        aux = escolherPessoaAleatorio(pop, nPessoas); // Escolhe uma pessoa

        if (aux->estado == 'S') { // Infeta-a, se a pessoa for saudavel (exclui doentes e imunes)
            aux->estado = 'D';
            aux->duracao = 1;
            (*nInfetados)++;
            printf("%s adoeceu.\n", aux->id);
        }
    }
}

void avancarIteracao(plocal vetor, int tam, int *iteracao, int *nTotais) {
    int i, nPessoasLocal;
    int nDiss; // Numero de individuos de uma população que são infetados se ocorrer disseminação
    pPessoa pop;

    (*iteracao)++;
    for (i = 0; i < tam; i++) { // Percorre todos os locais
        pop = vetor[i].lista;
        nPessoasLocal = numPessoas(pop);      // Numero de pessoas no local
        nDiss = (int)(nPessoasLocal * TDISS); // Numero de pessoas a serem infetadas

        while (pop != NULL) { // Pecorre toda a populacao de um local
            if (pop->estado == 'D' && !tentarCurar(pop, nTotais)) { // Se for doente e nao se curar nesta iteracao
                pop->duracao++;
                if (nDiss > 0) {
                    disseminar(vetor[i].lista, nPessoasLocal, nDiss, &nTotais[1]);
                }
            }
            pop = pop->prox;
        }
    }
}

void adicionarDoente(plocal vetor, int tam, int *nPessoas, int *nInfetados) {
    int idLocal, posVetor, i, errada;
    pPessoa p, aux;

    do {
        printf("ID do local onde inserir: ");
        scanf(" %d", &idLocal);

        if (idLocal == -1)
            return;

        posVetor = posLocal(vetor, tam, idLocal);
        if (posVetor > -1 && vetor[posVetor].capacidade > 0)
            break;

        printf("Local %d nao existe ou nao tem capacidade suficiente.\n\n", idLocal);
    } while (1);

    do {
        errada = 0;
        putchar('\n');
        p = pedirPessoa(1);

        if (p->duracao < 1) {
            printf("Duracao invalida!\n");
            errada = 1;
            free(p);
            continue;
        }

        if (p->idade < 0) {
            printf("Idade invalida!\n");
            errada = 1;
            free(p);
            continue;
        }

        for (i = 0; i < tam; i++) { // Percorre todos os locais
            aux = vetor[i].lista;
            while (aux != NULL) { // Percorre todas as pessoas de um local
                if (!strcmp(p->id, aux->id)) {
                    printf("Nome %s ja existe!\n", p->id);
                    errada = 1;
                    free(p);
                    break;
                }
                aux = aux->prox;
            }
            if (errada)
                break;
        }

    } while (errada);

    (*nPessoas)++;
    (*nInfetados)++;
    vetor[posVetor].lista = inserirFimPessoas(vetor[posVetor].lista, p);
    vetor[posVetor].numPessoas++;
    //vetor[posVetor].capacidade--;
    printf("\n%s adicionado(a) ao local %d.\n", p->id, idLocal);
}

void transferirPessoas(plocal vetor, int tam) {
    int l1, l2, n;
    int nl1; // Numero de pessoas na lista de origem
    pPessoa p;

    do {
        printf("Local de Origem: ");
        scanf(" %d", &l1);                  // Obter local de origem
        l1 = posLocal(vetor, tam, l1);      // Obter posicao no vetor onde se encontra o local de origem
        if (l1 == -1) {                     // Verificar se existe realmente esse local
            printf("ERRO: Local nao existe!\n\n");
        } else {
            break;
        }
    } while (1);

    do {
        do {
            printf("Local de Destino: ");
            scanf(" %d", &l2);                  // Obter local de destino
            l2 = posLocal(vetor, tam, l2);      // Obter posicao no vetor onde se encontra o local de destino
            if (l2 == -1) {                     // Verificar se existe realmente esse local
                printf("ERRO: Local nao existe!\n\n");
            } else {
                break;
            }
        } while (1);

        if (vetor[l1].liga[0] == vetor[l2].id ||
            vetor[l1].liga[1] == vetor[l2].id ||
            vetor[l1].liga[2] == vetor[l2].id) { // Verificar se existe ligacao
            break;
        }

        printf("ERRO: Locais %d e %d nao ligados!\n\n", vetor[l1].id, vetor[l2].id);
    } while (1);


    do {
        printf("Numero de Pessoas a Transferir: ");
        scanf(" %d", &n);                  // Obter numero de pessoas a transferir

        //nl1 = numPessoas(vetor[l1].lista);
        nl1 = vetor[l1].numPessoas;

        if (n > nl1) {
            printf("ERRO: Local %d de origem nao tem pessoas suficientes!\n", vetor[l1].id);
            continue;
        }

        if (n > vetor[l2].capacidade - vetor[l2].numPessoas) {
            printf("Erro: Local %d de destino nao tem capacidade suficiente!\n", vetor[l2].id);
            continue;
        }

        break;
    } while (1);

    putchar('\n');
    for(; n > 0; n--) {
        p = escolherPessoaAleatorio(vetor[l1].lista, nl1);

        vetor[l2].lista = inserirFimPessoas(vetor[l2].lista, p);
        vetor[l2].numPessoas++;
        //vetor[l2].capacidade--;

        vetor[l1].lista = removerPessoa(vetor[l1].lista, p);
        vetor[l1].numPessoas--;
        //vetor[l1].capacidade++;
        nl1--;

        printf("%s transferido(a) do local %d para o local %d.\n", p->id, vetor[l1].id, vetor[l2].id);
    }

    while (getchar() != '\n'); // Descartar eventuais inputs desnecessarios ou errados (limpar buffer)
}

pstat recuarIteracoes(plocal* vetor, int tam, pstat stats, int* iteracao, int* nTotais) {
    int x, i;
    pstat aux;

    do {
        printf("Numero de iteracoes a recuar: ");
        scanf(" %d", &x);

        if(x <= *iteracao)
            break;

        printf("Nao pode recuar %d iteracoes pois apenas existem %d iteracoes.\n", x, *iteracao);
    } while (1);

    //while (getchar() != '\n'); // Descartar eventuais inputs desnecessarios ou errados (limpar buffer)
    fseek(stdin, 0, SEEK_END);

    *iteracao -= x;

    for (i = 0; i < x; i++) {
        aux = stats;
        stats = stats->prox;
        freeStat(aux, tam);
    }

    *nTotais = stats->nPessoas;
    *(nTotais + 1) = (int)((float)stats->nPessoas * stats->tInfetados + 0.01); // O +0.01 está ali pois o programa estava a converter, por exemplo, float 9.00 para inteiro 8
    *(nTotais + 2) = (int)((float)stats->nPessoas * stats->tImunes + 0.01);    // Com esse 0.01, converte 9.01 para 9

    freeLocais(*vetor, tam);
    *vetor = deepcopy(stats->locais, tam);

    return stats;
}

void terminarSimulacao(pstat stats, int tam) {
    char* fnReport = "report.txt";
    FILE* fReport;
    char fnUIteracao[MAX];
    FILE* fUIteracao;
    pstat aux = stats;
    int i, nPLocal, nDLocal, nILocal, nSLocal;
    int maiorNPLocal = 0, localMNP; // Maior numero de pessoas e o respetivo local
    int maiorNDLocal = 0, localMND, maiorNDLItr = -1; // Maior numero de doentes e o respetivo local e iteracao
    int maiorNILocal  = 0, localMNI, maiorNILItr = -1; // Maior numero de imunes e o respetivo local e iteracao
    int maiorNSLocal = 0, localMNS, maiorNSLItr = -1; // Maior numero de saudaveis e o respetivo local e iteracao
    pPessoa lista;
    float maiorTInf = -1; // Maior % de infetados
    int maiorTInfItr = -1; // Iteracao da maior % de infetados
    float maiorTSaud = -1; // Maior % de saudaveis
    int maiorTSaudItr = -1; // Iteracao da maior % de saudaveis
    float maiorTImun = -1; // Maior % de imunes
    int maiorTImunItr = -1; // Iteracao da maior % de imunes
    int uIteracao = stats->iteracao;

    fReport = fopen(fnReport, "w");
    if (fReport == NULL) {
        printf("ERRO: Nao foi possivel gerar o ficheiro do relatorio!\n");
        return;
    }

    printf("-------FICHEIRO POPULACAO FINAL-------");
    pedirFicheiro(fnUIteracao, "txt", "w");
    fUIteracao = fopen(fnUIteracao, "w");
    if (fUIteracao == NULL) {
        printf("ERRO: Abertura de ficheiro falhou!\n");
        fclose(fReport);
        return;
    }

    while (aux != NULL) {
        if (aux->tInfetados > maiorTInf) { // Procurar a maior % de infetados
            maiorTInf = aux->tInfetados;
            maiorTInfItr = aux->iteracao;
        }

        if (aux->tSaudaveis > maiorTSaud) { // Procurar a maior % de infetados
            maiorTSaud = aux->tSaudaveis;
            maiorTSaudItr = aux->iteracao;
        }

        if (aux->tImunes > maiorTImun) { // Procurar a maior % de infetados
            maiorTImun = aux->tImunes;
            maiorTImunItr = aux->iteracao;
        }

        for (i = 0; i < tam; i++) {
            lista = aux->locais[i].lista;

            nPLocal = nDLocal = nILocal = 0; // Numero de pessoas / doesntes / imunes no local
            while (lista != NULL) {
                nPLocal++;
                if (lista->estado == 'D')
                    nDLocal++;
                if (lista->estado == 'I')
                    nILocal++;
                nSLocal = nPLocal - nDLocal - nILocal;

                if (nPLocal > maiorNPLocal) { // Procurar numero de pessoas
                    maiorNPLocal = nPLocal;
                    localMNP = aux->locais[i].id; // Respetivo local
                }

                if (nDLocal > maiorNDLocal) { // Procurar numero de doentes
                    maiorNDLocal = nDLocal;
                    localMND = aux->locais[i].id; // Respetivo local
                    maiorNDLItr = aux->iteracao; // Respetiva iteracao
                }

                if (nILocal > maiorNILocal) { // Procurar numero de imunes
                    maiorNILocal = nILocal;
                    localMNI = aux->locais[i].id; // Respetivo local
                    maiorNILItr = aux->iteracao; // Respetiva iteracao
                }

                if (nSLocal > maiorNSLocal) { // Procurar numero de saudaveis
                    maiorNSLocal = nSLocal;
                    localMNS = aux->locais[i].id; // Respetivo local
                    maiorNSLItr = aux->iteracao; // Respetiva iteracao
                }

                if (aux->iteracao == uIteracao) { // Para escrever a populacao da ultima iteracao
                    fprintf(fUIteracao, "%s  %d  %c", lista->id, lista->idade, lista->estado);

                    if (lista->estado == 'D') {
                        fprintf(fUIteracao, "  %d", lista->duracao);
                    }

                    fprintf(fUIteracao, "\n");
                }

                lista = lista->prox;
            }

        }
        aux = aux->prox;
    }

    apresentarStat(stats, fReport);

    fprintf(fReport, "\nMaior numero de pessoas: (%d)\nLocal: %d\n\n", maiorNPLocal, localMNP);

    fprintf(fReport, "Maior numero de doentes: %d\nLocal: %d\nIteracao: %d\n\n", maiorNDLocal, localMND, maiorNDLItr);
    fprintf(fReport, "Maior numero de imunes: %d\nLocal: %d\nIteracao: %d\n\n", maiorNILocal, localMNI, maiorNILItr);
    fprintf(fReport, "Maior numero de saudaveis: %d\nLocal: %d\nIteracao: %d\n\n", maiorNSLocal, localMNS, maiorNSLItr);

    fprintf(fReport, "\nMaior taxa de doentes: %.2f\nIteracao: %d\n\n", maiorTInf, maiorTInfItr);
    fprintf(fReport, "Maior taxa de imunes: %.2f\nIteracao: %d\n\n", maiorTImun, maiorTImunItr);
    fprintf(fReport, "Maior taxa de saudaveis: %.2f\nIteracao: %d\n\n", maiorTSaud, maiorTSaudItr);

    fclose(fReport);

    printf("\nRelatorio guardado com sucesso.\n\n");

    fclose(fUIteracao);
}