#include <stdio.h>

int compute(int x);

int main(void)
{
    int x;

    printf("Enter a value for x: ");
    scanf("%d", &x);

    printf("Result: %d\n", compute(x));

    return 0;
}

int compute(int x)
{
    return ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
}