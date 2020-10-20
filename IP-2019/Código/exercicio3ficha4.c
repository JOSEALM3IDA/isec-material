#include <stdio.h>

int numAlimentares = 0, numNaoAlimentares = 0, numProdutos;
float ivaAlimentar = 0.06, ivaNaoAlimentar = 0.23, preco, precoTotal, precoTotalIVA;
char tipoProduto;

void main()
{
    do{
        printf("\nIndique o preco do produto: ");
        scanf("%f",&preco);
        if (preco > 0)
        {
            fflush(stdin);
            printf("\nProdutos Alimentares: Insira A\n");
            printf("Produtos nao Alimentares: Insira N\n");
            printf("Tipo de produto: ");
            scanf("%c",&tipoProduto);
            switch (tipoProduto)
            {
                case 'a':
                case 'A':
                    numAlimentares++;
                    precoTotal += preco;
                    preco *= (1 + ivaAlimentar);
                    precoTotalIVA += preco;
                    break;
                case 'n':
                case 'N':
                    numNaoAlimentares++;
                    precoTotal += preco;
                    preco *= (1 + ivaNaoAlimentar);
                    precoTotalIVA += preco;
                    break;
                default:
                    printf("\nTipo invalido!\n");
            }
        }
        numProdutos = numAlimentares + numNaoAlimentares;
    }while (preco > 0 || numProdutos == 0);


    printf("\nNumero de produtos nao alimentares: %d\n",numNaoAlimentares);
    printf("Numero de produtos alimentares: %d\n",numAlimentares);
    printf("Numero total de produtos: %d\n",numProdutos);
    printf("Valor total: %.2f\n",precoTotal);
    printf("Valor total com IVA: %.2f\n",precoTotalIVA);
}
