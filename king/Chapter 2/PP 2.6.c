#include <stdio.h>

int main(void)
{
    int x;

    printf("Give a value for x: ");
    scanf("%d", &x);

    int result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) - 6;

    printf("The polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 results in: %d\n", result);

    return 0;
}