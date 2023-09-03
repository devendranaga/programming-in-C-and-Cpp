#include <stdio.h>

int f(const char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i ++) {
        str[i] = 'a';
    }

    return i;
}

int main()
{
    char str[20] = "hello";

    f(str);

    printf("str: %s\n", str);

    return 0;
}

