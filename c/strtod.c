#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str = "3.3";
    char *endptr = NULL;
    double val;

    val = strtod(str, &endptr);
    if (endptr && (endptr[0] != '\0')) {
        return -1;
    }

    printf("%f\n", val);

    return 0;
}

