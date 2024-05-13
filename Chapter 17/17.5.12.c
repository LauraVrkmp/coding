#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *find_last(struct node *list, int n)
{
    struct node *p = NULL;

    while (list != NULL) {
        if (list->value == n)
            p = list;
        list = list->next;
    }

    return p;
}