#include <stdio.h>

int main()
{
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a2[10];
    int i;

    for (i = 0; i < sizeof(a1) / sizeof(a1[0]); i ++) {
        a2[i] = a1[i];
    }

    for (i = 0; i < sizeof(a1) / sizeof(a1[0]); i ++) {
        printf("a1[%d] = %d a2[%d] = %d\n", i, a1[i], i, a2[i]);
    }

    return 0;
}

