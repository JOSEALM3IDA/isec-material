#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    int i = 0;
    char palavra[256] = "\0";

    setbuf(stdout, NULL);

    printf("port ou ingl? ");
    scanf("%s", palavra);

    execlp(palavra, palavra, NULL); // funciona com o ls, não funciona com o port e ingl, funciona com /home/justt/Desktop/Code/aula28out/port
    //execl(palavra, palavra, NULL); // não funciona com o ls, funciona com o port e ingl

/*
    //if(fork() == 0) {
        if (!strcmp(palavra, "port"))
            execl("./port", "port", NULL);
        else if (!strcmp(palavra, "ingl"))
            execl("./ingl", "ingl", NULL);
    //}
*/

    printf("Missao Cumprida!\n");
        
    return 0;
}