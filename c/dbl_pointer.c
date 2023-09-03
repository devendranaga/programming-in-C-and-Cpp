#include <stdio.h>

int main()
{
    int r;
    int *p = &r;
    int **s = &p;

    *p = 3;

    printf("r: %d *p: %d **s: %d\n", r, *p, **s);

    return 0;
}

