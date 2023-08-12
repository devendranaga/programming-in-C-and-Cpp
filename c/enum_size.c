#include <stdio.h>

enum fruit {
    orange,
    apple,
};

int main()
{
    printf("%d\n", sizeof(enum fruit));

    enum fruit f = orange, *p;

    p = &f;

    printf("%d\n", *p);
}

