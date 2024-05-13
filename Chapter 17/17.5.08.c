#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

struct node {
    int value;
    struct node *next;
};

struct node *top = NULL;

void make_empty(void)
{
    struct node *temp;

    while (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }
}

bool is_empty(void)
{
    return top == NULL;
}

void push(int i)
{
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("No memory was available.\n");
        return false;
    }
    new_node->value = i;
    new_node->next = top;
    top = new_node;
    return true;
}

int pop(void)
{
    struct node *temp;
    int i;
    
    if (is_empty()) {
        printf("Stack is empty!\n");
        exit(EXIT_FAILURE);
    } else {
        i = top->value;
        temp = top;
        top = top->next;
        free(temp);
        return i;
    }
}