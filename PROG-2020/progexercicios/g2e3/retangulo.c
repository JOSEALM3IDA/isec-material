//
// Created by josec on 24/03/2020.
//

#include "retangulo.h"
#include "ponto.h"

//alinea 3b)
void addR(retangulo* tab, int* total) {
    if (*total >= 10) {
        printf("Nao existe espaco na tabela.");
        return;
    } else {
        retangulo r;
        int pos, i;
        float area, novaArea;

        initR(&r);
        
        novaArea = r.larg * r.alt;

        for(pos = 0; pos < *total; pos++) {
            area = tab[pos].larg * tab[pos].alt;
            if(novaArea <= area)
                break;
        }

        for(i = *total; i >= pos; i--)
            tab[i] = tab[i - 1];

        tab[pos] = r;
        //tab[*total] = r;
        (*total)++;
    }
}

//alinea 3c)
void escreveTodosR(retangulo* tab, int total){
    int i;
    for(i = 0; i < total; i++){
        printf("\nRetangulo: %d", i);
        printf("\nCanto Inferior Esquerdo: ");
        printPonto(tab[i].cie);
        printf("Largura: %d\n", tab[i].larg);
        printf("Altura: %d\n", tab[i].alt);
        putchar('\n');
    }

}

//alinea 3d)
void eliminaR(retangulo* tab, int* total){
    if(*total < 1)
        return;
    else if(*total == 1) {
        (*total)--;
        return;
    }

    int i, posMenor;
    float area, menorArea;

    //menorArea = tab[0].alt * tab[0].larg;
    posMenor = 0;

    /*
    printf("Area Retangulo 0: %.1f", menorArea);


    for(i = 1; i < *total; i++){
        area = tab[i].larg * tab[i].alt;
        printf("\nArea Retangulo %d: %.1f", i, area);
        if(area < menorArea){
            menorArea = area;
            posMenor = i;
        }
    }
     */
    printf("\nEliminado Retangulo %d", posMenor);

    //tab[posMenor] = tab[(*total) - 1];

    for(i = posMenor; i < (*total - 1); i++)
        tab[i] = tab[i + 1];

    (*total)--;
}

//alinea 2b)
void printR(retangulo r){
    ponto2D temp;
    temp.x = r.cie.x;
    temp.y = r.cie.y;

    printf("Canto Inferior Esquerdo: ");
    printPonto(temp);

    printf("Canto Inferior Direito: ");
    movePonto(&temp, r.larg, 0);
    printPonto(temp);

    printf("Canto Superior Direito: ");
    movePonto(&temp, 0, r.alt);
    printPonto(temp);

    printf("Canto Superior Esquerdo: ");
    movePonto(&temp, -r.larg, 0);
    printPonto(temp);
}

// alinea 2c)
void initR(retangulo* r){
    printf("Insira x e y do canto superior esquerdo: ");
    scanf("%d %d", &(r -> cie.x), &(r -> cie.y));

    printf("Insira largura: ");
    scanf("%d", &(r -> larg));

    printf("Insira altura: ");
    scanf("%d", &(r -> alt));
}

// alinea 2d)
float areaR(retangulo r){
    return r.larg * r.alt;
}

// alinea 2e)
int dentroR(retangulo r, ponto2D p){
    if((p.y > r.cie.y) && (p.x > r.cie.x) && (p.y < (r.cie.y + r.alt)) && (p.x < (r.cie.x + r.larg)))
        return 1;
    else
        return 0;
}

// alinea 2f)
void deslocarR(retangulo* r, int dx, int dy){
    r -> cie.x += dx;
    r -> cie.y += dx;
}