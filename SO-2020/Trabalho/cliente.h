#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio_ext.h>

#define EXIT_QUIT -4

// Invocada na receção de sinais
void sig_handler(int signal, siginfo_t *info, void * extra);

// Responsável por terminar o cliente, garantindo o seu fecho correto
void sair(int exitValue, char* error);