#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "algoritmo.h"
#include "funcao.h"
#include "utils.h"

#define DEFAULT_RUNS	50

int main(int argc, char *argv[]) {
	char        nome_fich[100];
	struct info EA_param;
	pchrom      pop = NULL, parents = NULL;
	chrom       best_run, best_ever;
	int         gen_actual, r, runs, i, inv, mat[MAX_OBJ][2];
	float       mbf = 0.0;

    // Lê os argumentos de entrada
	if (argc == 3) {
		runs = atoi(argv[2]);
		strcpy(nome_fich, argv[1]);
	} else
        // Se o número de execuções do processo não for colocado nos argumentos de entrada, define-o com um valor por defeito
        if (argc == 2) {
            runs = DEFAULT_RUNS;
            strcpy(nome_fich, argv[1]);
        } else { // Se o nome do ficheiro de informações não for colocado nos argumentos de entrada, pede-o novamente
            runs = DEFAULT_RUNS;
            printf("Nome do Ficheiro: ");
            gets(nome_fich);
        }

    // Se o número de execuções do processo for menor ou igual a 0, termina o programa
	if (runs <= 0)
		return 0;

    //Inicializa a geração dos números aleatórios
	init_rand();

    // Preenche a matriz com dados dos objectos (peso e valor) e a estrutura EA_param que foram definidos no ficheiro de input
	EA_param = init_data(nome_fich, mat);

	// Faz um ciclo com o número de execuções definidas
	for (r = 0; r < runs; r++) {
		printf("Repeticao %d\n",r+1);

        // Geração da população inicial
		pop = init_pop(EA_param);

        // Avalia a população inicial
		evaluate(pop, EA_param, mat);
		gen_actual = 1;

		// Como ainda não existe, escolhe-se como melhor solução a primeira da população (poderia ser outra qualquer)
		best_run = pop[0];

        // Encontra-se a melhor solução dentro de toda a população
		best_run = get_best(pop, EA_param, best_run);

        // Reserva espaço para os pais da população seguinte
		parents = malloc(sizeof(chrom)*EA_param.popsize);
        // Caso não consiga fazer a alocação, envia aviso e termina o programa
		if (parents == NULL) {
			printf("Erro na alocacao de memoria\n");
			exit(1);
		}

		// Ciclo de optimização
		while (gen_actual <= EA_param.numGenerations) {
            // Torneio binário para encontrar os progenitores (ficam armazenados no vector parents)
			tournament(pop, EA_param, parents);

            // Aplica os operadores genéticos aos pais (os descendentes ficam armazenados na estrutura pop)
			genetic_operators(parents, EA_param, pop, mat);

			// Repara cada solucao da populacao, garantindo que estas sao validas
			for (i = 0; i < EA_param.popsize; i++) 
				reparacao3(pop[i].p, EA_param, mat, &pop[i].valido);
			
            // Avalia a nova população (a dos filhos)
			evaluate(pop, EA_param, mat);

            // Actualiza a melhor solução encontrada
			best_run = get_best(pop, EA_param, best_run);
			gen_actual++;
		}

		// Contagem das soluções inválidas
		for (inv = 0, i = 0; i < EA_param.popsize; i++)
			if (pop[i].valido == 0)
				inv++;
				
		// Escreve resultados da repetição que terminou
		//printf("\nRepeticao %d:", r);
		//write_best(best_run, EA_param);
		//printf("\nPercentagem Invalidos (se nao for zero o codigo esta mal): %.2f\n", 100*(float)inv/EA_param.popsize);
		mbf += best_run.fitness;
		if (r == 0 || best_run.fitness > best_ever.fitness)
			best_ever = best_run;

        // Liberta a memória usada
		free(parents);
		free(pop);
	}

	// Escreve resultados globais
	printf("\n\nMBF: %f\n", mbf/r);
	printf("\nMelhor solucao encontrada");
	write_best(best_ever, EA_param);
	return 0;
}
