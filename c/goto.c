#include <stdio.h>

int main()
{
    int i = 0;

begin:
    if (i < 10) {
        printf("i %d\n", i);
        i ++;
        goto begin;
    }

    return 0;
}

