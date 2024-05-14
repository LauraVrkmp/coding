#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_MAX 100

typedef int Item;
typedef struct queue_t *Queue;

struct queue_t {
    Item content[QUEUE_MAX];
    int empty_index;
    int removal_index;
    int items;
};

static void terminate(const char *message);
void insert(Queue q, Item i);
Item remove_item(Queue q);
Item peek_first(Queue q);
Item peek_last(Queue q);
bool is_empty(Queue q);

static void terminate(const char *message)
{
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

void insert(Queue q, Item i)
{
    if (q->items < QUEUE_MAX) {
        q->content[q->empty_index] = i;
        q->empty_index = ((q->empty_index + 1) == QUEUE_MAX) ?
            0 : q->empty_index + 1;
        q->items++;
    } else {
        terminate("Error: queue is full\n");
    }
}

Item remove_item(Queue q)
{
    if (!is_empty(q)) {
        int i = q->content[q->removal_index];
        q->removal_index++;
        q->items--;
        return i;
    } else
        terminate("Error: queue is empty\n");
}

Item peek_first(Queue q)
{
    if (!is_empty(q)) {
        return q->content[q->removal_index];
    } else
        terminate("Error: queue is empty\n");
}

Item peek_last(Queue q)
{
    if (!is_empty(q)) {
        if (q->empty_index == 0)
            return q->content[QUEUE_MAX - 1];
        else
            return q->content[q->empty_index - 1];
    } else
        terminate("Error: queue is empty\n");
}

bool is_empty(Queue q)
{
    return q->items == 0;
}