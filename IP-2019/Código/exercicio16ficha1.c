#include <stdio.h>

void main()
{
    float x,y;
    char a; /* variável de caso */

    printf("Insira os dois valores: \n");
    scanf("%f%f",&x,&y);
    fflush(stdin);
    printf("Escolha a operacao a efetuar:\n  Adicao (+)\n  Subtracao(-)\n  Divisao(/)\n  Multiplicacao(*)\n");
    scanf("%c",&a);

    switch (a)
    {
    case '+': // plicas, nao aspas
        x = x + y;
    break;
    case '-':
        x = x - y;
    break;
    case '/':
        x = x / y;
    break;
    case '*':
        x = x * y;
    break;
    default: printf("Opcao invalida.\n");
    }

    printf("Valor pretendido: %.2f\n",x);
}
