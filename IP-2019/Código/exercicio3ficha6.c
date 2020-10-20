#include <stdio.h>
#include <ctype.h>
#define N 10

void main()
{
    int i,A[N]={0},B[N]={0},I[N]={0},R[10]={0},S[10]={0},n;
    char ter;

    do{
        do{
            printf("\nInsira elemento do conjunto A: ");
            scanf("%d",&n);
        }while(n<0 || n>9);
        A[n] = 1;
        i++;
        printf("Terminou (Y/N)? ");
        fflush(stdin);
        scanf("%c",&ter);
    }while(toupper(ter)=='N');

    do{
        do{
            printf("\nInsira elemento do conjunto B: ");
            scanf("%d",&n);
        }while(n<0 || n>9);
        B[n] = 1;
        i++;
        printf("Terminou (Y/N)? ");
        fflush(stdin);
        scanf("%c",&ter);
    }while(toupper(ter)=='N');

    printf("\nA\tB\t\tInterseccao\tReuniao\t\tDiferenca\n\n");
    for(i=0;i<N;i++)
    {
        I[i] = A[i] && B[i];
        R[i] = A[i] || B[i];
        S[i] = A[i] && !B[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",A[i],B[i],I[i],R[i],S[i]);
    }
}
