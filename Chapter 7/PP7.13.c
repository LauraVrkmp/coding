#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    float length = 0;
    int words = 1;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n') {
        if (c == ' ')
            words++;
        else
            length++;
    }

    printf("Average word length: %.1f\n", length / words);

    return 0;
}