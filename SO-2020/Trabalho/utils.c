#include "utils.h"
#include <string.h>
#include <ctype.h>
#include <dirent.h> 
#include <sys/types.h>

void limpar(char *buff, int tam) {
    int i;
    for (i = 0; i < tam; i++)
        buff[i] = '\0';
}

void toupperString(char *str) {
    size_t i;
    for (i = 0; i < strlen(str); i++)
        str[i] = toupper(str[i]);
}

bool isAbsoluteNumber(char* str) {
    size_t i;

    for (i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return false;

    return true;
}