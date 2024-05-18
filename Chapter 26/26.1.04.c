#include <stdio.h>
#include <stdarg.h>

void display(int n, ...);

int main(void)
{
    display(4, "Special", "Agent", "Dale", "Cooper");
    return 0;
}

void display(int n, ...)
{
    va_list ap;
    int i;
    char *string;

    va_start(ap, n);

    for (i = 0; i < n; i++)
    {
        string = va_arg(ap, char *);
        while (*string)
        {
            putchar(*string);
            string++;
        }
        if (i < n - 1)
            putchar(' ');
    }
    putchar('\n');

    va_end(ap);
}