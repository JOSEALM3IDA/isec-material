#include <stdio.h>
#define TAMANHO 44

/*
int pesquisa(int tab[], int tam, int num){

    for(int i = 0; i < tam; i++){
        if(tab[i] > num)
            break;

        if(tab[i] == num)
            return 1;
    }

    return 0;
}
*/

/*
int pesquisa(int tab[], int tam, int num){

    int j = 0;

    if(num < tab[0])
        return 0;

    if(num > tab[tam-1])
        return 0;


    while(j < tam && tab[j++] < num);

    if(tab[--j] > num)
        return 0;

    return 1;
}
*/

//PESQUISA BINARIA//

int pesquisa(int tab[], int tam, int num){

    int minimo = 0, M, maximo = tam-1;

    while(minimo + 1 < maximo){

        M = (int)((minimo + maximo) / 2);

        if (num == tab[M]){
            return 1;
        }
        else if(num < tab[M]){
            maximo = M;
        }
        else{
            minimo = M;
        }
    }

    return 0;
}


int main() {

    int tab[TAMANHO] = {0,3,6,8,15,17,18,24,28,29,31,35,36,40,46,48,52,55,56,63,73,82,83,84,85,91,92,101,102,105,106,107,108,111,113,115,124,125,134,139,144,147,149,152};

    printf("\n%d\n", pesquisa(tab, TAMANHO, 46));

    return 0;
}
