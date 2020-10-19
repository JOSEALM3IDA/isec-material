#include <stdio.h>
#include <string.h>

void linhas(char st[]){
    int i, tam = strlen(st);

    for(i = 0; i < tam; i++){
        if(st[i] == ' ' && st[i+1] != ' ')
            putchar('\n');
        else
            putchar(st[i]);
    }
}

int main() {
    char st[50];

    printf("String:\n");
    gets(st);

    linhas(st);

    return 0;
}
