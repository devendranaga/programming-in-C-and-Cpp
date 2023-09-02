#include <stdio.h>
#include <stdarg.h>

int add(int n_args, ...)
{
    int i;
    int r = 0;
    va_list ap;

    va_start(ap, n_args);

    for (i = 0; i < n_args; i ++) {
        r += va_arg(ap, int);
    }

    va_end(ap);

    return r;
}

int main()
{
    int r;

    r = add(3, 1, 2, 3);
    printf("r: %d\n", r);

    r = add(6, 1, 2, 3, 4, 5, 6);
    printf("r: %d\n", r);

    return 0;
}

