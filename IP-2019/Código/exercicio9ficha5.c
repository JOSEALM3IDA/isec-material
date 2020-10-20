#include <stdio.h>

int arredonda(float x1,float x2);

void main()
{
    float x1,x2;

    printf("Insira x1 e x2: ");
    scanf("%f%f",&x1,&x2);

    printf("%d", arredonda(x1,x2));
}

int arredonda(float x1, float x2)
{
    int mediaInteira;
    float media;
    media = (x1+x2)/2;

    mediaInteira = (int)media;

    if(media-mediaInteira >= 0.5)
        mediaInteira++;

    return mediaInteira;
}
