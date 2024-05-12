#include <stdio.h>
#include <ctype.h>

void reverse_name(char *name);

int main(void)
{
    char name[100 + 1];
    char *p = name, c;

    printf("Enter a first and last name: ");

    while ((c = getchar()) != '\n' && p < name + 100) {
        *p++ = c;
    }
    *p = '\0';

    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    char *p = name, initial;
    
    while (*p++ == ' ');
    initial = *--p;

    while (*p && *p++ != ' ');
    while (*p == ' ')
        p++;
    while (*p && *p != ' ')
        putchar(*p++);

    printf(", %c.", initial);
}