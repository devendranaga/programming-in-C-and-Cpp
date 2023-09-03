#include <stdio.h>
#include <stdint.h>

struct S {
    uint32_t v:1;
    uint32_t p:2;
};

int main()
{
    struct S s;

    s.v = 1;
    s.p = 2;

    printf("v: %d p: %d\n", s.v, s.p);
    printf("size: %ld\n", sizeof(struct S));

    return 0;
}

