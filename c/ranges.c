#include <stdio.h>

int main()
{
    short int i = 40000;

    printf("%d %d\n", i, 65535 + i);

    return 0;
}

