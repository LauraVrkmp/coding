#include <stdio.h>
#include <string.h>

#define MAX_LEN 255

int main(void)
{
    char str[MAX_LEN], *p[MAX_LEN];
    int i = 0;

    printf("Enter words separated by single spaces: ");
    fgets(str, MAX_LEN, stdin);
    str[strlen(str) - 1] = '\0';

    if ((p[i] = strtok(str, " ")) == NULL)
        return 0;
    i++;

    while ((p[i] = strtok(NULL, " ")) != NULL)
        i++;
    for (i--; i >= 0; i--)
        printf("%s ", p[i]);
    printf("\n");

    return 0;
}