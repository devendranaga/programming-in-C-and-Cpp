#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **p;
    int i;
    int j;

    p = calloc(1, sizeof(int *) * 4 * 3);
    if (!p) {
        return -1;
    }

    for (i = 0; i < 4; i ++) {
        p[i] = calloc(1, sizeof(int) * 3);
        if (!p[i]) {
            return -1;
        }
    }

    for (i = 0; i < 4; i ++) {
        for (j = 0; j < 3; j ++) {
            p[i][j] = i + j;
        }
    }

    for (i = 0; i < 4; i ++) {
        for (j = 0; j < 3; j ++) {
            printf("p[%d][%d] = %d\n", i, j, p[i][j]);
        }
    }

    for (i = 0; i < 4; i ++) {
        free(p[i]);
    }

    free(p);

    return 0;
}

