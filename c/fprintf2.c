#include <stdio.h>

struct S {
    char *name;
    int age;
} friends[] = {
    {"Dev", 33},
    {"Rahul", 34},
    {"Nithin", 38},
    {"Seema", 35},
};

int main()
{
    const char *filename = "c/file_write";
    FILE *fp;
    int i;

    fp = fopen(filename, "w");
    if (!fp) {
        return -1;
    }

    for (i = 0; i < sizeof(friends) / sizeof(friends[0]); i ++) {
        fprintf(fp, "%s %d\n", friends[i].name, friends[i].age);
    }

    fclose(fp);

    return 0;
}

