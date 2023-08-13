#include <stdio.h>

#if defined(PRINT_HELLO)
void print_message()
{
    printf("Hello\n");
}
#else
void print_message()
{
    printf("Bye\n");
}
#endif

int main()
{
    print_message();
}

