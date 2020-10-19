
#ifndef PONTO_H
#define PONTO_H

// alinea a)
typedef struct ponto ponto2D;
struct ponto{
    int x, y;
};

void printPonto(ponto2D a);

void initPonto(ponto2D* p);

void movePonto(ponto2D* p, int dx, int dy);

void mesmaReta(ponto2D* p1, ponto2D* p2, ponto2D* p3);

#endif /* PONTO_H */

