#include <stdio.h>

#define X(val) TYPESET_ ## val
#define LIST_OF_TYPESETS \
        X(BOLD), \
        X(ITALICS), \
        X(REGULAR)

enum typeset_list {
    LIST_OF_TYPESETS
};

#undef X

int main()
{
#define X(type, val) type = TYPESET_ ##val;
    enum typeset_list typeset;
    X(typeset, BOLD)
#undef X

    switch (typeset) {
#define X(val) case TYPESET_ ##val: printf("val is %d\n", TYPESET_ ##val); break;
#define TYPESET_STATEMENT \
        X(BOLD) \
        X(ITALICS) \
        X(REGULAR)

        TYPESET_STATEMENT
#undef X
    }

    return 0;
}
