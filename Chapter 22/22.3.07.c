#include <stdio.h>

int main(void)
{
    int i, j, n;
    float x;

    n = scanf("%d%f%d", &i, &x, &j);

    printf("i is %d, j is %d, n is %d, x is %f\n", i, j, n, x);

    return 0;
}