#include <stdio.h>
#include <stdlib.h>

int len(const char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i ++) { }

    return i;
}

char *strdup_1(const char *str)
{
    char *ptr;
    int i;
    int length = len(str);

    // 1 for the \0
    ptr = calloc(1, length + 1);

    for (i = 0; i < length; i ++) {
        ptr[i] = str[i];
    }
    ptr[i] = '\0';

    return ptr;
}

int main()
{
    char *ptr = "hello";
    char *ptr1;

    ptr1 = strdup_1(ptr);

    printf("ptr %s ptr1 %s\n", ptr, ptr1);

    free(ptr1);

    return 0;
}

