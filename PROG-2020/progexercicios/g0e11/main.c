#include <stdio.h>
#include <string.h>

void inverterString(char frase[]){
    int i, j = 0;
    char copy[50];

    strcpy(copy,frase);

    for(i = strlen(frase) - 1; i >= 0; i--)
        frase[j++] = copy[i];

    frase[j] = '\0';
}

int main() {
    char st[50];

    printf("String:\t");
    gets(st);

    inverterString(st);

    puts(st);
    return 0;
}
