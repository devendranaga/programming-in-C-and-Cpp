#include <stdio.h>
#include <stdarg.h>

void log_printf(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vfprintf(stderr, fmt, ap);
    va_end(ap);
}

int main()
{
    int a = 10;

    log_printf("test: test message a=%d\n", a);
}

