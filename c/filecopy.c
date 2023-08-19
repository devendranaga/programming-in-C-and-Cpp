#include <stdio.h>

int main()
{
    const char *file_in = "c/filecopy.c";
    const char *file_out = "c/filecopy.c.copy";
    FILE *f_in;
    FILE *f_wr;
    char str[1024];

    f_in = fopen(file_in, "r");
    if (!f_in) {
        return -1;
    }

    f_wr = fopen(file_out, "w");
    if (!f_wr) {
        fclose(f_in);
        return -1;
    }

    while (fgets(str, sizeof(str), f_in)) {
        fputs(str, f_wr);
    }

    fclose(f_in);
    fclose(f_wr);

    return 0;
}

