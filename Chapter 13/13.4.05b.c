#include <stdio.h>
#include <ctype.h>

void capitalize(char str[]);

int main(void)
{
    char str[] = "uppercase";

    capitalize(str);

    printf("%s", str);

    return 0;
}

void capitalize(char str[])
{
    char *c = str;

    while (*c != '\0') {
        if (isalpha(*c))
            *c = toupper(*c);
        c++;
    }
}