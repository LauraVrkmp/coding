#include <stdlib.h>

int compare(const void *p, const void *q);

int main(void)
{
    int a[100];
    
    qsort(&a[50], 50, sizeof(a[0]), compare);
}