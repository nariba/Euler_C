#include <stdio.h>
#include <stdlib.h>

long int sumofsquare(int num) {
    long int sum = 0;
    for(int i = 1; i <= num; i++) {
        sum += i * i;
    }
    return sum;
}

long int squareofsum(int num) {
    long int sum = 0;
    for(int i = 1; i <= num; i++) {
        sum += i;
    }
    return sum * sum;
}

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    int num = atoi(argv[1]);
    long int ans = squareofsum(num);
    ans -= sumofsquare(num);
    printf("ans=%ld\n", ans);
    return 0;
}
