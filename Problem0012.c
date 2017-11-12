#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "prime.h"
#include "omp.h"

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }

    int nthreads = omp_get_max_threads();
    bool flag = false;
    long ans;

#pragma omp parallel
    {
        int num = atoi(argv[1]);
        int mynum = omp_get_thread_num();
        long i = 2;
        long triangle = 1;
        for(int k = 0; k < mynum; k++) {
            triangle += i;
            i++;
        }

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
//            printf("[%d]%ld %d\n", mynum, triangle, counter);

            if (counter >= num) {
                printf("[%d]%ld %d\n", mynum, triangle, counter);
                if (flag != true) {
                    ans = triangle;
                    flag = true;
                }
                else if (ans > triangle) {
                    ans = triangle;
                }
            }
            else {
                for(int k = 0; k < nthreads; k++) {
                    triangle += i;
                    i++;
                }
            }
        } while(!flag || ans > triangle);
    }
    printf("%ld\n", ans);

    return 0;
}
