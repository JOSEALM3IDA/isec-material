#include <stdio.h>

void main()
 {
     int numero,multiplo;

     printf("Insira o numero inteiro cujos multiplos quer calcular: ");
     scanf("%d",&numero);

     /*
     int contador = 2;
     while (contador <= 6){
         multiplo = numero;
         multiplo *= contador;
         contador++;
         printf("Multiplo %d: %d \n",contador-1,multiplo);
     }
     */

     for(int i = 2;i<=6;i++){
        multiplo = numero;
        multiplo *= i;
        printf("Multiplo %d: %d \n",i-1,multiplo);
     }
 }
