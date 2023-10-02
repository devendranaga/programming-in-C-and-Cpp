#include <stdio.h>
#include <stdlib.h>

struct S {
    int v;
    char *ptr;
};

#define rows 4
#define cols 3

int main()
{
    struct S **s;
    int i;
    int j;

    s = calloc(1, sizeof(struct S *) * rows); // alloc 4 pointers
    if (!s) {
        return -1;
    }

    for (i = 0; i < rows; i ++) {
        // for each pointer allocate memory for structure
        s[i] = calloc(1, sizeof(struct S) * cols);
        if (!s[i]) {
            return -1;
        }

        for (j = 0; j < cols; j ++) {
            s[i][j].v = i;
            s[i][j].ptr = calloc(1, 14);
            if (!s[i][j].ptr) {
                return -1;
            }

            sprintf(s[i][j].ptr, "alloc_%d", i);
        }
    }

    for (i = 0; i < rows; i ++) {
        for (j = 0; j < cols; j ++) {
            printf("s[%d][%d].v %d s[%d][%d].ptr %s\n", i, j, s[i][j].v, i, j, s[i][j].ptr);

            free(s[i][j].ptr);
        }
        free(s[i]);
    }

    free(s);

    return 0;
}
