#include <stdio.h>
#include <stdarg.h>

typedef enum {
    INT,
    DOUBLE,
    STRING,
} type_t;

double add(type_t type, int n_args, ...)
{
    va_list ap;
    double r = 0;
    int i;

    va_start(ap, n_args);
    for (i = 0; i < n_args; i ++) {
        if (type == INT) {
            r += va_arg(ap, int);
        } else if (type == DOUBLE) {
            r += va_arg(ap, double);
        }
    }

    va_end(ap);

    return r;
}

int main()
{
    double r;

    r = add(INT, 3, 1, 2, 3);
    printf("r: %f\n", r);

    r = add(DOUBLE, 6, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6);
    printf("r: %f\n", r);

    return 0;
}

