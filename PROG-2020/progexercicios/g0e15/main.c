#include <stdio.h>
#include <string.h>

void removerEspacos(char frase[]){
    int i, j, tam = strlen(frase);

    if(frase[0] == ' ')
        for(j = 0; j < tam; j++)
            frase[j] = frase[j+1];

    for(i = 0; i < tam; i++){
        if(frase[i] == ' ' && frase[i+1] == ' ') {

            while (frase[i+1] == ' '){
                for (j = i + 1; j < tam; j++)
                    frase[j] = frase[j+1];

            frase[--tam] = '\0';
            }
        }
    }

    if(frase[tam-1] == ' ')
        frase[tam-1] == '\0';
}

int main() {
    char st[50];

    printf("String:\n");
    gets(st);

    removerEspacos(st);

    printf("%s",st);

    return 0;
}
