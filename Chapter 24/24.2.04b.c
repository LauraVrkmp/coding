#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

#define TRY_MATH_FUNC(f, x) try_math_func(f, x, "Error in call of " #f);

double try_math_func(double (*f)(double), double x, char *string);

int main(void)
{
    double x = 25.0, y;
    y = TRY_MATH_FUNC(sqrt, x);
    printf("The result is %.2lf\n", y);
    return 0;
}

double try_math_func(double (*f)(double), double x, char *string)
{
    errno = 0;
    double result = (*f)(x);
    if (errno != 0) {
        exit(EXIT_FAILURE);
    }
    return result;
}