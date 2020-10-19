#include <stdio.h>

int posMaior(int tab[], int tam){

    int pos = 0;

    for(int i = 0 ; i < tam ; i++){

        if(tab[i] > tab[pos])
            pos = i;
    }

    return pos;
}

int contaMaior(int tab[], int tam){

    int maior = tab[0], conta = 1;

    for(int i = 1 ; i < tam ; i++){
        if(tab[i] > maior){
            maior = tab[i];
            conta = 1;
        }
        else if(tab[i] == maior){
            conta++;
        }
    }
    return conta;
}

int main() {

    int tab[8] = {-2,15,7,15,15,6,8,11};
    int pos, conta;

    pos = posMaior(tab,8);
    conta = contaMaior(tab,8);

    printf("%d \t %d\n", pos, conta);

    return 0;
}