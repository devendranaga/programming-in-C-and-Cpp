#include <stdio.h>

int main()
{
    const char *filename = "./c/file_pattern";
    FILE *fp;
    int ret;

    fp = fopen(filename, "r");
    if (!fp) {
        return -1;
    }

    while (1) {
        char name[30];
        int age;

        ret = fscanf(fp, "%s %d", name, &age);
        if (ret != 2) {
            break;
        }
        printf("name: %s age: %d\n", name, age);
    }

    fclose(fp);

    return 0;
}

