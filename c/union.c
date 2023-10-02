#include <stdio.h>

union U {
    int a;
    int b;
};

int main()
{
    union U u;

    printf("size: %ld\n", sizeof(u));

    u.b = 0;
    u.a = 10;

    printf("u.a %d u.b %d\n", u.a, u.b);

    u.b = 3;

    printf("u.a %d u.b %d\n", u.a, u.b);

    return 0;
}

