
#include <stdio.h>
#include <string.h>


void ex4(char *nomeF){
    FILE *f;
    int c;
    int linha=1;
    
    f = fopen(nomeF, "r");
    if(f == NULL)
        printf("Ficheiro nao existe\n");
    else{       
        // int feof(FILE *f);       -> Função
        // EOF - constante que assinala o fim de um ficheiro de texto     
        printf("%d. ", linha++);
        while( (c = fgetc(f)) != EOF){
            
            putchar(c);
            if(c == '\n')
                printf("%d. ", linha++);
                
        }
        fclose(f);
    }
}


void ex9(char *nomeF){
    FILE *f;
    int peso[6] = {0};
    int nAl, nProvas;
    int c;
    
    f = fopen(nomeF, "r");
    if (f == NULL) return;
    
    do
        c = fgetc(f);
    while(c != ':');
    fscanf(f, "%d", &nAl);
    
     do
        c = fgetc(f);
    while(c != ':');
    fscanf(f, "%d", &nProvas);
    
    //fscanf(f, "Numero de alunos: %d", &nAl); 
    //fscanf(f, " Numero de provas: %d", &nProvas);
    
    printf("Sao %d alunos e %d provas\n", nAl, nProvas);
    
    fclose(f);
    
    
}


int main(){

    //ex4("Aula2TXT.c");
    
    //ex5("Aula2TXT.c", "Novo.txt");
    
    //(ex6("Aula2TXT.c", "NovoNumerado.txt");
    
    ex9("notas_ex9.txt");

    return 0;    
}