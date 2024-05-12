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
int evaluate_RPN_expression(const char *expression);

int main(void)
{
    char c, expression[STACK_SIZE], *p;
    int result;

    while (1) {
        p = expression;
        
        printf("Enter an RPN expression: ");

        while ((c = getchar()) != '\n' && p < expression + STACK_SIZE)
            *p++ = c;
        *p = '\0';

        result = evaluate_RPN_expression(expression);

        printf("Value of expression: %d\n", result);

        p = expression;
        while (*p)
            *p++ = '\0';
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

int evaluate_RPN_expression(const char *expression)
{
    char temp1, temp2;
    int value;
    
    while (*expression) {
        if (isdigit(*expression))
            push(*expression - '0');
        else if (*expression == '+')
            push(pop() + pop());
        else if (*expression == '-') {
            temp1 = pop();
            temp2 = pop();
            push(temp2 - temp1);
        }
        else if (*expression == '*')
            push(pop() * pop());
        else if (*expression == '/') {
            temp1 = pop();
            temp2 = pop();
            push(temp2 / temp1);
        }
        else if (*expression == '=') {
            value = pop();
            make_empty();
            return value;
        }
        else if (*expression == ' ') {
            ;
        }
        else
            exit(EXIT_FAILURE);
        
        expression++;
    }
}