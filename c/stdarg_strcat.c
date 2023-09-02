#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int strcat_self(char *dst, const char *src)
{
    int i = 0;
    int j = 0;

    for (i = 0; dst[i] != '\0'; i ++) { }
    for (j = 0; src[j] != '\0'; i ++, j ++) {
        dst[i] = src[j];
    }
    dst[i] = '\0';
}

int strcat_vaarg(char *final_str, int n_args, ...)
{
    va_list ap;
    int i;

    va_start(ap, n_args);
    for (i = 0; i < n_args; i ++) {
        char *str = va_arg(ap, char *);
        strcat_self(final_str, str);
    }

    printf("final %s\n", final_str);
    return 0;
}

int main()
{
    char final_str[400] = {};
    int r;

    final_str[0] = '\0';
    r = strcat_vaarg(final_str, 3, "fruits", "vitamins", "health");
    memset(final_str, 0, sizeof(final_str));

    r = strcat_vaarg(final_str, 6, "snacks", "sugars", "fats", "chips", "crispy", "bad");
}

