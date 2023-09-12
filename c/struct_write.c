#include <stdio.h>

struct S {
    int a;
    int r;
};

struct S s1[10];

int main()
{
    struct S s;
    int i;
    FILE *fp;

    for (i = 0; i < sizeof(s1) / sizeof(s1[0]); i ++) {
        s1[i].a = i;
        s1[i].r = i + 1 * i;
    }

    fp = fopen("./s.bin", "wb");
    if (!fp) {
        return -1;
    }

    fwrite(s1, sizeof(s1), 1, fp);
    fclose(fp);

    fp = fopen("./s.bin", "rb");
    if (!fp) {
        return -1;
    }

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("s.a %d s.r %d\n", s.a, s.r);
    }

    fclose(fp);

    return 0;
}

