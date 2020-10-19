
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contacto.h"

// Alinea d)
void listarTodos(contacto a[], int total){
    int i;
    
    printf("Existem %d contactos:\n", total);
    
    for(i=0; i<total; i++)
        printf("Nome: %s\tNumero: %d\n", a[i].nome, a[i].num);
    
}

// Alinea c)
contacto* adicionaContacto(contacto *a, int *total){
    contacto* b = realloc(a, sizeof(contacto) * (*total+1));
    int i, existe;

    if (b != NULL){
        a = b;
        do {
            existe = 0;
            printf("Nome: ");
            scanf(" %[^\n]", &a[*total].nome);

            for(i = 0; i < *total; i++)
                if(!strcmp(a[*total].nome,a[i].nome)){
                    printf("O nome %s ja existe!\n", a[i].nome);
                    existe = 1;
                }
        }while(existe);

        printf("Numero: ");
        scanf("%d", &a[*total].num);
        (*total)++;
    }
    return a;
}

// Alinea d)
void procurar(contacto* a, int total, char nome[]){
    int i;
    for(i = 0; i < total; i++){
        if(strcmp(nome, a[i].nome) == 0){
            printf("%s tem o numero %d", nome, a[i].nome);
            return;
        }
    }
    printf("Contacto nao encontrado.\n");
}

// Alinea g)
contacto* eliminaContacto(contacto* a, int* total, char nome[]){
    int i, j;
    contacto* p;
    contacto ultimo;

    if(*total == 0)
        return a;

    for(i = 0; i < *total && !strcmp(a[i].nome, nome); i++)
        ;

    if(i == *total)
        return a;

    if(*total == 1){
        free(a);
        *total = 0;
        return NULL;
    }

    ultimo = a[*total - 1];

    p = realloc(a, sizeof(contacto) * (*total - 1));
    if(p == NULL)
        return a;

    if(i == *total - 1){
        (*total)--;
        return a;
    }

    a = p;
    for(j = i; j < *total - 2; j++)
        a[j] = a[j+1];

    a[j] = ultimo;

    (*total)--;

    return a;
}

