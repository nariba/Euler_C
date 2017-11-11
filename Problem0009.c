#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    int num = atoi(argv[1]);
    int i, j;
    bool flag = false;

    for (i = 1; i < num; i++) {
        for (j = 1; j < num; j++) {
            if ((num-(i+j)) * (num-(i+j)) == i*i + j*j) {
                printf("%d %d %d\n", i, j, num-(i+j));
                flag = true;
            }
            if (flag) {
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    printf("ans=%d\n", i * j * (num-(i+j)));
    return 0;
}
