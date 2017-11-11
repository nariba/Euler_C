#include <stdio.h>
#include <stdlib.h>
#include "prime.h"

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    int num = atoi(argv[1]);
    long triangle = 1;
    long i = 2;
    int counter;

    do {
        counter = 1;
        long tmp = triangle;
        long j = 2;
        int index = 0;
        do {
            if (is_prime(j, 1000)) {
                if (0 == tmp % j) {
                    index++;
                    tmp /= j;
                    if (1 == tmp) {
                        counter *= (index + 1);
                    }
                }
                else {
                    counter *= (index + 1);
                    index = 0;
                    j++;
                }
            }
            else {
                j++;
            }
        } while(1 != tmp);
        printf("%ld %d\n", triangle, counter);

        triangle += i;
        i++;
    } while(counter < num);
    return 0;
}
