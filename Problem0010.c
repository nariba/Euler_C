#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "prime.h"

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    int num = atoi(argv[1]);
    long sum = 0;
    for (int i = 1; i < num; i++) {
        if (is_prime(i, 1000)) {
            sum += i;
        }
    }
    printf("ans=%ld\n", sum);
}
