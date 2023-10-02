#include <stdio.h>

#define SIZEOF(__ptr_a) ((size_t)(&(__ptr_a) + 1) - (size_t)&(__ptr_a))

struct S {
    int n;
    int p;
};

int main()
{
    int p1;
    struct S s;
    int *p;

    printf("%ld %ld %ld\n", SIZEOF(p1), SIZEOF(s), SIZEOF(p));

    return 0;
}

