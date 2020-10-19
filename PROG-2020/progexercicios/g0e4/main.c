#include <stdio.h>

int maisVezes(int tab[], int tam){

    int maisComum = tab[0], vezesComum = 0, conta = 0;

    for (int j = 0; j < tam; ++j) {
        for(int i = 0; i < tam; i++){
            if(tab[i] == tab[j]){
                conta++;
            }
        }

        if(conta == vezesComum && tab[j] > maisComum){
            maisComum = tab[j];
            vezesComum = conta;
        }
        else if(conta > vezesComum){
            maisComum = tab[j];
            vezesComum = conta;
        }

        conta = 0;
    }
    return maisComum;
}


int main() {

    int tab[8] = {4,22,2,0,1,0,2,11};
    int mais;

    mais = maisVezes(tab, 8);

    printf("Elemento mais comum: %d\n", mais);
    return 0;
}
