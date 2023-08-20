#include <stdio.h>

int main()
{
    char *filename = "c/fgets_newline.c";
    FILE *fp;
    char str[100];

    fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    while (fgets(str, sizeof(str), fp) != NULL) {
        fprintf(stderr, "line '%s'\n", str);
    }
    fclose(fp);

    return 0;
}

