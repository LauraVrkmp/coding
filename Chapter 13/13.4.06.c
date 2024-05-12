#include <stdio.h>
#include <string.h>

void censor(char str[]);

int main(void)
{
    char str[] = "food fool";

    censor(str);

    printf("%s", str);

    return 0;
}

void censor(char str[])
{
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] ==  'f' && str[i + 1] == 'o' && str[i + 2] == 'o')
            str[i] = str[i + 1] = str[i + 2] = 'x';
    }
}