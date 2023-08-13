#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main()
{
    uint8_t buf1[] = {0x01, 0x02, 0x04, 0x02, 0x03, 0x05, 0x03, 0x03};
    uint8_t buf2[8];
    int i;

    memcpy(buf2, buf1, sizeof(buf1));
    for (i = 0; i < sizeof(buf1); i ++) {
        printf("%02x\n", buf2[i]);
    }

    return 0;
}

