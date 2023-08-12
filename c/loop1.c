#include <stdio.h>

int main()
{
    int i = 0;

    while (1) {
        if (i >= 10) {
            break;
        }
        printf("%d\n", i);
        i ++;
    }

    return 0;
}

