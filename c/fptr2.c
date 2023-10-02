#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void buy_apples(int number);
void buy_oranges(int number);
void buy_mangoes(int number);

struct S {
    char *ptr;
    void (*buy)(int number);
};

static const struct S s[] = {
    {
        .ptr = "apples",
        .buy = buy_apples,
    },
    {
        .ptr = "oranges",
        .buy = buy_oranges,
    },
    {
        .ptr = "mangoes",
        .buy = buy_mangoes,
    },
};

const struct S *find_fruit(const char *fruit)
{
    int i;

    for (i = 0; i < sizeof(s) / sizeof(s[0]); i ++) {
        if (!strcmp(s[i].ptr, fruit)) {
            return &s[i];
        }
    }

    return NULL;
}

int main(int argc, char **argv)
{
    const struct S *p = find_fruit(argv[1]);
    if (!p) {
        printf("fruit %s not found\n", argv[1]);
        return -1;
    }

    p->buy(atoi(argv[2]));

    return 0;
}

void buy_apples(int number)
{
    printf("buying apples %d\n", number);
}

void buy_oranges(int number)
{
    printf("buying oranges %d\n", number);
}

void buy_mangoes(int number)
{
    printf("buying mangoes %d\n", number);
}



