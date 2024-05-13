#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *delete_from_list(struct node **list, int n)
{
    struct node *item = *list;
    while (item) {
        if (item->value == n) {
            *list = item->next;
            free(item);
            break;
        }
        list = &item->next;
        item = item->next;
    }

    return *list;
}