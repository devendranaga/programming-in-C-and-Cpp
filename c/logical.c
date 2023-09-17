#include <stdio.h>

int main()
{
    int a = 0x80;
    int b = 0x81;

    printf("AND 0x%02x OR 0x%02x XOR 0x%02x\n",
                a & b, a | b, a ^ b);

    printf("%d %d\n", a && b, a || b);

    int r = -1;
    int p = 1;

    printf("%d %d\n", !!r, !!p);

    return 0;
}

