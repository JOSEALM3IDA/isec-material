#include <stdio.h>


#include <stdio.h>
#include <string.h>
#include <ctype.h>


int maisComum(char *nomeF) {
    FILE *f;
    int c, maior = 0;
    int numeroVogais[5] = {0};

    f = fopen(nomeF, "r");
    if (f == NULL)
        printf("Ficheiro nao existe\n");
    else {
        while ((c = fgetc(f)) != EOF) {
            c = tolower(c);
            switch (c) {
                case 'a':
                    numeroVogais[0]++;
                    break;
                case 'e':
                    numeroVogais[1]++;
                    break;
                case 'i':
                    numeroVogais[2]++;
                    break;
                case 'o':
                    numeroVogais[3]++;
                    break;
                case 'u':
                    numeroVogais[4]++;
                    break;
                default:
                    break;
            }
        }
        fclose(f);
    }

    for (c = 0; c < 5; c++)
        if (numeroVogais[c] > maior)
            maior = numeroVogais[c];

    return maior;
}

int main(){

    printf("Numero: %d\n", maisComum("file.txt"));

    return 0;
}