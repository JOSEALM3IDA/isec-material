// Trabalho Pratico Programacao - LEICE
// DEIS-ISEC 2019-2020
// José Almeida - 2019129077

#include "utils.h"
#include "utilFiles.h"
#include "utilStructs.h"

int iniciar();

int main() {
    char escolha;                 // Escolha do utilizador no menu

    initRandom();          // Esta função só deve ser chamada uma vez

    while(1) {
        escolha = '0';

        printf("\n--------------MENU--------------\n");
        printf("1. Iniciar Simulacao\n2. Criar Novo Ficheiro de Espacos");
        printf("\n3. Listar Espacos\n4. Verificar Ficheiro de Espacos\n5. Criar Novo Ficheiro de Pessoas\n");
        printf("6. Listar Pessoas\n7. Verificar Ficheiro de Pessoas\n8. Sair\n");

        printf("\nOpcao: ");
        scanf("%c", &escolha);

        while (getchar() != '\n'); // Descartar eventuais inputs desnecessarios ou errados (limpar buffer)

        switch (escolha) {
            case '1': // Iniciar Simulação
                iniciar();
                break;

            case '2': // Criar Novo Ficheiro de Espaços
                criarFicheiro('b');
                break;

            case '3': // Listar Espacos
                listarFicheiro('b');
                break;

            case '4': // Verificar Ficheiro de Espacos
                verificarFicheiro('b');
                break;

            case '5': // Criar Novo Ficheiro de Pessoas
                criarFicheiro('t');
                break;

            case '6': // Listar Populacao
                listarFicheiro('t');
                break;

            case '7': // Verificar Ficheiro de Pessoas
                verificarFicheiro('t');
                break;

            case '8': // Sair
                printf("A terminar programa...\n");
                return 1;

            default:
                printf("Opcao nao reconhecida! Por favor tente novamente.\n");
                break;
        }
    }
}

int iniciar() {
    char fileName[MAX];
    plocal vLocais = NULL;        // Vetor dinâmico para onde está a informaçao dos espaços
    int tam;                      // Tamanho atual do vetor dinâmico vetorLocais
    pPessoa listaPessoas = NULL;  // Lista ligada que contem toda a informacão da população
    char escolha;                 // Escolha do utilizador no menu
    int iteracao = 0;             // Iteracao atual
    int nTotais[3] = {0};         // Vetor que contem os numeros totais de pessoas, infetados e imunes
    pstat stats = NULL;           // Lista ligada que contem a informacao de todas as iteracoes
    pstat novaStat;


    printf("\n-------FICHEIRO DOS LOCAIS-------");
    do {
        pedirFicheiro(fileName, "bin", "rb");

        vLocais = lerBinario(fileName, &tam);

        if (!vLocais || !verificarLocais(vLocais, tam)) {
            printf("A informacao do ficheiro nao parece estar correta! Por favor forneca outro ficheiro.\n\n");
            free(vLocais);
            vLocais = NULL;
        }
    } while (!vLocais);

    printf("\n-------FICHEIRO DAS PESSOAS-------");
    do {
        pedirFicheiro(fileName, "txt", "r");

        listaPessoas = lerTxt(fileName);

        if (!listaPessoas || !verificarPessoas(listaPessoas)) {
            printf("A informacao do ficheiro nao parece estar correta! Por favor forneca outro ficheiro.\n\n");
            freeLigada(listaPessoas);
            listaPessoas = NULL;
        }
    } while (!listaPessoas);

    printf("\nA inserir pessoas nos espacos aleatoriamente...\n");
    designarPessoas(vLocais, tam, listaPessoas, nTotais);

    novaStat = gerarStat(vLocais, tam, iteracao, nTotais);
    stats = inserirStat(stats, novaStat);
    apresentarStat(stats, stdout);

    while(1) {
        escolha = '0';

        printf("\n--------------MENU ITERACAO %d--------------\n", iteracao);
        printf("1. Avancar 1 Iteracao na Simulacao\n2. Apresentar Estatistica");
        printf("\n3. Adicionar Doente\n4. Transferir Pessoas\n5. Voltar Atras X Iteracoes (Undo X)\n");
        printf("6. Terminar Simulacao\n");

        printf("\nOpcao: ");
        scanf("%c", &escolha);

        while (getchar() != '\n'); // Descartar eventuais inputs desnecessarios ou errados (limpar buffer)

        putchar('\n');

        switch (escolha) {
            case '1': // Avancar 1 Iteracao na Simulacao
                avancarIteracao(vLocais, tam, &iteracao, nTotais);
                novaStat = gerarStat(vLocais, tam, iteracao, nTotais); // Atualizar stat
                stats = inserirStat(stats, novaStat); // Insercao no inicio da lista ligada
                break;

            case '2': // Apresentar Estatistica
                apresentarStat(stats, stdout);
                break;

            case '3': // Adicionar Doente
                adicionarDoente(vLocais, tam, &nTotais[0], &nTotais[1]);
                novaStat = gerarStat(vLocais, tam, iteracao, nTotais); // Atualizar stat
                novaStat->prox = stats->prox;   // Substituicao do primeiro nó da lista ligada
                freeStat(stats, tam);           //
                stats = novaStat;               //
                break;

            case '4': // Transferir Pessoas
                transferirPessoas(vLocais, tam);
                novaStat = gerarStat(vLocais, tam, iteracao, nTotais); // Atualizar stat
                novaStat->prox = stats->prox;   // Substituicao do primeiro nó da lista ligada
                freeStat(stats, tam);           //
                stats = novaStat;               //
                break;

            case '5': // Voltar Atras X Iteracoes (Undo X)
                stats = recuarIteracoes(&vLocais, tam, stats, &iteracao, nTotais);
                break;

            case '6': // Terminar Simulação
                terminarSimulacao(stats, tam);
                while(stats != NULL) {
                    freeStat(stats, tam);
                    stats = stats->prox;
                }
                //freeLigada(listaPessoas);
                freeLocais(vLocais, tam);
                printf("Simulacao executada com sucesso.\n");
                return 1;

            default:
                printf("Opcao nao reconhecida! Por favor tente novamente.\n");
                break;
        }
    }
}
