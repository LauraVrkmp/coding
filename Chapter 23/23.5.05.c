#include <ctype.h>
#include <string.h>

long int is_hex(char *s)
{
    while (*s) {
        if (!isxdigit(*s))
            return -1;
        s++;
    }
    return strtol(s, NULL, 16);
}