#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{
    int options[] = {7, 11, 15, 19};
    int length = sizeof(options) / sizeof(options[0]);
    int n;
    
    srand((unsigned) time(NULL));
    n = options[rand() % length];

    printf("%d\n", n);

    return 0;
}