#include <stdio.h>
#include <stdlib.h>

int alloc(int **p)
{
    *p = calloc(1, sizeof(int));
    if (!*p) {
        return -1;
    }

    **p = 3;

    return 0;
}

int main()
{
    int *p = NULL;

    alloc(&p);

    printf("*p: %d\n", *p);

    free(p);

    return 0;
}


