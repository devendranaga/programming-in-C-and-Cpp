#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main()
{
    uint8_t a[10];
    int i;

    memset(a, 0, sizeof(a));

    printf("set 0s:\n");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    memset(a, 1, sizeof(a));

    printf("set 1s:\n");
    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        printf("a[%d] = %x\n", i, a[i]);
    }

    return 0;
}

