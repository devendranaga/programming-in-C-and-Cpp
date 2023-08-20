#include <stdio.h>

int main()
{
    char str[100];
    char *err;

    while (1) {
        err = fgets(str, sizeof(str), stdin);
        if (err == NULL) {
            printf("stopping program\n");
            break;
        }

        printf("you entered - %s", str);
    }

    return 0;
}

