#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

void deleteList(struct node *first)
{
    struct node *temp;
    struct node *p = first;
    
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}