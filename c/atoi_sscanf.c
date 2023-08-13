#include <stdio.h>

int main()
{
    char *str_int = "1343";
    int intval;

    sscanf(str_int, "%d", &intval);
    printf("%d\n", intval);

    return 0;
}

