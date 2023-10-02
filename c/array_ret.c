#include <stdio.h>

int *return_a()
{
    int a[] = {1, 2, 3};

    return a;
}

int main()
{
    int *p = return_a();
    int i;

    for (i = 0; i < 3; i ++) {
        printf("%d\n", p[i]);
    }

    return 0;
}



