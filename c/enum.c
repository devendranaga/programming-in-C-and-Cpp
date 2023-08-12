#include <stdio.h>

int main()
{
    enum t {
        a = 10,
        b,
        c,
        d = 20,
        e,
    };

    printf("%d %d %d %d\n", a, b, d, e);
}

