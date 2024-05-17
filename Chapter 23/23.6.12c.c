#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *strlwr(char *s);

int main(void)
{
    char str[] = "This Should All Be Lower-Case";

    strlwr(str);
    printf("%s\n", str);

    return 0;
}

char *strlwr(char *s)
{
    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
    }

    return s;
}