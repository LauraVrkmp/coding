#include <stdio.h>
#include <ctype.h>

void capitalize(char str[])
{
    int i = 0;

    while (str[i] != '\0') {
        if (isalpha(str[i]))
            topupper(str[i]);
        i++;
    }
}