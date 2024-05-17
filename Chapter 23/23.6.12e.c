#include <stdio.h>
#include <string.h>

char *my_strset(char *s, char ch);

int main(void)
{
    char ch = 'b';
    char s[11] = "to replace";
    my_strset(s, ch);
    s[10] = '\0';

    char *p = s;

    while (*p) {
        printf("%c\n", *p);
        p++;
    }

    return 0;
}

char *my_strset(char *s, char ch)
{
    char *p = s;
    while (*p) {
        *p = ch;
        p++;
    }

    return s;
}