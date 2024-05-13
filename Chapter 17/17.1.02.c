#include <stdlib.h>
#include <string.h>

char *duplicate(const char *str)
{
    char *result;
    result = malloc(strlen(str) + 1);
    if (result == NULL) {
        return NULL;
    }
    strcpy(result, str);
    return result;
}