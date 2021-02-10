#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ex4-utils.h"

#define CLI_MAX 20
#define CLI_FILE "banco"

typedef struct cli {
    char nome[STR_SIZE];
    float saldo;
} cli;

typedef struct PARAM {
    cli *arr;
    int *arrlen;
    int cancel;
    pthread_mutex_t *myLock;
} PARAM;

