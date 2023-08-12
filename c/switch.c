#include <stdio.h>

int main()
{
    int n = 10;

    switch (n) {
        case 10:
        case 20:
            printf("n is %d\n", n);
        break;
        case 30:
            printf("n is 30\n");
        break;
    }

    return 0;
}

