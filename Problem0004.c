#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool is_palindromic_num(int num) {
    char *num_c;
    sprintf(num_c, "%d", num);
    int len = strlen(num_c);

    bool ret = true;
    for(int i = 0; i < len; i++) {
        if(num_c[i] != num_c[len - 1 - i]) {
            ret = false;
            break;
        }
    }
    return ret;
}

int main(int argc, char *argv[]) {
    /* Error */
    if (2 != argc) {
        printf("Error\n");
        return 1;
    }
    int num = atoi(argv[1]);
    int max = (int)__exp10((double)num) - 1;

    int i, j, palindromic_max = 0;
    for(i = max; i > 1; i--) {
        for(j = i; j <= max; j++) {
            if(is_palindromic_num(i*j) && palindromic_max < i * j) {
                palindromic_max = i * j;
            }
        }
    }
    printf("%d\n", palindromic_max);
    return 0;
}
