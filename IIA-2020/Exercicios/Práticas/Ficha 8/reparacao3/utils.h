struct info init_data(char *s, int mat[][2]);

pchrom init_pop(info d);

void print_pop(pchrom pop, info d);

chrom get_best(pchrom pop, info d, chrom best);

void write_best(chrom x, info d);

void init_rand();

int random_l_h(int min, int max);

float rand_01();

int flip();
