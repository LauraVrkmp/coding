#include <stdlib.h>

void *my_malloc(size_t n)
{
    void *p;
    if ((p = malloc(n)) == NULL) {
        printf("Error: malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    return p;
}