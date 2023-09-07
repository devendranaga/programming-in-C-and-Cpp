#include <stdio.h>
#include <stdlib.h>

struct circular_list {
    void *data;
    struct circular_list *next;
};

static struct circular_list *head;
static struct circular_list *tail;

int add_tail(void *data)
{
    struct circular_list *item;

    item = calloc(1, sizeof(struct circular_list));
    if (!item) {
        return -1;
    }

    item->data = data;

    if (!head) {
        head = item;
        tail = item;
        tail->next = head;
    } else {
        tail->next = item;
        tail = item;
        item->next = head;
    }

    return 0;
}

void print(void (*callback)(void *data))
{
    struct circular_list *item = head;

    if (!item) {
        return;
    }

    do {
        callback(item->data);
        item = item->next;
    } while (item != head);
}

void for_each(void (*callback)(void *data))
{
    struct circular_list *item = head;

    if (!item) {
        return;
    }

    do {
        if (callback)
            callback(item->data);
        item = item->next;
    } while (item != head);
}

int count()
{
    struct circular_list *item = head;
    int count = 0;

    if (!item) {
        return count;
    }

    do {
        count ++;
        item = item->next;
    } while (item != head);

    return count;
}

int delete(void *data, void (*callback)(void *data))
{
    struct circular_list *item = head;
    struct circular_list *prev = item;

    if (head->data == data) {
        head = head->next;
        tail->next = head;
        if (callback)
            callback(item->data);
        free(item);
        return 0;
    }

    prev = item;
    item = item->next;

    while (item != head) {
        if (item->data == data) {
            if (callback)
                callback(item->data);
            prev->next = item->next;
            if (item == tail) {
                tail = prev;
            }
            free(item);
            return 0;
        }
        prev = item;
        item = item->next;
    }

    return -1;
}

void free_all(void (*callback)(void *data))
{
    struct circular_list *item;
    struct circular_list *prev;

    item = head;
    prev = head;

    do {
        prev = item;
        item = item->next;
        if (callback)
            callback(prev->data);
        free(prev);
    } while (item != head);
}

void print_data(void *data)
{
    printf("%d\n", *(int *)data);
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    for (i = 0; i < 10; i ++) {
        add_tail(&a[i]);
    }

    printf("print all elements:\n");
    print(print_data);

    delete(&a[0], NULL);

    printf("after deleting the first element:\n");
    print(print_data);

    delete(&a[9], NULL);

    printf("after deleting the last element:\n");
    print(print_data);

    free_all(NULL);

    return 0;
}

