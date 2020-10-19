#include <stdio.h>
#include <string.h>

void tradutor(){

    char mes[12][15] = {"janeiro", "fevereiro","marco","abril", "maio", "junho",
                        "julho", "agosto", "setembro", "outubro","novembro","dezembro"};

    char *month[12] = {"january", "february","march","april", "may", "june",
                       "july", "august", "september", "october","november","december"};

    char st[15];
    int i;

    printf("Mes:");
    scanf("%s", st);

    for(i=0; i<12; i++)
        if(strcmp(st, mes[i]) == 0){
            printf("%s - %s\n", mes[i], month[i]);
            return;
        }

    printf("Mes inexistente\n");
}


int main() {

    float m1[3][2] = {{1.0, 4.5},{-2.5, 8.9},{0.3, 1.4}};
    float m2[2][6] = {{1.0, 1.6, 4.2, 1.4, 0.5, -3.4},{2.5, 8.1, 0.9, -0.1, 0.8, 3.5}};
    int i;

    for(i=0; i<5; i++)
        tradutor();

    return 0;
}