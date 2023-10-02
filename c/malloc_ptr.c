#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a;
    int *p;
    int i;

    a = malloc(sizeof(int) * 10);
    if (!a) {
        return -1;
    }

    p = a;

    printf("a %p\n", a);

    i = 0;
    while (i < 10) {
        *a = i;
        i ++;
        a ++;
    }

    printf("a after assigning %p\n", a);

    i = 0;
    while (i < 10) {
        printf("val %d\n", *p);
        i ++;
        p ++;
    }

    free(p - 10);

    return 0;
}

