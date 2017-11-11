#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    int limit = atoi(argv[1]);

    long int a0;
    long int a1 = 2;
    long int a2 = 1;
    long int answer = 2;
    for(int i = 3; a0 < limit; i++) {
        a0 = a1 + a2;
        a2 = a1;
        a1 = a0;
        if(a0 % 2 == 0) {
            answer += a0;
        }
    }
    printf("answer=%ld\n", answer);
    return 0;
}
