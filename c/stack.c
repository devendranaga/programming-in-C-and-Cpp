#include <stdio.h>
#include <stdlib.h>

struct stack {
    void *elem;
    struct stack *next;
};

static struct stack *head;
static int count;

void *top()
{
    return head->elem;
}

int push(void *elem)
{
    struct stack *node;

    node = calloc(1, sizeof(struct stack));
    if (!node) {
        return -1;
    }

    node->elem = elem;

    if (!head) {
        head = node;
    } else {
        node->next = head;
        head = node;
    }

    count ++;

    return 0;
}

void *pop()
{
    struct stack *node;
    void *elem = NULL;

    if (head) {
        elem = head->elem;
        node = head;
        head = head->next;
        free(node);
        count --;
    }

    return elem;
}

int size()
{
    return count;
}

void empty(void (*callback)(void *elem))
{
    struct stack *node;
    struct stack *prev;

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
}

int main()
{
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int e = 5;
    int f = 6;

    push(&a);
    push(&b);
    push(&c);
    push(&d);
    push(&e);
    push(&f);

    printf("size : %d\n", size());

    while (1) {
        int *elem = pop();
        if (elem == NULL) {
            break;
        }
        printf("%d\n", *elem);
    }

    empty(NULL);

    return 0;
}


