#include <stdio.h>
#include <stdint.h>
#include <string.h>


int string_copy(char *dst, unsigned int dst_len, const char *src)
{
    uint32_t i = 0;
    uint32_t len = 0;

    for (i = 0; src[i] != '\0'; i ++) {
        if (i < dst_len) {
            dst[i] = src[i];
        } else {
            break;
        }
    }

    dst[i - 1] = '\0';

    printf("%s\n", dst);

    return 0;
}

int main()
{
    char *str = "Witcher";
    char dst[6];

    string_copy(dst, 6, str);
}

