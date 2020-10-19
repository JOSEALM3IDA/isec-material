#include <stdio.h>

void zeros(int *v, int tam){
    int i, pos, j;

    for (i = 1; i < tam; i++) {
        if (v[i] == 0 && v[i-1] != 0) {
            for (pos = 0; v[pos] == 0; pos++);
            for (j = i; j > pos; j--) {
                v[j] = v[j-1];
            }
            v[pos] = 0;
        }
    }
}

int main() {
    int n=6, i;
    int a[6] = {0,0,0,0,0,0};
    zeros(a, n);

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
