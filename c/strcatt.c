#include <stdio.h>

int string_cat(char *dst, const char *src)
{
    int i = 0;
    int j = 0;

    while (dst[i] != '\0') {
        i ++;
    }
    while (src[j] != '\0') {
        dst[i] = src[j];
        i ++;
        j ++;
    }
    dst[i] = '\0';

    return i;
}

int main()
{
    char *src = "test";
    char dst[30] = "dest";

    string_cat(dst, src);
    printf("dst %s\n", dst);

    return 0;
}

