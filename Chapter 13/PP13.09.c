#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char *sentence);

int main(void)
{
    int n;
    char sentence[100 + 1], c, *p = sentence;

    printf("Enter a sentence: ");
    while ((c = getchar()) != '\n' && p < sentence + 100) {
        *p++ = c;
    }
    *p = '\0';

    n = compute_vowel_count(sentence);

    printf("Your sentence contains %d vowels.\n", n);
    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int count = 0;

    while (*sentence) {
        switch (toupper(*sentence)) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                count++;
                break;
            default:
                break;
        }

        sentence++;
    }

    return count;
}