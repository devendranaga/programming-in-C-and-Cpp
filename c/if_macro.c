#include <stdio.h>

int main()
{
#if IN == 1
    printf("IN is 1\n");
#elif IN == 2
    printf("IN is 2\n");
#else
    printf("IN is %d\n", IN);
#endif

    return 0;
}

