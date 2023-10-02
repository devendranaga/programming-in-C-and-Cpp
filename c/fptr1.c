#include <stdio.h>
#include <stdlib.h>

typedef int (*init)(void);
typedef void (*run)(int);
typedef void (*deinit)(void);

struct S {
    init init;
    run run;
    deinit deinit;
};

int driver_init(void)
{
    printf("driver_init called\n");

    return 0;
}

void driver_run(int a)
{
    printf("driver_run called with %d\n", a);
}

void driver_deinit(void)
{
    printf("driver_deinit called\n");
}

struct S *get_driver_callbacks()
{
    struct S *s;

    s = calloc(1, sizeof(struct S));
    if (!s) {
        return NULL;
    }

    s->init = driver_init;
    s->run = driver_run;
    s->deinit = driver_deinit;

    return s;
}

void free_driver_callbacks(struct S *s)
{
    if (s) {
        free(s);
    }
}

int main()
{
    struct S *s;
    int ret;

    s = get_driver_callbacks();
    if (!s) {
        return -1;
    }

    ret = s->init();
    if (ret != 0) {
        return -1;
    }

    s->run(3);

    s->deinit();

    free_driver_callbacks(s);

    return 0;
}


