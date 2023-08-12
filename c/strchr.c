#include <stdio.h>
#include <string.h>

int main()
{
    char *string = "english movies";
    char *pos;

    pos = strchr(string, 'm');
    if (pos) {
        printf("pos '%s'\n", pos);
    }
}

