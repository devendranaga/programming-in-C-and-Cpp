#include <stdio.h>
#include <stdlib.h>

struct queue {
    void *elem;
    struct queue *next;
};

static struct queue *head;
static struct queue *tail;
static int count;

void *front()
{
    void *elem;

    if (head) {
        elem = head->elem;
    }

    return elem;
}

void *back()
{
    void *elem;

    if (tail) {
        elem = tail->elem;
    }

    return elem;
}

void empty(void (*callback)(void *elem))
{
    struct queue *node;
    struct queue *prev;

    node = head;
    prev = head;

    while (node) {
        prev = node;
        node = node->next;
        if (callback) {
            callback(prev->elem);
        }
        free(prev);
    }
    count = 0;
}

int size()
{
    return count;
}

int push(void *elem)
{
    struct queue *node;

    node = calloc(1, sizeof(struct queue));
    if (!node) {
        return -1;
    }

    node->elem = elem;

    if (!head) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    return 0;
}

void *pop()
{
    struct queue *node;
    void *elem = NULL;

    if (head != NULL) {
        node = head;
        elem = node->elem;
        head = head->next;
        free(node);
    }

    return elem;
}

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;
    int e = 50;
    int f = 60;

    push(&a);
    push(&b);
    push(&c);
    push(&d);
    push(&e);
    push(&f);

    printf("size : %d\n", size());
    printf("Front: %d\n", *(int *)front());
    printf("Back:  %d\n", *(int *)back());

    while (1) {
        int *elem = pop();
        if (!elem) {
            break;
        }
        printf("%d\n", *elem);
    }

    empty(NULL);

    return 0;
}




