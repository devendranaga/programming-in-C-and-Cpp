#include <stdio.h>
#include <stdlib.h>

#define rows 10
#define cols 10

struct S {
    int p1;
    int p2;
};

int main()
{
    struct S **s = NULL;
    int i;
    int j;

    s = calloc(rows, sizeof(struct S **)); // allocate pointers for rows x cols
    if (!s) {
        return -1;
    }

    // allocate cols for each row
    for (i = 0; i < rows; i ++) {
        s[i] = calloc(cols, sizeof(struct S));
        if (!s[i]) {
            return -1;
        }
    }

    for (i = 0; i < rows; i ++) {
        for (j = 0; j < cols; j ++) {
            s[i][j].p1 = i;
            s[i][j].p2 = j;
        }
    }

    for (i = 0; i < rows; i ++) {
        for (j = 0; j < cols; j ++) {
            printf("s[%d][%d].p1 = %d s[%d][%d].p2 = %d\n", i, j, s[i][j].p1, i, j, s[i][j].p2);
        }
    }

    for (i = 0; i < rows; i ++) {
        free(s[i]);
    }
    free(s);

    return 0;
}

