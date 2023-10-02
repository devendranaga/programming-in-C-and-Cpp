#include <stdio.h>

union U {
    unsigned char a;
    char s[10];
};

int main()
{
    union U u;

    u.a = 10;
    u.s[0] = '\0';

    printf("u.a_ptr %p u.s_ptr %p\n", &u.a, u.s);

    printf("size %ld\n", sizeof(union U));
    printf("u.a %d u.s '%s'\n", u.a, u.s);

    u.s[0] = '\n';

    printf("u.a %d u.s '%s'\n", u.a, u.s);

    u.s[0] = 'P';
    u.s[1] = 'A';
    u.s[2] = '\0';

    printf("u.a %d u.s '%s'\n", u.a, u.s);

    return 0;
}

