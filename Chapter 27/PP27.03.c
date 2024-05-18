#include <stdio.h>
#include <math.h>

int main(void)
{
    double r, theta, a, b;

    printf("Enter a value for r: ");
    scanf("%lf", &r);
    printf("Enter a value for theta: ");
    scanf("%lf", &theta);

    a = r * cos(theta);
    b = r * sin(theta);

    printf("In Cartesian form: %lf %c %lfi\n", 
            a, b < 0 ? '-' : '+', fabs(b));

    return 0;
}