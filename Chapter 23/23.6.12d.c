#include <stdio.h>
#include <string.h>

char *strrev(char *s);

int main(void)
{
    char str[] = "This sentence should be reversed";
    strrev(str);
    printf("%s\n", str);
    return 0;
}

char *strrev(char *s)
{
    int i, middle, length = strlen(s);
    char temp;

    if (length % 2 == 0)
        middle = length / 2 - 1;
    else
        middle = length / 2;

    for (i = 0; i <= middle; i++) {
        temp = s[i];
        s[i] = s[length - 1 - i];
        s[length - 1 - i] = temp;
    }

    return s;
}