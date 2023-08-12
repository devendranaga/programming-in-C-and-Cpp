#include <stdio.h>

int main()
{
    int n[10] = {9};

    printf("%lu\n", sizeof(n));

    int i;

    for (i = 0; i < 10; i++) {
        printf("%d\n", n[i]);
    }

    return 0;
}

