#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct t {
    char c;
    int cancel;
};

void *routine(void *arg) {
    struct t *s = (struct t *)arg;
    int i, n;

    while (!s->cancel) {
        n = 1 + rand() % 5;
        for (i = 0; i < n; i++) {
            printf(".");
            sleep(1);
        }

        for (i = 0; i < 3; i++) {
            printf("%c", s->c);
            sleep(1);
        }
    }
}

void main() {
    pthread_t th[2];
    struct t sA, sB;
    char str[16];

    setbuf(stdout, NULL);
    srand(time(NULL));

    sA.c = 'A';
    sB.c = 'B';
    sA.cancel = sB.cancel = 0;

    printf("Vou comecar! Digite \"sair\" para sair.\n");

    pthread_create(&th[0], NULL, &routine, &sA);
    pthread_create(&th[1], NULL, &routine, &sB);

    do {
        scanf(" %s", str);
    } while (strcmp(str, "sair"));

    sA.cancel = 1; // pedir à thread A para sair
    //pthread_cancel(th[0]); // apenas por segurança
    pthread_join(th[0], NULL); // esperar que a thread A acabe

    sB.cancel = 1; // pedir à thread B para sair
    //pthread_cancel(th[1]); // apenas por segurança
    pthread_join(th[1], NULL); // esperar que a thread B acabe
}