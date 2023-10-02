#include <stdio.h>

int main()
{
    char *p = "hello";

    while (*p != '\0') {
        printf("'%c'", *p);
        p ++;
    }
    printf("\n");

    return 0;
}

