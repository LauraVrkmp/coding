#include <stdio.h>

char fput_string(char *s, FILE *stream)
{
    while (*s != '\0') {
        if (putc(*s, stream) == EOF)
            return EOF;
        s++;
    }

    return 0;
}