#include <ctype.h>
#include <stdbool.h>   /* C99 only */
#include <stdio.h>

int main(void)
{
    bool in_word = false;
    char ch;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch) && !in_word) {
            putchar(toupper(ch));
            in_word = true;
        } else if (isspace(ch)) {
            in_word = false;
            putchar(ch);
        } else
            putchar(ch);
    }

    return 0;
}