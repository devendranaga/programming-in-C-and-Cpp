#include <stdio.h>

int main()
{
    void f() { printf("in f\n"); }

    void f2() { printf("in f2\n"); }

    f();
    f2();

    return 0;
}

