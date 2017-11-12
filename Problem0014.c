#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long collatz(unsigned long n) {
    if (n % 2) {
        return 3 * n + 1;
    }
    else {
        return n / 2;
    }
}

int count_chain(unsigned long n) {
    int chain = 1;
    while(n != 1) {
        n = collatz(n);
        chain++;
    }
    return chain;
}

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    int num = atoi(argv[1]);
    int max;
    int ans;
#pragma omp parallel reduction(max:ans) private(max)
    {
        max = 0;
#pragma omp for
        for (int i = 1; i < num; i++) {
            int tmp = count_chain((unsigned long)i);
            printf("%d:%d\n", i, tmp);
            if (tmp > max) {
                ans = i;
                max = tmp;
            }
        }
        printf("ans=%d, max=%d\n", ans, max);
    }

    return 0;
}
