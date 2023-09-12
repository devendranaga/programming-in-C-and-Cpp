#include <stdio.h>

int main()
{
    int a[100];
    int b[100];
    int i;
    FILE *fp;

    for (i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
        a[i] = i;
    }

    fp = fopen("./test.bin", "wb");
    if (!fp) {
        return -1;
    }

    fwrite(a, sizeof(a), 1, fp);

    fclose(fp);

    fp = fopen("./test.bin", "rb");
    if (!fp) {
        return -1;
    }

    fread(b, sizeof(b), 1, fp);

    for (i = 0; i < sizeof(b) / sizeof(b[0]); i ++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    fclose(fp);

    return 0;
}

