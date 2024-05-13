#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 50
#define MAX_LENGTH 20

int read_line(char str[], int n);
int compare_strings(const void *str1, const void *str2);

int main(void)
{
    char *strings[MAX_WORDS];
    char msg_str[MAX_LENGTH + 1];
    int i, j, num_strings = 0;

    for (;;) {
        printf("Enter a word: ");
        i = read_line(msg_str, MAX_LENGTH);

        if (i == 0)
            break;
        
        strings[num_strings] = malloc(strlen(msg_str) + 1);
        if (strings[num_strings] == NULL) {
            printf("No space left.\n");
            break;
        }

        strcpy(strings[num_strings], msg_str);
        num_strings++;
    }

    qsort(strings, num_strings, sizeof(char *), compare_strings);

    printf("\nIn sorted order: ");
    for (j = 0; j < num_strings; j++) {
        printf("%s ", strings[j]);
        free(strings[j]);
    }
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int compare_strings(const void *str1, const void *str2)
{
    return strcmp(*(char **)str1, *(char **)str2);
}