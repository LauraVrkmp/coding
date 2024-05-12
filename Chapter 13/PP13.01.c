#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define MAX 20

size_t my_strlen(const char *s);
void read_line(char strp[], int n);

int main(void)
{
    char word[MAX + 1];
    char smallest_word[MAX + 1];
    char largest_word[MAX + 1];
    
    while (my_strlen(word) != 4) {    
        printf("Enter word: ");
        read_line(word, MAX);

        if (strcmp(word, smallest_word) < 0)
            strcpy(smallest_word, word);
        else if (strcmp(word, largest_word) > 0)
            strcpy(largest_word, word);
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);    

    return 0;
}

size_t my_strlen(const char *s)
{
    const char *p = s;

    while (*s)
        s++;

    return s - p;
}

void read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
}