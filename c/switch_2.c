#include <stdio.h>

int main()
{
    int a = 10;

    switch (a) {
        case 10:
            int r = a * 14;
            printf("val %d %d\n", a, r);
        break;
        case 20:
            printf("val %d\n", a);
        break;
    }

    return 0;
}

