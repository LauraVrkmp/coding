#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c, initial;
    char last_name[20] = {0};
    int i;

    printf("Enter a first and last name: ");

    while ((c = getchar()) == ' ');

    initial = c;

    while ((c = getchar()) != ' ');

    for (i = 0; (c = getchar()) != '\n'; i++)
        last_name[i] = c;

    printf("You entered the name: ");
    for (i = 0; last_name[i] != '\0'; i++)
        putchar(last_name[i]);
    printf(", %c.", initial);

    return 0;
}