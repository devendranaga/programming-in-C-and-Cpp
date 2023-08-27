#include <stdio.h>

int main()
{
    const char *ptr = "hello";

    *ptr = 'i';

    printf("%s\n", ptr);

    return 0;
}

