#include <stdio.h>

#define DAYS 7
#define HOURS 24

int main(void)
{
    int temperatures[DAYS][HOURS];

    int *p;
    int i;

    for (p = temperatures[i]; p < temperatures[i] + HOURS; p++) {
        printf("%d\n", *p);
    }

    return 0;
}