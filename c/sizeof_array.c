#include <stdio.h>

int f(int array[])
{
    printf("val %d\n", sizeof(array));
}

int main()
{
    int p[10];

    f(p);

    return 0;
}

