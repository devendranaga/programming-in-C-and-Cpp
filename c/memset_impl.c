#include <stdio.h>
#include <stdint.h>

void memset_impl(void *p, int r, size_t n)
{
    uint8_t *v = p;
    int i;

    for (i = 0; i < n; i ++) {
        *(v + 0) = r;
        *(v + 1) = r;
        *(v + 2) = r;
        *(v + 3) = r;

        v += sizeof(int);
    }
}

int main()
{
    uint32_t a[10];
    int i;

    memset_impl(a, 1, 10);

    for (i = 0; i < 10; i ++) {
        printf("a[%d] = %x\n", i, a[i]);
    }

    return 0;
}

