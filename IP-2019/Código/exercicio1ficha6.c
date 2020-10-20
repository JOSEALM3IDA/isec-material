#include <stdio.h>

void main()
{
    float media = 0;
    int N = 5;
    int i;
    int v[N];

    for(i=0;i<N;i++)
    {
        printf("Insira valor: ");
        scanf("%d",&v[i]);
        media += v[i];
    }
    media /= N;
    printf("\nMedia: %.2f\n\n",media);

    for(i=0;i<N;i++)
    {
        if (v[i]<media)
        {
            v[i] = 0;
        }
        printf("%d   ",v[i]);
    }
}
