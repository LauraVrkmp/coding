#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

static struct node {
    Item item;
    struct node *next;
} *head = NULL, *tail = NULL;

static int items = 0;

static void terminate(const char *message);
void insert(Item i);
Item remove_item(void);
Item peek_first(void);
Item peek_last(void);
bool is_empty(void);

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void insert(Item i)
{
    struct node *new_node;
    if ((new_node = malloc(sizeof(struct node))) == NULL)
        terminate("Error: malloc failed\n");
    
    new_node->item = i;
    new_node->next = NULL;
    items++;

    if (head == NULL)
        head = tail = new_node;
    else {
        tail->next = new_node;
        tail = new_node;
    }
}

Item remove_item(void)
{
    if (!is_empty()) {
        struct node *temp = head;
        Item i = head->item;
        head = head->next;
        free(temp);
        items--;
        return i;
    } else
        terminate("Error: queue is empty\n");
}

Item peek_first(void)
{
    if (!is_empty()) {
        return head->item;
    } else
        terminate("Error: queue is empty\n");
}

Item peek_last(void)
{
    if (!is_empty()) {
        return tail->item;
    } else
        terminate("Error: queue is empty\n");
}

bool is_empty(void)
{
    return items == 0;
}