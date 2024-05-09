#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

// external variables
char contents[STACK_SIZE] = {0};
int top = 0;

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char i);
char pop(void);

int main(void)
{
    char ch;
    int temp1, temp2;

    while (1) {
        printf("Enter an RPN expression: ");

        while (1) {
            scanf(" %c", &ch);

            if (isdigit(ch))
                push(ch - '0');
            else if (ch == '+')
                push(pop() + pop());
            else if (ch == '-') {
                temp1 = pop();
                temp2 = pop();
                push(temp2 - temp1);
            }
            else if (ch == '*')
                push(pop() * pop());
            else if (ch == '/') {
                temp1 = pop();
                temp2 = pop();
                push(temp2 / temp1);
            }
            else if (ch == '=') {
                printf("Value of expression: %d\n", pop());
                make_empty();
                break;
            }
            else
                exit(EXIT_FAILURE);
        }
    }   
        
    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char i)
{
    if (is_full()) {
        printf("Expression is too complex\n");
        exit(EXIT_FAILURE);
    }
    else
        contents[top++] = i;
}

char pop(void)
{
    if (is_empty()) {
        printf("Not enough operands in expression\n");
        exit(EXIT_FAILURE);
    }
    else
        return contents[--top];
}