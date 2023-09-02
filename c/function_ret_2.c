#include <stdio.h>

static const char *books[] = {
    "networking essentials",
    "programming in C",
};

const char *get(unsigned int book_id)
{
    if (book_id > sizeof(books) / sizeof(books[0])) {
        return "Unknown";
    }

    return books[book_id];
}

int main()
{
    printf("book %s\n", get(1));

    return 0;
}

