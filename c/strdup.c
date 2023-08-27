#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *ptr = "hello";
    char *ptr1;

    ptr1 = strdup(ptr);

    printf("ptr %s ptr1 %s\n", ptr, ptr1);

    free(ptr1);

    return 0;
}

