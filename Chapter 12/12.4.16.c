#include <stdio.h>

#define DAYS 7
#define HOURS 24

int main(void)
{
    int temperatures[DAYS][HOURS];

    int i;

    for (i = 0; i < DAYS; i++)
        printf("Day %d: %d\n", i + 1, find_largest(temperatures[i], HOURS));

    return 0;
}

int find_largest(int a[], int n)
{
    int *p = a;
    int max = *p++;

    while (p++ < a + n) {
        if (*p > max)
            max = *p;
    }

    return max;
}