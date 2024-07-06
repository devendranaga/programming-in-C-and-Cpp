#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;

    switch (a) {
        case 10:
            switch (b) {
                case 20:
                    printf("nested switch\n");
                break;
            }
        break;
    }

    return 0;
}
