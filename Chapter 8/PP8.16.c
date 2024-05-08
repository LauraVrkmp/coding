#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int seen[26] = {0};
    int i;
    char c;

    printf("Enter first word: ");

    for (i = 0; (c = getchar()) != '\n'; i++) {
        if (isalpha(c)) {
            i = toupper(c) - 'A';
            seen[i] += 1;
        }
    }

    printf("Enter second word: ");

    for (i = 0; (c = getchar()) != '\n'; i++) {
        if (isalpha(c)) {
            i = toupper(c) - 'A';
            seen[i] -= 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (seen[i] == 1) {
            printf("The words are not anagrams.");
            return 0;
        }
    }

    printf("The words are anagrams.");
    
    return 0;
}