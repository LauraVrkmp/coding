#ifndef QUEUE.H
#define QUQUE.H

#include <stdbool.h>

typedef int Item;
typedef struct queue_t *Queue;

void insert(Queue, Item i);
int remove(Queue);
int peek_first(Queue);
int peek_last(Queue);
bool is_empty(Queue);

#endif