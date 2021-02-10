#include <stdio.h>
#include <stdlib.h>

//2 extern char **environ;
void ex12(int argc, char ** argv) {
    char nome[256] = {"\0"}, valor[256] = {"\0"}, *p = NULL;

    printf("Nome da var: ");
    scanf("%s", nome);

    printf("Valor a dar: ");
    scanf("%s", valor);

    setenv(nome, valor, 1); // Criar a variável, overwriting se existir (por causa do 1) 

    p = getenv(nome); // Lervariável com um determinado nome

   if(p != NULL) {
       printf("Variavel: %s = %s", nome, *p);
   }
}
    

int main(int argc, char **argv) { // 1 char *envp[]
    int i = 0;

    char s[] = "PATH", *p = NULL;

    //falta um setenv
    p = getenv(s);

    /* 1
    for (i = 0; envp[i] != NULL; i++) {
        printf("envp[%i] %s \n", i, envp[i]);
    }
    */

   /* 2
   for (i = 0; environ[i] != NULL; i++) {
       printf("environ[%i] %s\n", i, environ[i]);
   }
   */

   for (i = 0; p[i] != NULL; i++) {
       printf("environ[%i] %s\n", i, p[i]);
   }

    return 0;
}