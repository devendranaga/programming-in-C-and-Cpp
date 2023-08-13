#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    char *str = "4294967295";
    uint32_t val;
    char *err = NULL;

    val = strtoul(str, &err, 10);
    if (err && (err[0] != '\0')) {
        return -1;
    }

    printf("val %u\n", val);

    return 0;
}

