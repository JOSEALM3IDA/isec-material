

#ifndef CONTACTO_H
#define CONTACTO_H

// Alinea a)
typedef struct{
    char nome[100];
    int num;
} contacto;

void listarTodos(contacto a[], int total);

contacto* adicionaContacto(contacto *a, int *total);

void procurar(contacto* a, int total, char nome[]);

contacto* eliminaContacto(contacto* a, int* total, char nome[]);


#endif /* CONTACTO_H */

