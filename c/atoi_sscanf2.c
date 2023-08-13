#include <stdio.h>

int main()
{
    char *str = "123a";
    int intval;
    int ret;

    ret = sscanf(str, "%d", &intval);
    if (ret != 1) {
        printf("incorrect integer\n");
    } else {
        printf("val %d\n", intval);
    }
}

