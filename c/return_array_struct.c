#include <stdio.h>

struct S {
    int a[10];
    int len;
};

struct S return_s()
{
    struct S r;
    int i;

    r.len = 10;
    for (i = 0; i < r.len; i ++) {
        r.a[i] = i;
    }

    return r;
}

int main()
{
    struct S r;
    int i;

    r = return_s();

    for (i = 0; i < r.len; i ++) {
        printf("a[%d] = %d\n", i, r.a[i]);
    }

    return 0;
}

