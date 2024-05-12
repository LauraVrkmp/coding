#include <stdio.h>

#define MAX 100

void reverse(char *message);

int main(void)
{
    char c, sentence[MAX], *p = sentence;

    printf("Enter a message: ");

    while ((c = getchar()) != '\n' && p < sentence + MAX) {
        *p++ = c;
    }
    *p = '\0';

    printf("Reversal is: ");

    reverse(sentence);
    printf("%s\n", sentence);

    return 0;
}

void reverse(char *message)
{
    char *p = message, *q = message, temp;

    while (*q)
        q++;
    q--;

    while (p < q) {
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}