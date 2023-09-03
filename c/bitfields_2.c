#include <stdio.h>
#include <stdint.h>

struct S {
    unsigned int v:1;
    unsigned int p:2;
};

int main()
{
    struct S s;
    struct S *s1;

    s1 = &s;

    s1->v = 1;
    s1->p = 3;

    int *v = &s1->v;
}


