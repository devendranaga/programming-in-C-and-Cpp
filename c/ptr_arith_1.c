#include <stdio.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6};
    int *p;

    p = &a[0];

    while (*p != 6) {
        printf("p %d\n", *p);
        p ++;
    }

    printf("\n");

    p = &a[0];

    printf("p->%d\n", *(p + 3));

    return 0;
}

