#ifndef UTILS_H
#define UTILS_H

#define ARB_PIPE "arb_pipe"

#define EXIT_OK 0
#define EXIT_ERR_MSG -1
#define EXIT_TRNMT_OVER -2

#define OK_STR "#OK"
#define EXISTE_STR "#EXISTE"

#define ARBITRO_CAMPEONATO_CHEIO "#FULL"
#define ARBITRO_SAIU_STR "#EXIT"
#define ARBITRO_MATOU_STR "#KILLED"
#define ARBITRO_SUSPENDEU_STR "#SUSPENDED"
#define ARBITRO_RETOMOU_STR "#RESUME"
#define CAMPEONATO_TERMINOU_STR "#FIMCAMP"

#define STR_SIZE 128
#define BUFF_SIZE 256

#define true 1
#define false 0
#define bool int

// Limpa uma string buff com tamanho máximo tam
void limpar(char *buff, int tam);

// Transforma todos os caracteres duma string str em maiúsculos
void toupperString(char *str);

// Verifica se a string fornecida é um número absoluto
bool isAbsoluteNumber(char* str);

#endif /* UTILS_H */