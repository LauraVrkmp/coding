#include <stdio.h>

#define MAX 100

int main(void)
{
    char c, sentence[MAX];
    int n = 0;
    int i;

    printf("Enter a message: ");

    while ((c = getchar()) != '\n' && n <= MAX) {
        sentence[n++] = c;
    }

    printf("Reversal is: ");

    for (i = n - 1; i >= 0; i--) {
        printf("%c", sentence[i]);
    }

    return 0;
}