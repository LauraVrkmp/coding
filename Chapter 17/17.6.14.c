#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void *delete_from_list(struct node **list, int n)
{
    struct node *entry = *list;

    while (entry != NULL) {
        if (entry->value == n) {
            *list = entry->next;
            free(entry);
        }
        list = &entry->next;
        entry = entry->next;
    }
}