#include <stdio.h>

struct A {
    int val;
    double val_d;
};

int main()
{
    struct A a = { .val = 3, .val_d = 3.1 };

    fprintf(stderr, "val: %d\n", a.val);
    fprintf(stderr, "val_d: %f\n", a.val_d);

    return 0;
}

