#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>

int main(int argc, char **argv)
{
    int a = 0;
    char *str = NULL;
    bool t = false;
    int ret;

    while ((ret = getopt(argc, argv, "i:s:t")) != -1) {
        switch (ret) {
            case 'i':
                a = atoi(optarg);
            break;
            case 's':
                str = optarg;
            break;
            case 't':
                t = true;
            break;
            default:
                printf("%s <-i int value> <-s string value> -t\n", argv[0]);
                return -1;
        }
    }

    printf("a %d\n", a);
    if (str) {
        printf("str %s\n", str);
    }
    printf("t %d\n", t);

    return 0;
}

