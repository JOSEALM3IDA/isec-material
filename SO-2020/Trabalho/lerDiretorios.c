
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <dirent.h> 
  
char** lerDiretorio(char* dir, int* tam) { 
    int i;
    char **temp, **arr = NULL;
    struct dirent *de;  // Pointer for directory entry 
  
    // opendir() returns a pointer of DIR type.  
    DIR *dr = opendir(dir); 
  
    if (dr == NULL) { // opendir returns NULL if couldn't open directory 
        printf("Could not open current directory" ); 
        return NULL; 
    } 

    *tam = 0;

    printf("Abri o diretorio!\n");

    while ((de = readdir(dr)) != NULL) 
        if(de->d_type == DT_REG) {
            printf("Li um ficheiro de nome %s!\n", de->d_name);
            for(i = strlen(de->d_name) - 1; i >= 0; i--)
                if (de->d_name[i] == '.') {
                    printf("Tinha um ponto :(\n");
                    break;
                }

            if (i != -1)
                continue;

            printf("Sem ponto! Vou realocar!\n");
            temp = realloc(arr, sizeof(char*) * ((*tam) + 1));
            if (temp == NULL) {
                printf("Erro na alocação de memória dinâmica!\n");
                for(i = 0; i < *tam; i++)
                    free(arr[i]);
                free(arr);
                return NULL;
            }

            printf("Realocado com sucesso! Agora vou realocar a string!\n");

            arr = temp;

            arr[*tam] = malloc(sizeof(de->d_name));
            strcpy(arr[*tam], de->d_name);

            printf("Realoquei a string: %s\n", arr[*tam]);

            (*tam)++;

        }

    for(i = 0; i < *tam; i++) {
        printf("%i: ", i);
        printf("%s\n", arr[i]);
    }
  
    closedir(dr);     
    return arr; 
} 

int main(void) { 
    int index;
    char** listaJogos;
    setbuf(stdout, NULL);
    int nJogos;

    listaJogos = lerDiretorio("./Games", &nJogos);
    printf("tam: %i\n", nJogos);
    for(index = 0; index < nJogos; index++) {
        printf("%i: ", index);
        printf("%s\n", listaJogos[index]);
    } 

    for(index = 0; index < nJogos; index++)
        free(listaJogos[index]);
    free(listaJogos);

    return 0; 
} 

