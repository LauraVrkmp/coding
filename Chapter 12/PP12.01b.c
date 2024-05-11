#include <stdio.h>

#define MAX 100

int main(void)
{
    char c, sentence[MAX], *p = sentence;

    printf("Enter a message: ");

    while ((c = getchar()) != '\n' && p < sentence + MAX) {
        *p++ = c;
    }

    p--;

    printf("Reversal is: ");

    while (p >= sentence)
        printf("%c", *p--);
    
    return 0;
}