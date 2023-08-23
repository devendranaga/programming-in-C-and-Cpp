#include <stdio.h>
#include <stdint.h>
#include <string.h>

int a[1024*1024 * 10];
int b[1024*1024 * 10];

void fill()
{
    int i;

    for (i = 0; i != 1024 * 1024 * 10; i ++) {
        a[i] = b[i] = i;
    }
}

int d_memcmp(const void *mem_a, const void *mem_b, int len)
{
    int ret = 0;
    int i;
    int rem = len % 8;
    int check_len = len / 8;

    const uint64_t *val_a = mem_a;
    const uint64_t *val_b = mem_b;

    const uint8_t *ptr_a = mem_a;
    const uint8_t *ptr_b = mem_b;

    for (i = 0; i < check_len; i ++) {
        if (val_a[i] != val_b[i]) {
            ret = -1;
            break;
        }
    }
    if (ret != -1) {
        if (rem != 0) {
            for (i = len - rem; i < len; i ++) {
                if (ptr_a[i] != ptr_b[i]) {
                    ret = -1;
                    break;
                }
            }
        }
    }

    return ret;
}

int b_memcmp(const void *a, const void *b, int len)
{
    int i;
    const uint8_t *val_a = a;
    const uint8_t *val_b = b;
    int ret = 0;

    for (i = 0; i < len; i ++) {
        if (val_a[i] != val_b[i]) {
            ret = -1;
            break;
        }
    }

    return ret;
}

int main()
{
    fill();

#if 1
    printf("Result optimized: %d\n", d_memcmp(a, b, 1024 * 1024 * 10));
    //printf("Result byte: %d\n", b_memcmp(a, b, 1024 * 1024 * 10));
#else
    printf("Result %d\n", memcmp(a, b, 1024 * 1024 * 10));
#endif

    return 0;
}

