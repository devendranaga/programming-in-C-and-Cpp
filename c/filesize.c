#include <stdio.h>

int main()
{
    const char *filename = "c/filesize.c";
    long int filesize;
    FILE *fp;

    fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);

    printf("file size %ld\n", filesize);

    return 0;
}

