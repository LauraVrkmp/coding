#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

char *vstrcat(const char *first, ...);

int main(void)
{
    char *result = vstrcat("hello", "there", NULL);

    printf("%s", result);
    free(result);

    return 0;
}

char *vstrcat(const char *first, ...)
{
    va_list ap;
    int size;
    char *string, *result;

    va_start(ap, first);
    size = strlen(first);

    while ((string = va_arg(ap, char *)) != NULL) {
        size += strlen(string);
    }
    size++;

    if ((result = malloc(size)) == NULL) {
            printf("Error: malloc failed.\n");
            va_end(ap);
            return NULL;
    }

    va_end(ap);
    va_start(ap, first);
    strcpy(result, first);

    while ((string = va_arg(ap, char *)) != NULL) {
        strcat(result, string);
    }

    va_end(ap);
    return result;
}