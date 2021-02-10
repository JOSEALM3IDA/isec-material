#include "geneticAlgorithm.h"
#include "utils.h"
#include "fitness.h"

// Torneio com tamanho T_SIZE
void tournament(int* pop[POP_SIZE], int* parents[POP_SIZE], int qualidade[POP_SIZE], int M) {
	int i, j, x, k, winner;
	int pos[T_SIZE];

	if (T_SIZE < 2 || T_SIZE > M) {
		fprintf(stderr, "<ERRO> T_SIZE tem de estar entre 2 e M.\n");
		exit(-1);
	}

	// Realiza POP_SIZE torneios
	for (i = 0; i < POP_SIZE; i++) {
		for (k = 0; k < T_SIZE; k++) {
			pos[k] = -1;
			do {
				x = randomMinMax(0, POP_SIZE - 1);
				for (j = 0; j < k; j++)
					if (pos[j] == x)
						break;
			} while (j != k);

			pos[k] = x;
		}
		
		winner = -1;
		for (k = 0; k < T_SIZE; k++)
			if (winner == -1 || qualidade[pos[k]] > qualidade[winner])
				winner = pos[k];
		
		memcpy(parents[i], pop[winner], sizeof(int) * M);
	}
}

void geneticOperators(int* parents[POP_SIZE], int* offspring[POP_SIZE], int qualidade[POP_SIZE], const int* dist, int M, int G) {
    // Recombinação
	crossover(parents, offspring, qualidade, M, G);
	// Mutação
	mutation(offspring, dist, M, G);
}

// RECOMBINAÇÃO: UNIFORME
void crossover(int* parents[POP_SIZE], int* offspring[POP_SIZE], int qualidade[POP_SIZE], int M, int G) {
	int i, j, point1, point2, point3;

	for (i = 0; i < POP_SIZE; i += 2) {
		if (rand_01() < PROB_REPROD) {
			for (j = 0; j < M; j++)
				if (rand_01() < 0.5) {
					offspring[i][j] = parents[i][j]; // Colocar o cromossoma j do pai i no cromossoma j do filho i
					offspring[i + 1][j] = parents[i + 1][j];
				} else {
					offspring[i][j] = parents[i + 1][j];
					offspring[i + 1][j] = parents[i][j];
				}
		} else {
			memcpy(offspring[i], parents[i], sizeof(int) * M);
			memcpy(offspring[i + 1], parents[i + 1], sizeof(int) * M);
		}
	}
}

// MUTAÇÃO 1: Escolher 2 subconjuntos G1 e G2, e trocar um elemento de G1 para G2 (aleatoriamente)
void mutation(int* offspring[POP_SIZE], const int* dist, int M, int G) {
	int i, j, g1, g2, p1, count;
	int best_ratio_index, worst_ratio_index;

	for (i = 0; i < POP_SIZE; i++) {
		if (rand_01() < PROB_MUTAC) { // Mutar individuo
			
			do { // Garantir que o grupo escolhido tem pelo menos um elemento
				count = 0; 
				g1 = randomMinMax(0, G - 1);

				for (j = 0; j < M; j++) {
					if (offspring[i][j] == g1) {
						count++;
						break;
					}
				}
			} while (count == 0);

            do
                g2 = randomMinMax(0, G - 1);
            while (g2 == g1);

            do
				p1 = randomMinMax(0, M - 1);
			while (offspring[i][p1] != g1);

            offspring[i][p1] = g2;
        }
	}
}