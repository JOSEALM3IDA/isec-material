#include <stdio.h>
#include <string.h>

int main() {
    char st1[20], st2[20], res[60];

    printf("Strings:\n");
    gets(st1);
    gets(st2);

    if(strcmp(st1,st2) == 0) //strcmp retorna 0 se iguais, retorna < 0 se st1 aparecer primeiro no dicionario que st2, e > 0, o contrario
        strcpy(res,"IGUAIS!"); //copia "IGUAIS" para st1
    else if(strlen(st1) == strlen(st2))
        strcpy(res,"MESMO TAMANHO");
    else if(strcmp(st1,st2) < 0){
        strcpy(res,st1);
        strcat(res,st2);
    }
    else{
        strcpy(res,st2);
        strcat(res,st1);
    }

    printf("%s",res);

    return 0;
}
