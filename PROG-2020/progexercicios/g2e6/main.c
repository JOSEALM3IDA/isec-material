
#include <stdio.h>
#include <stdlib.h>

#include "Contacto.h"

int main() {
    //contacto agenda[10] = {{"Ana", 12345656},{"Joao", 234342432}};
    //int total = 2;
    
    // Declarar um array dinamico b)
    contacto *agenda = NULL;
    int total = 0, i;
    char nome[100];
    
    // Chamada da alinea c)
    for(i=0; i<3; i++)
        agenda = adicionaContacto(agenda, &total);
    
    listarTodos(agenda, total);

    printf("Nome da pessoa a eliminar: ");
    scanf(" %[\n]", &nome);
    printf("\n\n%s\n\n",nome);
    // procurar(agenda, total, nome); nao funciona nao sei pq
    agenda = eliminaContacto(agenda, &total, nome);
    listarTodos(agenda, total);

    // Libertar o array dinamico 
    free(agenda);
    
    return 0;
}

