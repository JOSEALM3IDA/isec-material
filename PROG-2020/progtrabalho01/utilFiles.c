// Trabalho Pratico Programacao - LEICE
// DEIS-ISEC 2019-2020
// José Almeida - 2019129077

#include "utilFiles.h"

void pedirFicheiro(char *fileName, char ext[3], const char tipo[3]) {
    FILE *ficheiro;
    unsigned int tam;
    int i;

    do {
        printf("\n-> Nome do ficheiro: ");
        scanf(" %[^\n]%*c", fileName);  // %[^\n]%*c -> lê até ao char \n e com o %*c faz discard a esse \n

        tam = strlen(fileName);

        for (i = 1; i < 4; i++)
            fileName[tam-i] = tolower(fileName[tam-i]);

        if (fileName[tam-4] != '.' ||     // Verifica se a extensão do ficheiro é ext
            fileName[tam-3] != ext[0] ||
            fileName[tam-2] != ext[1] ||
            fileName[tam-1] != ext[2])
        {
            printf("ERRO: O ficheiro nao tem a extensao %s.\n", ext);
            ficheiro = NULL;
            continue;
        }

        ficheiro = fopen(fileName, tipo);
        if (ficheiro == NULL) {
            printf("ERRO: Abertura de ficheiro falhou!\n");
        }

    } while (!ficheiro);
    printf("Ficheiro encontrado!\n");
    fclose(ficheiro);
}

plocal lerBinario(char fileName[100], int* tam) {
    FILE* ficheiro;
    plocal vetor = NULL, p;
    local room;
    sler leitura;
    int i;

    *tam = 0;

    ficheiro = fopen(fileName, "rb");

    while (fread(&leitura, sizeof(sler), 1, ficheiro)) {

        p = realloc(vetor, sizeof(local) * (*tam + 1));

        if (p == NULL) {
            printf("\nERRO: Realloc falhou!\n");
            free(vetor);
            fclose(ficheiro);
            *tam = 0;
            return NULL;
        }

        vetor = p;

        room.id = leitura.id;
        room.capacidade = leitura.capacidade;
        for (i = 0; i < 3; i++)
            room.liga[i] = leitura.liga[i];

        room.numPessoas = 0;
        room.lista = NULL;

        vetor[*tam] = room;

        (*tam)++;
    }

    fclose(ficheiro);

    if (*tam == 0) {
        printf("\nERRO: Ficheiro vazio!\n");
        return NULL;
    }

    return vetor;
}

pessoa* lerTxt(char fileName[MAX]) {
    FILE *ficheiro = NULL;
    char c, str[MAX];
    int idade, vazio;
    pessoa *lista = NULL, *p;

    ficheiro = fopen(fileName, "r");
    if (ficheiro == NULL) {
        printf("ERRO: Nao foi possivel abrir o ficheiro!\n");
        return NULL;
    }

    while(fscanf(ficheiro, " %s %d %c", str, &idade, &c) == 3) {
        vazio = 0;

        p = malloc(sizeof(pessoa));
        if (p == NULL) {
            printf("ERRO: Alocacao de memoria falhou!\n");
            return NULL;
        }

        strcpy(p->id, str);
        p->idade = idade;
        p->estado = c;

        if (c == 'D') {
            fscanf(ficheiro, " %d", &p->duracao);
        } else {
            p->duracao = 0;
        }

        p->prox = NULL;
        lista = inserirFimPessoas(lista, p);
    }

    if (vazio)
        printf("ERRO: Ficheiro vazio!\n");

    fclose(ficheiro);
    return lista;
}

void criarFicheiro(char tipo) {
    FILE* ficheiro = NULL;
    char fileName[MAX];

    if (tipo == 'b') {
        int nEspacos = 0, i;
        sler espaco;

        printf("\n-----CRIAR FICHEIRO ESPACOS-----");
        pedirFicheiro(fileName, "bin", "wb");

        ficheiro = fopen(fileName, "wb");
        if (ficheiro == NULL) {
            printf("ERRO: Abertura de ficheiro falhou!");
            return;
        }

        do {
            printf("\nNumero de espacos que pretende inserir: ");
            scanf("%d", &nEspacos);

            if (nEspacos > 0)
                break;

            printf("Por favor introduza um numero valido de espacos.\n");
        } while (1);


        for (i = 0; i < nEspacos; i++) {
            printf("\nEspaco %d\n", i+1);

            printf("Id: ");
            scanf(" %d", &espaco.id);

            printf("Capacidade: ");
            scanf(" %d", &espaco.capacidade);

            printf("Ligacoes: ");
            scanf(" %d %d %d", &espaco.liga[0], &espaco.liga[1], &espaco.liga[2]);

            fwrite(&espaco, sizeof(sler), 1, ficheiro);

            while (getchar() != '\n'); // Descartar eventuais inputs desnecessarios ou errados (limpar buffer)
        }
    } else if (tipo == 't') {
        int nPessoas = 0, i;
        pessoa p;

        printf("\n-----CRIAR FICHEIRO PESSOAS-----");
        pedirFicheiro(fileName, "txt", "w");

        ficheiro = fopen(fileName, "w");
        if (ficheiro == NULL) {
            printf("ERRO: Abertura de ficheiro falhou!");
            return;
        }

        do {
            printf("\nNumero de pessoas que pretende inserir: ");
            scanf("%d", &nPessoas);

            if (nPessoas > 0)
                break;

            printf("Por favor introduza um numero valido de pessoas.\n");
        } while (1);

        for (i = 0; i < nPessoas; i++) {
            printf("\nPessoa %d\n", i+1);
            p = *pedirPessoa(0);
            fprintf(ficheiro, "%s %d %c %d\n", p.id, p.idade, p.estado, p.duracao);
        }
    }

    fclose(ficheiro);
}

void listarFicheiro(char tipo) {
    FILE *ficheiro = NULL;
    char fileName[MAX];


    if (tipo == 'b') {
        local espaco;
        pedirFicheiro(fileName, "bin", "rb");

        ficheiro = fopen(fileName, "rb");
        if (ficheiro == NULL) {
            printf("ERRO: Nao foi possivel abrir o ficheiro!\n");
            return;
        }

        while(fread(&espaco, sizeof(sler), 1, ficheiro)) {
            espaco.lista = NULL;
            listLocal(espaco);
            putchar('\n');
        }

    } else if (tipo == 't') {
        pessoa pessoa1;

        pedirFicheiro(fileName, "txt", "r");
        ficheiro = fopen(fileName, "r");
        if (ficheiro == NULL) {
            printf("ERRO: Nao foi possivel abrir o ficheiro!\n");
            return;
        }

        printf("ID\t\tIDADE\tESTADO\tDURACAO\n");
        while(fscanf(ficheiro, " %s %d %c %d", pessoa1.id, &pessoa1.idade, &pessoa1.estado, &pessoa1.duracao) != EOF) {
            if (pessoa1.estado != 'D')
                pessoa1.duracao = 0;

            listPessoa(pessoa1, stdout);
        }
    }
    fclose(ficheiro);
}

void verificarFicheiro(char tipo) {
    char fileName[MAX];

    if (tipo == 'b') {
        plocal vetorLocais;
        int tam;

        pedirFicheiro(fileName, "bin", "rb");
        vetorLocais = lerBinario(fileName, &tam);
        if((vetorLocais != NULL) && verificarLocais(vetorLocais, tam))
            printf("A informacao do ficheiro encontra-se no estado pretendido.\n");

        free(vetorLocais);

    } else if (tipo == 't') {
        pessoa* pessoas;

        pedirFicheiro(fileName, "txt", "r");
        pessoas = lerTxt(fileName);
        if((pessoas != NULL) && verificarPessoas(pessoas))
            printf("A informacao do ficheiro encontra-se no estado pretendido.\n");

        freeLigada(pessoas);
    }
}