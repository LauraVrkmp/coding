#include <stdlib.h>

int *create_array(int n, int initial_value)
{
    int *result, *i;
    
    result = (int *) malloc(sizeof(int) * n);
    if (result == NULL)
        return NULL;
    for (i = result; i < result + n; i++)
        *i = initial_value;
    
    return result;
}