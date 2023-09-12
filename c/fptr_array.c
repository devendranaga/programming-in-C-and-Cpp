#include <stdio.h>

int f()
{
    static int count = 0;

    printf("F called %d\n", count);

    return ++ count;
}

typedef int (*fptr_f)(void);


int main()
{
    fptr_f fptr[4];
    int i;

    for (i = 0; i < 4; i ++) {
        fptr[i] = f;
    }

    for (i = 0; i < 4; i ++) {
        fptr[i]();
    }

    return 0;
}

