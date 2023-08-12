#include <stdio.h>

int main()
{
    int i = 0;

    for (;;) {
        if (i >= 10) {
            break;
        }
        printf("i %d\n", i);
        i ++;
    }

    return 0;
}

