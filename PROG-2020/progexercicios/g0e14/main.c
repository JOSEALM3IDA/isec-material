#include <stdio.h>
#include <string.h>
#include <ctype.h>

int capicua(char st[]){
    int A = -1, B = strlen(st);

    while(B-- - A++ > 1)
        if(tolower(st[A]) != tolower(st[B]))
            return 0;

    return 1;
}

int main() {
    int x;
    char st[50];

    printf("String:\n");
    gets(st);

    printf("%d",capicua(st));
    return 0;
}
