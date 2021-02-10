#include "ex4-servidor.h"

cli* preencheArray(cli *arr, int *tam) {
    FILE* fd;
    cli *temp;
    int n;
    char nome[STR_SIZE];
    float saldo;
    char buff[BUFF_SIZE];
    
    *tam = 0;
    
    if ((fd = fopen(CLI_FILE, "r")) == NULL)
        return NULL;

    while(fscanf(fd, "%s %f\n", nome, &saldo) != EOF) {
        if ((temp = realloc(arr, sizeof(cli) * (*tam + 1))) == NULL)
            return arr;
        arr = temp;
        strcpy(arr[*tam].nome, nome);
        arr[*tam].saldo = saldo;
        (*tam)++;
    }

    return arr;
}

int findCli(char* nome, cli *arr, int *tam) {
    int i;

    for (i = 0; i < *tam; i++) {
        if (strcmp(nome, arr[i].nome) == 0) {
            return i;
        }
    }

    return -1;
}

void* routine(void *arg) {
    PARAM *s = (PARAM *)arg;
    int i, n, fd_serv, fd_cli, idx;
    cli *temp;
    char buff[BUFF_SIZE], nome[STR_SIZE], pid[STR_SIZE], cmd[STR_SIZE];

    if ((fd_serv = open(SERV_PIPE, O_RDWR)) == -1) {
        fprintf(stderr, "ERRO ao abrir o meu pipe.\n");
        unlink(SERV_PIPE);
        exit(-1);
    }

    while (!s->cancel) {
        if ((n = read(fd_serv, buff, sizeof(buff) - 1)) == -1) {
            fprintf(stderr, "ERRO ao ler do meu pipe.\n");
            break;
        }
        buff[n] = '\0';

        sscanf(buff, "%s %s %[^\n]", nome, pid, cmd);

        if ((fd_cli = open(pid, O_WRONLY)) == -1) {
            printf("ERRO ao abrir pipe do cliente.\n");
            unlink(SERV_PIPE);
            return NULL;
        }

        // LIMPAR BUFFER
        for (n = 0; n < BUFF_SIZE; n++) buff[n] = '\0';

        if ((idx = findCli(nome, s->arr, s->tam)) == -1) {
            temp = realloc();
            if (!temp) {
                fprintf(stderr, "ERRO no realloc.\n");
                break;
            }

            s->arr = temp;
            strcpy(s->arr[*(s->tam)].nome, nome);
            s->arr[*(s->tam)].saldo = 0;
            *(s->tam)++;
        }

        if (strcmp("saldo", cmd) == 0) {
            temp = s->arr[findCli(nome, s->arr, s->arrlen)].saldo;
            sprintf(buff, "%d", temp);
        } else if () {
            return NULL;
        }

        if ((n = write(fd_cli, buff, strlen(buff))) == -1) {
            fprintf(stderr, "ERRO ao ler do meu pipe.\n");
            break;
        }

        close(fd_cli);
        //pthread_mutex_lock(s->myLock);
        //pthread_mutex_unlock(s->myLock);
    }
    

    close(fd_serv);
    unlink(SERV_PIPE);
}

void main() {
    pthread_t th;
    PARAM s;
    char str[16];
    pthread_mutex_t myLock;
    cli *arr = NULL;
    int tam, i;

    setbuf(stdout, NULL);

    if (mkfifo(SERV_PIPE, 0777) == -1) {
        fprintf(stderr, "ERRO ao criar o meu pipe.\n");
        exit(-1);
    }

    //arr = preencheArray(arr, &tam);

    s.arr = arr;
    s.arrlen = &tam;
    s.cancel = 0;
    s.myLock = &myLock;
    
    pthread_mutex_init(&myLock, NULL);
    printf("Vou comecar! Digite \"sair\" para sair.\n");

    pthread_create(&th, NULL, &routine, &s);

    do {
        scanf(" %s", str);
    } while (strcmp(str, "sair"));

    s.cancel = 1; // pedir à thread para sair
    pthread_join(th, NULL); // esperar que a thread acabe

    pthread_mutex_destroy(&myLock);
}