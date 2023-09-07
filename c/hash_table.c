#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct LL {
    void *data;
    struct LL *next;
};

#define HASH_TABLE_LEN 30

struct HT {
    struct LL *head;
    struct LL *tail;
};

struct HT ht[HASH_TABLE_LEN];


int hash(const char *str)
{
    int v = 0;
    int i;

    for (i = 0; str[i] != '\0'; i ++) {
        v += str[i];
    }

    return v % HASH_TABLE_LEN;
}

int add_item(const char *key, void *data)
{
    struct LL *item;
    int r = hash(key);

    item = calloc(1, sizeof(struct LL));
    if (!item) {
        return -1;
    }

    item->data = data;

    if (!ht[r].head) {
        ht[r].head = item;
        ht[r].tail = item;
    } else {
        ht[r].tail->next = item;
        ht[r].tail = item;
    }

    return 0;
}

bool find(const char *key, void *data)
{
    struct LL *item;
    int r = hash(key);
    int iters = 0;

    for (item = ht[r].head; item != NULL; item = item->next) {
        iters ++;
        if (item->data == data) {
            printf("took %d iterations\n", iters);
            return true;
        }
    }

    return false;
}

void free_ht()
{
    int i;

    for (i = 0; i < HASH_TABLE_LEN; i ++) {
        struct LL *item;
        struct LL *prev;

        item = ht[i].head;

        while (item) {
            prev = item;
            item = item->next;
            free(prev);
        }
    }
}

struct table {
    char *key;
    int a;
} list [] = {
    {"hash_1", 1},
    {"hash_2", 2},
    {"hash_3", 3},
    {"hash_4", 4},
    {"hash_5", 5},
    {"hash_6", 6},
    {"hash_7", 7},
    {"hash_8", 8},
    {"hash_9", 9},
    {"hash_10", 10},
    {"hash_11", 11},
    {"hash_12", 12},
    {"hash_13", 13},
    {"hash_14", 14},
    {"hash_15", 15},
    {"hash_16", 16},
    {"hash_17", 17},
    {"hash_18", 18},
    {"hash_19", 19},
    {"hash_20", 20},
    {"hash_21", 21},
    {"hash_22", 22},
    {"hash_23", 23},
    {"hash_24", 24},
    {"hash_25", 25},
    {"hash_26", 26},
    {"hash_27", 27},
    {"hash_28", 28},
    {"hash_29", 29},
    {"hash_30", 30},
    {"hash_31", 31},
    {"hash_32", 32},
    {"hash_33", 33},
    {"hash_34", 34},
    {"hash_35", 35},
    {"hash_36", 36},
    {"hash_37", 37},
    {"hash_38", 38},
    {"hash_39", 39},
    {"hash_40", 40},
    {"hash_41", 41},
    {"hash_42", 42},
    {"hash_43", 43},
    {"hash_44", 44},
    {"hash_45", 45},
    {"hash_46", 46},
};

void print()
{
    int i;

    for (i = 0; i < sizeof(list) / sizeof(list[0]); i ++) {
        printf("index %d\n", i);

        struct LL *item;

        for (item = ht[i].head; item != NULL; item = item->next) {
            struct table *t = item->data;
            printf("\tval [%s] [%d]\n", t->key, t->a);
        }
    }
}

int main()
{
    int i;

    for (i = 0; i < sizeof(list) / sizeof(list[0]); i ++) {
        add_item(list[i].key, &list[i]);
    }

    print();

    printf("find %s in %s\n", list[10].key, find(list[10].key, &list[10]) ? "True": "False");
    printf("find %s in %s\n", list[12].key, find(list[12].key, &list[12]) ? "True": "False");
    printf("find %s in %s\n", list[45].key, find(list[45].key, &list[45]) ? "True": "False");
    printf("find %s in %s\n", list[33].key, find(list[33].key, &list[33]) ? "True": "False");
    printf("find hash_50 in %s\n", find("hash_50", &list[12]) ? "True": "False");

    free_ht();

    return 0;
}


