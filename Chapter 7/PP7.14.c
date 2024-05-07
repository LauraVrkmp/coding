#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    double x, y = 1, xy, yxy, difference;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    do {
        xy = x / y;
        yxy = (y + xy) / 2;
        difference = fabs(yxy - y);
        y = yxy;
    } while (difference > 0.00001 * y);

    printf("Square root: %.5lf\n", y);

    return 0;
}