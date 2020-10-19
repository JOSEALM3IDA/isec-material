//
// Created by josec on 24/03/2020.
//

#ifndef G2E1_RETANGULO_H
#define G2E1_RETANGULO_H

#include <stdio.h>
#include "ponto.h"

typedef struct r retangulo;

struct r{
    ponto2D cie;
    int larg, alt;
};

void printR(retangulo r);

void initR(retangulo* r);

float areaR(retangulo r);

int dentroR(retangulo r, ponto2D p);

void deslocarR(retangulo* r, int dx, int dy);

#endif //G2E1_RETANGULO_H
