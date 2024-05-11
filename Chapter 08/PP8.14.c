#include <stdio.h>

#define MAX_VALUE 40

int main(void)
{
    char array[MAX_VALUE] = {0};
    char terminate;
    char c;
    int i, j;

    printf("Enter a sentence: ");

    for (i = 0; (c = getchar()) != '\n' && i < MAX_VALUE; i++) {
       if (c == '!' || c == '.' || c == '?') {
            terminate = c;
            break;
        }
        array[i] = c;
    }

    printf("Reversal of sentence: ");
    while (i >= 0) {
        while (array[--i] != ' ' && i != 0);
        j = i == 0 ? 0 : i + 1;
        while (array[j] != ' ' && array[j] != '\0')
            putchar(array[j++]);
        if (i >= 0)
            putchar(' ');
    }

    printf("\b%c\n", terminate);

    return 0;
}