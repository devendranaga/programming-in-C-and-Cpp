#include <stdio.h>

int main()
{
    int a[10][10] = {0};
    int i;
    int j;

    for (i = 0; i < 10; i ++) {
        for (j = 0; j < 10; j ++) {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }

    return 0;
}
