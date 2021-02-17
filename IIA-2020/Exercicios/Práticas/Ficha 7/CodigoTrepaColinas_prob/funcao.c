#include "funcao.h"

// Calcula a qualidade de uma solucao
// Recebe:  A solucao, a, a matriz de adjacencias, mat, e o numero de vertices, vert
// Devolve: O custo que e o numero de ligacoes que existem na solucao
int calcula_fit(int a[], int *mat, int vert) {
	int total=0;
	int i, j;

	for(i=0; i<vert; i++)
		if(a[i]==0)
			for(j=0; j<vert;j++)
				if(a[j]==1 && *(mat+i*vert+j)==1)
				    total++;
	
	return total;
}
