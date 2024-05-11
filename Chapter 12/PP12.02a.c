#include <stdio.h>
#include <ctype.h>

#define MAX 100

int main(void)
{
    char c, sentence[MAX];
    int n = 0;
    int i;

    printf("Enter a message: ");

    while ((c = getchar()) != '\n' && n <= MAX) {
        if (isalpha(c))
            sentence[n++] = toupper(c);
    }

    n--;

    for (i = 0; i < n; i++, n--) {
        if (sentence[i] != sentence[n]) {
            printf("Not a palindrome\n");
            return 0;
        }
    }

    printf("Palindrome\n");
    return 0;
}