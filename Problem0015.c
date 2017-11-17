#include <stdio.h>
#include <stdlib.h>

unsigned long latticepath(int x, int y) {
    unsigned long ret = 0;
    int i, j;
    unsigned long **lp = malloc(sizeof(unsigned long *) * (x+1));
    for (i = 0; i <= x; i++) {
        lp[i] = malloc(sizeof(unsigned long) * (y+1));
    }

    for (i = 0; i <= x; i++) {
        lp[i][0] = 1;
    }
    for (j = 0; j <= y; j++) {
        lp[0][j] = 1;
    }
    for (i = 1; i <= x; i++) {
        for (j = 1; j <= y; j++) {
            lp[i][j] = lp[i-1][j] + lp[i][j-1];
        }
    }

    ret = lp[x][y];
    for (i = 0; i <= x; i++) {
        free(lp[i]);
    }
    free(lp);
    return ret;
}

int main(int argc, char *argv[]) {
    /* Error */
    if (3 != argc) {
        printf("Error\n");
        return 1;
    }
    int x = atoi(argv[2]);
    int y = atoi(argv[1]);

    unsigned long ans = latticepath(x, y);
    printf("ans=%lu\n", ans);

    return 0;
}
