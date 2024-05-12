#include "stack.h"

int main(void)
{
    char ch;
    int temp1, temp2;

    while (1) {
        top = 0;
        
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