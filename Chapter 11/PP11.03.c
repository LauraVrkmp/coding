#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int main(void)
{
    int nom, denom, red_nom, red_denom;

    printf("Enter a fraction: ");
    scanf("%d/%d", &nom, &denom);

    reduce(nom, denom, &red_nom, &red_denom);

    printf("In lowest terms: %d/%d\n", red_nom, red_denom);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
    int remainder, m, n;

    m = numerator;
    n = denominator;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;

}