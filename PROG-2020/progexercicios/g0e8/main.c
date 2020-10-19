#include <stdio.h>

void preencheMatriz(int nLin, int mat[][3]){
    int i, j, temp;

    for(i = 0; i < nLin; i++){
        do{
            temp = 0;
            do{
                printf("Elemento %d:", i+1);
                scanf("%d", &mat[i][0]);
            }while(mat[i][0] < 1 || mat[i][0] > 100);

            for(j = i-1; j >= 0; j--){
                if(mat[i][0] == mat[j][0]) {
                    temp = 1;
                    break;
                }
            }

        }while(temp == 1);
    }

    for(i = 0; i < nLin; i++){
        for(j = 1; j < 3; j++){
            mat[i][j] = mat[i][j-1] * mat[i][0];
        }
    }
}

void escreveMatriz(int nLin, int nCol, int m[][nCol]){
    int i,j;

    for(i = 0; i < nLin; i++){
        for(j = 0; j < nCol; j++){
            printf("%d\t", m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int main() {
    int mat[4][3];

    preencheMatriz(4, mat);

    escreveMatriz(4, 3, mat);

    return 0;
}
