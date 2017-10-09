#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_multiple(int base, int num) {
    if (num % base) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char *argv[]) {
    int sum = 0;
    int limit;

    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }


    limit = atoi(argv[1]);
    for (int i = 0; i < limit; i++) {
        if (is_multiple(3, i) || is_multiple(5, i)) {
            sum += i;
        }
    }
    printf("sum=%d\n", sum);
    return 0;
}
