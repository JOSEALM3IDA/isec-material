//
// Created by josec on 24/03/2020.
//

#include "retangulo.h"
#include "ponto.h"

//alinea b)
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

// alinea c)
void initR(retangulo* r){
    printf("Insira x e y do canto superior esquerdo: ");
    scanf("%d %d", &(r -> cie.x), &(r -> cie.y));

    printf("Insira largura: ");
    scanf("%d", &(r -> larg));

    printf("Insira altura: ");
    scanf("%d", &(r -> alt));
}

// alinea d)
float areaR(retangulo r){
    return r.larg * r.alt;
}

// alinea e)
int dentroR(retangulo r, ponto2D p){
    if((p.y > r.cie.y) && (p.x > r.cie.x) && (p.y < (r.cie.y + r.alt)) && (p.x < (r.cie.x + r.larg)))
        return 1;
    else
        return 0;
}

// alinea f)
void deslocarR(retangulo* r, int dx, int dy){
    r -> cie.x += dx;
    r -> cie.y += dx;
}