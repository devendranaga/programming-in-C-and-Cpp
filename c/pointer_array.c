#include <stdio.h>

int main()
{
    int a[10];
    int i;
    int *p;

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        p = &a[i];
        *p = i;
    }

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("%d\n", a[i]);
    }

    return 0;
}

