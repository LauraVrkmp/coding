#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? \
                    (c) - 'a' + 'A' : (c))

int main(void)
{
    char s[4];
    int i = 0;

    strcpy(s, "abcd");
    putchar(TOUPPER(s[++i]));

    printf("\n");

    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));

    printf("\n");

    return 0;    
}