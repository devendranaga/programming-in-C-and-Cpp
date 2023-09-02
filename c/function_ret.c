#include <stdio.h>
#include <string.h>

char *get_2()
{
    char hello_msg[20];

    strcpy(hello_msg, "hello");

    return hello_msg;
}

char *get_1()
{
    return "hello";
}

int main()
{
    char *ptr = get_1();

    printf("get_1 %s\n", ptr);

    ptr = get_2();

    printf("get_2 %s\n", ptr);

    return 0;
}

