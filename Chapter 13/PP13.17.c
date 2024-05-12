#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define bool _Bool
#define MAX 100

bool is_palindrome(const char *message);

int main(void)
{
    char c, sentence[MAX], *p = sentence;
    int result;

    printf("Enter a message: ");

    while ((c = getchar()) != '\n' && p < sentence + MAX) {
        if (isalpha(c))
            *p++ = toupper(c);
    }
    *p = '\0';

    result = is_palindrome(sentence);
    if (result)
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(const char *message)
{
    const char *p = message, *q = message;

    while (*q)
        q++;
    q--;

    while (p < q) {
        if (*p != *q)
            return false;
        p++;
        q--;
    }

    return true;
}