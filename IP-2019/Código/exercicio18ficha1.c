#include <stdio.h>

void main()
{
    int x,y;

    printf("Insira o ponto no formato (x,y): ");
    scanf("(%d,%d)",&x,&y); //ler no formato de par ordenado

    if (x > 0 && y > 0)
        printf("O ponto pertence ao primeiro quadrante.\n");
    else if (x < 0 && y > 0)
        printf("O ponto pertence ao segundo quadrante.\n");
    else if (x < 0 && y < 0)
        printf("O ponto pertence ao terceiro quadrante.\n");
    else if (x > 0 && y > 0)
        printf("O ponto pertence ao quarto quadrante.\n");
    else if (y == 0 && x != 0)
        printf("O ponto pertence ao eixo dos xx.\n");
    else if (x == 0 && y != 0)
        printf("O ponto pertence ao eixo dos yy.\n");
    else
        printf("O ponto e a origem.\n");
}
