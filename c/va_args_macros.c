#include <stdio.h>

#define log_msg(...) printf(__VA_ARGS__)

int main()
{
    log_msg("hello world\n");

    return 0;
}

