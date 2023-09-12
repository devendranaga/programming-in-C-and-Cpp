#include <stdio.h>

int main()
{
    FILE *fp;
    int lines = 0;
    char line[1024];

    fp = fopen("./c/fgets_lines.c", "r");
    if (!fp) {
        return -1;
    }

    while (fgets(line, sizeof(line), fp)) {
        lines ++;
    }

    fclose(fp);

    printf("lines: %d\n", lines);

    return 0;
}

