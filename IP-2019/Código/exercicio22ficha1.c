#include <stdio.h>

void main()
{
    int dia, mes, ano, ultimoDia;

    printf("Insira o dia atual: ");
    scanf("%d",&dia);
    printf("Insira o mes atual: ");
    scanf("%d",&mes);
    printf("Insira o ano atual: ");
    scanf("%d",&ano);

    if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        ultimoDia = 30;
    else if (mes == 2)
        ultimoDia = 28;
    else
        ultimoDia = 31;

    if (dia == ultimoDia && mes == 12)
    {
        dia = 1;
        mes = 1;
        ano++;
    }
    else if (dia == ultimoDia)
    {
        dia = 1;
        mes++;
    }
    else
        dia++;

    printf("\nData do dia seguinte: %.2d/%.2d/%.4d\n",dia,mes,ano);
}
