#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *strdup(const char *s)
{
    char *copy;
    copy = (char *)malloc(sizeof(s) + 1);

    if (copy == NULL) {
        printf("Error: retrieved a null pointer\n");
        return NULL;
    }
    
    strcpy(copy, s);
    return copy;
}