#include <stdio.h>

int main()
{
    int a = 0x80;
    int b = 0x81;

    printf("AND 0x%02x OR 0x%02x XOR 0x%02x\n",
                a & b, a | b, a ^ b);

    printf("%d %d\n", a && b, a || b);
    return 0;
}

