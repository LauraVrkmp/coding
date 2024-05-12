#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void remove_filename(char *url);
size_t my_strlen(const char *s);

int main(void)
{
    char url[] = "http://www.knking.com/index.html";

    remove_filename(url);

    printf("%s", url);

    return 0;
}

void remove_filename(char *url)
{
    int length = my_strlen(url);
    char *p = url + length - 1;

    for (; p >= url; p--) {
        if (*p == '/') {
            *p = '\0';
            break;
        }
    }
}

size_t my_strlen(const char *s)
{
    const char *p = s;

    while (*s)
        s++;

    return s - p;
}