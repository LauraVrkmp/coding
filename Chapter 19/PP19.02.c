#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct stack_type *Stack;
typedef int Item;

struct node {
    Item value;
    struct node *next;
};

struct stack_type {
    struct node *top;
};

void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
char pop(Stack s);
static void terminate(char *message);

int main(void)
{
    Stack s;    
    char ch;
    int temp1, temp2;

    while (1) {
        printf("Enter an RPN expression: ");

        while (1) {
            scanf(" %c", &ch);

            if (isdigit(ch))
                push(s, ch - '0');
            else if (ch == '+')
                push(s, pop(s) + pop(s));
            else if (ch == '-') {
                temp1 = pop(s);
                temp2 = pop(s);
                push(s, temp2 - temp1);
            }
            else if (ch == '*')
                push(s, pop(s) * pop(s));
            else if (ch == '/') {
                temp1 = pop(s);
                temp2 = pop(s);
                push(s, temp2 / temp1);
            }
            else if (ch == '=') {
                printf("Value of expression: %d\n", pop(s));
                make_empty(s);
                break;
            }
            else
                exit(EXIT_FAILURE);
        }
    }   
        
    return 0;
}

Stack create()
{
    Stack s;
    if ((s = malloc(sizeof(struct stack_type))) == NULL)
        terminate("Error: malloc failed in create()");
    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, Item i)
{
    if (is_full(s))
        terminate("Error: stack overflow");
    struct node *new_node = malloc(sizeof(struct node));
    new_node->value = i;
    new_node->next = s->top;
    s->top = new_node;
}

char pop(Stack s)
{
    if (is_empty(s))
        terminate("Error: stack underflow");
    struct node *temp;
    Item value = s->top->value;
    temp = s->top;
    s->top = s->top->next;
    free(temp);
    return value;
}

static void terminate(char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}