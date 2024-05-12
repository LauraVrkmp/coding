#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define bool _Bool
#define MAX 100

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char first_word[MAX + 1];
    char second_word[MAX + 1];
    char c, *p = first_word, *q = second_word;
    bool anagram;

    printf("Enter first word: ");

    while ((c = getchar()) != '\n' && p < first_word + MAX)
        *p++ = toupper(c);
    *p = '\0';

    printf("Enter second word: ");

    while ((c = getchar()) != '\n' && q < second_word + MAX)
        *q++ = toupper(c);
    *q = '\0';

    anagram = are_anagrams(first_word, second_word);

    if (anagram)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");
    
    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int letters[26] = {0};
    int *p = letters;

    while (*word1) {
        letters[*word1 - 'A']++;
        *word1++;
    }

    while (*word2) {
        letters[*word2 - 'A']--;
        *word2++;
    }

    while (*p) {
        if (*p != 0)
            return false;
        p++;
    }

    return true;
}