#include <stdio.h>
#include <stdlib.h>

struct S {
    int v;
    char *ptr;
};

int main()
{
    struct S **s;
    int i;
    int j;

    s = calloc(1, sizeof(struct S *) * 4 * 3); // alloc 4 pointers
    if (!s) {
        return -1;
    }

    for (i = 0; i < 4; i ++) {
        // for each pointer allocate memory for structure
        s[i] = calloc(1, sizeof(struct S) * 3);
        if (!s[i]) {
            return -1;
        }

        for (j = 0; j < 3; j ++) {
            s[i][j].v = i;
            s[i][j].ptr = calloc(1, 14);
            if (!s[i][j].ptr) {
                return -1;
            }

            sprintf(s[i][j].ptr, "alloc_%d", i);
        }
    }

    for (i = 0; i < 4; i ++) {
        for (j = 0; j < 3; j ++) {
            printf("s[%d][%d].v %d s[%d][%d].ptr %s\n", i, j, s[i][j].v, i, j, s[i][j].ptr);

            free(s[i][j].ptr);
        }
        free(s[i]);
    }

    free(s);

    return 0;
}
