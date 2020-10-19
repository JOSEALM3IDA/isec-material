
#include <stdio.h>
#include "ponto.h"

// alinea b)
void printPonto(ponto2D a){
    printf("(%d,%d)\n", a.x, a.y);
}

// alinea c)
void initPonto(ponto2D* p){
    printf("Insira x e y: ");
    scanf("%d %d", &(p -> x), &(p -> y));
}

// alinea d)
void movePonto(ponto2D* p, int dx, int dy){
    p -> x += dx;
    p -> y += dy;
}

// alinea e)
void mesmaReta(ponto2D* p1, ponto2D* p2, ponto2D* p3){
    float m1, m2, mY, mX;

    mY = (p2 -> y) - (p1 -> y);
    mX = (p2 -> x) - (p1 -> x);

    if(mX != 0)
        m1 = mY/mX;
    else
        printf("Colineares.");


    mY = (p3 -> y) - (p2 -> y);
    mX = (p3 -> x) - (p2 -> x);

    if(mX != 0)
        m2 = mY/mX;
    else
        printf("Colineares.");


    if(m1 == m2)
        printf("Colineares.");
    else
        printf("Nao colineares.");
}