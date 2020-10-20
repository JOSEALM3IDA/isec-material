#include <stdio.h>

float valor(int dist, float tempo, float custoHora, float custoKM, int equipa)
{
    float preco;
    preco = custoHora*tempo*equipa + custoKM*dist;
    return preco;
}

void main()
{
    int servico, nServicos, dist, equipa;
    float tempo, custoHora, custoKM, preco, menorPreco, total = 0;

    do{
        printf("Numero de servicos > ");
        scanf("%d", &nServicos);
    }while(nServicos < 1 || nServicos > 6);

    servico = 1;
    while(servico <= nServicos)
    {
        printf("\nCliente: %.2d\n", servico);
        printf("Distancia, Tempo, Equipa, Custo/Hora, Custo/km > ");
        scanf("%d%f%d%f%f", &dist, &tempo, &equipa, &custoHora, &custoKM);
        preco = valor(dist,tempo,custoHora,custoKM,equipa);

        if (servico == 1)
            menorPreco = preco;
        total += preco;
        printf("\nCusto do servico = %.2f\n", preco);
        servico++;
    }
    printf("\nCusto total dos servicos = %.2f", total);
    printf("\nMenor custo = %.2f\n", menorPreco);
}
