#include <stdio.h>
#include <ctype.h>

double compute_average_word_length(const char *sentence);

int main(void)
{
    char sentence[101];
    char c, *p = sentence;
    double average;

    printf("Enter a sentence: ");

    while ((c = getchar()) != '\n' && p < sentence + 100) {
        *p++ = c;
    }
    *p = '\0';

    average = compute_average_word_length(sentence);

    printf("Average word length: %.1f\n", average);

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int length = 0, words = 1;

    while (*sentence) {
        if (*sentence == ' ')
            words++;        
        else
            length++;
        sentence++;
    }

    return (float) length / words;
}