#include <stdio.h>

#if defined(CONFIG_A) || defined(CONFIG_R)
void f()
{
    printf("in f\n");
}

#elif defined(CONFIG_B)
void f()
{
    printf("in g\n");
}

#endif

int main()
{
    f();

    return 0;
}

