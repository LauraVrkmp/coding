#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>

double try_math_func(double (*f)(double), double x, const char *string);

int main(void)
{
    double x = 25.0, y;
    y = try_math_func(sqrt, x, "Error in call of sqrt");
    printf("The result is %.2lf\n", y);
    return 0;
}

double try_math_func(double (*f)(double), double x, const char *string)
{
    errno = 0;
    double result = (*f)(x);
    if (errno != 0) {
        perror(string);
        exit(EXIT_FAILURE);
    }
    return result;
}