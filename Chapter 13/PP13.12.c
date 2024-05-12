#include <stdio.h>

#define WORDS 30
#define LETTERS 20

int main(void)
{
    int i = 0, j = 0;
    char sentence[WORDS][LETTERS + 1], terminate = 0, c;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n' && i < WORDS) {
        if (c == ' ') {
            sentence[i][j] = '\0';
            i++;
            j = 0;
            continue;
        }
        else if (c == '.' || c == '!' || c == '?') {
            terminate = c;
            sentence[i][j] = '\0';
            break;
        }
        else if (j < LETTERS)
            sentence[i][j++] = c;
    }

    printf("Reversal of sentence: ");

    while (i > 0)
        printf("%s ", sentence[i--]);

    printf("%s%c\n", sentence[i], terminate);

    return 0;
}