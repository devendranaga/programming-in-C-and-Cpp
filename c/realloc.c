#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a;
    int i;

    a = calloc(4, sizeof(int));
    if (!a) {
        return -1;
    }

    for (i = 0; i < 4; i ++) {
        a[i] = i;
    }

    printf("calloced a %p\n", a);

    a = realloc(a, sizeof(int) * 10);
    if (!a) {
        return -1;
    }

    printf("realloced a %p\n", a);

    for (i = 4; i < 10; i ++) {
        a[i] = i;
    }

    for (i = 0; i < 10; i ++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    free(a);

    return 0;
}

