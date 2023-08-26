#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct DL {
    void *data;
    struct DL *prev;
    struct DL *next;
};

struct DL *head = NULL;
struct DL *tail = NULL;

int dl_add_head(void *data)
{
    struct DL *node;

    node = calloc(1, sizeof(struct DL));
    if (!node) {
        return -1;
    }

    node->data = data;

    if (!head) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }

    return 0;
}

bool dl_find_fwd(bool (*callback)(void *data))
{
    struct DL *node;

    for (node = head; node != NULL; node = node->next) {
        if (callback(node->data)) {
            return true;
        }
    }

    return false;
}

bool dl_find_rv(bool (*callback)(void *data))
{
    struct DL *node;

    for (node = tail; node != NULL; node = node->prev) {
        if (callback(node->data)) {
            return true;
        }
    }

    return false;
}

int dl_count()
{
    struct DL *node;
    int count = 0;

    for (node = head; node != NULL; node = node->next) {
        count ++;
    }

    return count;
}

bool dl_delete_item(void *data, void (*callback)(void *data))
{
    struct DL *node;
    struct DL *prev;

    if (head->data == data) {
        node = head;
        head = head->next;
        head->prev = NULL;
        if (callback) {
            callback(node->data);
        }
        free(node);

        return true;
    } else if (tail->data == data) {
        node = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(node);

        return true;
    } else {
        node = head;
        while (node) {
            if (node->data == data) {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                if (callback) {
                    callback(node->data);
                }
                free(node);

                return true;
            }
            node = node->next;
        }
    }

    return false;
}

void dl_for_each_fwd(void (*callback)(void *data))
{
    struct DL *node;

    for (node = head; node != NULL; node = node->next) {
        if (callback) {
            callback(node->data);
        }
    }
}

void dl_for_each_rv(void (*callback)(void *data))
{
    struct DL *node;

    for (node = tail; node != NULL; node = node->prev) {
        if (callback) {
            callback(node->data);
        }
    }
}

void dl_free_fwd(void (*callback)(void *data))
{
    struct DL *node = head;
    struct DL *prev;

    while (node) {
        prev = node;
        if (callback) {
            callback(prev->data);
        }
        node = node->next;
        free(prev);
    }
}

void dl_free_rv(void (*callback)(void *data))
{
    struct DL *node = tail;
    struct DL *prev;

    while (node) {
        prev = node;
        if (callback) {
            callback(prev->data);
        }
        node = node->prev;
        free(prev);
    }
}

void print(void *data)
{
    printf("val %d\n", *(int *)data);
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    for (i = 0; i < 10; i ++) {
        dl_add_head(&a[i]);
    }

    printf("forward[%d]: \n", dl_count());
    dl_for_each_fwd(print);

    dl_delete_item(&a[0], NULL);
    dl_delete_item(&a[2], NULL);
    dl_delete_item(&a[9], NULL);

    printf("reverse[%d]: \n", dl_count());
    dl_for_each_rv(print);

    // dl_free_fwd(NULL);
    dl_free_rv(NULL);

    return 0;
}


