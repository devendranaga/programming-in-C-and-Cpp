#include <stdio.h>

int main()
{
    int a;
    char str[100];
    int ret;

    ret = fscanf(stdin, "%d %s", &a, str);
    if (ret != 2) {
        printf("incorrect number of arguments\n");
        return -1;
    }

    printf("a=%d str=%s\n", a, str);

    return 0;
}

