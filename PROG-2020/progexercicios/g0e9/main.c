#include <stdio.h>

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
    int mat[4][3] = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};

    escreveMatriz(4,3,mat);
    return 0;
}
