#include <stdio.h>

void calculaMedias(int nLin, int nCol, float m[][nCol], int* min, int *max){
    int i, k;
    float media = 0;
    float maiorMedia, menorMedia;

    for(k = 0; k < nCol; k++) {
        for(i = 0; i < nLin; i++) {
            media += *(m[i] + k);
        }
        media /= nLin;
        printf("Media coluna %d: %.3f\n", k, media);

        if(k != 0) {
            if(media > maiorMedia) {
                maiorMedia = media;
                *max = k;
            }
            else if(media < menorMedia) {
                menorMedia = media;
                *min = k;
            }
        }
        else {
            maiorMedia = media;
            menorMedia = media;
            *min = 0;
            *max = 0;
        }
        media = 0;
    }
}


int main() {

    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0, 1.6, 4.2, 1.4, 0.5, -3.4},{2.5, 8.1, 0.9, -0.1, 0.8, 3.5}};

    int min2 = -1, max2 = -1;

    calculaMedias(2, 6, m2, &min2, &max2);

    printf("\nIndice Min: %d\nIndice Max: %d\n", min2, max2);

    return 0;
}