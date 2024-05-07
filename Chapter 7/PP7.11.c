#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c, initial;

    printf("Enter a first and last name: ");
    scanf(" %c", &initial);

    while ((c = getchar()) != ' ');

    while ((c = getchar()) == ' ');

    do {
        putchar(c);
    } while ((c = getchar()) != ' ' && c != '\n');

    printf(", %c.", initial);

    return 0;
}