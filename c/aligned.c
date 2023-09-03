#include <stdio.h>

struct S {
    int v;
    int r;
} __attribute__ ((aligned(16)));

int main()
{
    printf("size %ld\n", sizeof(struct S));

    return 0;
}

