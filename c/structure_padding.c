#include <stdio.h>

struct S {
    int v;
    int p;
    char r;
} __attribute__ ((__packed__));

struct R {
    int v;
    int p;
    char r;
};

int main()
{
    printf("regular_size %ld packed_size %ld\n", sizeof(struct R), sizeof(struct S));

    return 0;
}


