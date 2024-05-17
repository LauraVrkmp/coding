#include <stdio.h>
#include <string.h>

int count_words(char *sentence);

int main(void)
{
    char sentence[] = "   Hier moet je goed over nadenken   ";
    int count = count_words(sentence);
    printf("The sentence has %d words\n", count);
}

int count_words(char *sentence)
{
    int count = 0;

    char *p = strtok(sentence, " ");
    while (p != NULL) {
        count ++;
        p = strtok(NULL, " ");
    }

    return count;
}