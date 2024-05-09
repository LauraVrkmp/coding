#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    char c;

    printf("Enter parentheses and/or braces: ");

    while ((c = getchar()) != '\n') {
        if (c == '{' || c == '(')
            push(c);
        else if (c == '}' && pop() != '{') {
            printf("Parentheses/braces are not nested properly.\n");
            return 0;
        } else if (c == ')' && pop() != '(') {
            printf("Parentheses/braces are not nested properly.\n");
            return 0;
        }
    }

    if (!is_empty()) {
        printf("Parentheses/braces are not nested properly.\n");
        return 0;
    }

    printf("Parentheses/braces are nested properly.\n");

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
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    else
        contents[top++] = i;
}

char pop(void)
{
    if (is_empty()) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    else
        return contents[--top];
}