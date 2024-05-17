#include <stdio.h>
#include <string.h>

int numchar(const char *s, char ch);

int main(void)
{
    char str[] = "Form follows function.";
    char ch = 'o';

    printf("The %c is present %d times\n", ch, numchar(str, ch));
    return 0;
}


int numchar(const char *s, char ch)
{
    s = strchr(s, ch);
    int count = 0;

    while (s != NULL) {
        count++;
        s = strchr(s + 1, ch);
    }

    return count;
}