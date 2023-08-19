#include <stdio.h>

int main()
{
    const char *filename = "c/numchar.c";
    FILE *fp;
    char a;
    int num_chars = 0;

    fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    while (1) {
        a = fgetc(fp);
        if (a == EOF) {
            break;
        }
        num_chars ++;
    }

    printf("number of characters %d\n", num_chars);

    return 0;
}

