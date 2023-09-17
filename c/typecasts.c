#include <stdio.h>

int main()
{
    int d;
    double v = 10.1;
    double v1 = 10.99;

    d = (int)v;

    printf("d %d v %f v1 %d \n", d, v, (int)v1);

    return 0;
}

