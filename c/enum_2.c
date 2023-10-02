#include <stdio.h>

typedef enum {
    apples,
    oranges,
    bananas,
} fruits;

int main()
{
    fruits f = apples;

    f ++;

    printf("fruits:apples : %d:%d\n", f, apples);

    f --;

    printf("fruits:apples : %d:%d\n", f, apples);

    return 0;
}


