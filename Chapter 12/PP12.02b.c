#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
    char c, sentence[MAX], *p = sentence, *q;

    printf("Enter a message: ");

    while ((c = getchar()) != '\n' && p < sentence + MAX) {
        if (isalpha(c))
            *p++ = toupper(c);
    }

    p--;

    for (q = sentence; q < p; q++, p--) {
        if (*p != *q) {
            printf("Not a palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");
    return 0;
}