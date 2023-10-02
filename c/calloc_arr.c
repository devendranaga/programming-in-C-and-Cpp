#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a;
    int i;

    a = calloc(10, sizeof(int));
    if (!a) {
        return -1;
    }

    for (i = 0; i < 10; i ++) {
        a[i] = i;
    }

    for (i = 0; i < 10; i ++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);

    return 0;
}

