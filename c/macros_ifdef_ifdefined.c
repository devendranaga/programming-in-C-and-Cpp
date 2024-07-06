#include <stdio.h>

#define ABC
#define ABC_ABC 0

int main()
{
#ifdef ABC
    printf("in ABC\n");
#endif

#if defined(ABC_ABC)
    printf("in ABC_ABC\n");
#endif
}
