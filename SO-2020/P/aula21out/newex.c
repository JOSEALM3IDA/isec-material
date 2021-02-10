#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int i = 0;

    if (argc == 3) {
        setbuf(stdout, NULL);

        while (1) {
            for (i = 0; i < *argv[1]-'0'; i++) {
                printf("*");
            }
            
            sleep(*argv[2]-'0');
        }
    }
    return 0;
}