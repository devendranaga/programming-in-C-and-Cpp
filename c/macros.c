#include <stdio.h>

#define CONFIG_MACRO

int main()
{
    int a = 10;

#ifdef CONFIG_MACRO
    a = 5;
#else
    a = 6;
#endif

    printf("%d\n", a);
}

