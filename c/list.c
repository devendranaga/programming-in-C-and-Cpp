#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct linked_list {
    void *elem;
    struct linked_list *next;
};

static struct linked_list *head;
static struct linked_list *tail;

int add(void *data)
{
    struct linked_list *node;

    node = calloc(1, sizeof(struct linked_list));
    if (!node) {
        return -1;
    }

    node->elem = data;

    if (!head) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    return 0;
}

int add_head(void *data)
{
    struct linked_list *node;

    node = calloc(1, sizeof(struct linked_list));
    if (!node) {
        return -1;
    }

    node->elem = data;

    if (!head) {
        head = node;
        tail = node;
    } else {
        node->next = head;
        head = node;
    }

    return 0;
}

int delete(void *elem)
{
    struct linked_list *node;
    struct linked_list *prev;

    node = head;
    prev = node;

    if (head->elem == elem) {
        head = head->next;
        free(node);
        return 0;
    } else {
        while (node != NULL) {
            if (node->elem == elem) {
                prev->next = node->next;
                if (node == tail) {
                    tail = prev;
                }
                free(node);
                return 0;
            }
            prev = node;
            node = node->next;
        }
    }

    return -1;
}

bool find(void *elem)
{
    struct linked_list *node;

    for (node = head; node != NULL; node = node->next) {
        if (node->elem == elem) {
            return true;
        }
    }

    return false;
}

int count()
{
    struct linked_list *node;
    int n = 0;

    for (node = head; node != NULL; node = node->next) {
        n ++;
    }

    return n;
}

void for_each(void (*callback)(void *elem))
{
    struct linked_list *node;

    for (node = head; node != NULL; node = node->next) {
        if (callback) {
            callback(node->elem);
        }
    }
}

void print()
{
    struct linked_list *node;

    printf("elements:\n");
    for (node = head; node != NULL; node = node->next) {
        int *data = node->elem;

        printf("%d\n", *data);
    }
}

void clean()
{
    struct linked_list *node;
    struct linked_list *prev;

    node = head;
    prev = head;

    while (node) {
        node = node->next;
        free(prev);
        prev = node;
    }
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;
    int f = 60;

    add(&a);
    add(&b);
    add(&c);
    add(&d);
    add(&e);
    add(&f);

    print();

    delete(&a);
    delete(&f);

    add(&f);

    print();

    clean();
}


