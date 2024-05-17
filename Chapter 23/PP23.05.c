#include <stdio.h>
#include <math.h>

#ifndef M_E
#define M_E 2.718281828
#endif

int main(void)
{
    double P, r, t, result;

    printf("Enter amount deposited: ");
    scanf("%lf", &P);
    printf("Enter interest rate: ");
    scanf("%lf", &r);
    printf("Enter number of years: ");
    scanf("%lf", &t);

    r /= 100;

    result = P * exp(r * t);
    printf("Total compounded: $%.2lf\n", result);

    return 0;
}