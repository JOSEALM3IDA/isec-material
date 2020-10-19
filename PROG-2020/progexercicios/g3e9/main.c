#include <stdio.h>

void lerFicheiro(char *nomeF) {
    FILE *f, *d;
    int peso[5] = {0};
    int nAl, nProvas, i, c;
    float nota, valor;

    f = fopen(nomeF, "r");
    if (f == NULL) return;

    d = fopen("novo.txt", "w");
    if (d == NULL) return;

    fscanf(f, "Numero de alunos: %d\n", &nAl);
    fscanf(f, "Numero de provas: %d\n", &nProvas);

    fprintf(d, "%d alunos ; %d provas\n", nAl, nProvas);

    do
        c = fgetc(f);
    while(c != ':');

    for(i = 0; i < 6; i++) {
        do
            c = fgetc(f);
        while(c == ' ');

        fseek(f, -1, SEEK_CUR);

        fscanf(f, "%d", &peso[i]);
    }

    nAl = 1;

    while ((c = fgetc(f)) != EOF) {
        nota = 0;
        do
            c = fgetc(f);
        while(c != ':');

        for(i = 0; i < 6; i++) {
            do
                c = fgetc(f);
            while(c == ' ');

            fseek(f, -1, SEEK_CUR);

            fscanf(f, "%f", &valor);

            nota += valor * (peso[i]/100.0);

        }

        fprintf(d, "Aluno %d: %.2f\n", nAl, nota);
        nAl++;
    }

    fclose(f);
}

int main() {
    lerFicheiro("notas_ex9.txt");

    return 0;
}
