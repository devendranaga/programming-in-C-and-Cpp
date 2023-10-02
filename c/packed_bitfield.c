#include <stdio.h>

struct S {
    int a;
    int b;
    int f1:1;
    int f2:1;
    int f3:2;
    int f4:2;
} __attribute__ ((__packed__));

int main()
{
    printf("size = %ld\n", sizeof(struct S));

    return 0;
}


