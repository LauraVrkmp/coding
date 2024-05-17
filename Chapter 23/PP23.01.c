#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, x1, x2;

    printf("Enter value a: ");
    scanf("%lf", &a);
    printf("Enter value b: ");
    scanf("%lf", &b);
    printf("Enter value c: ");
    scanf("%lf", &c);

    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        printf("The roots are complex\n");
    } else {
        x1 = (-b - sqrt(discriminant)) / (2 * a);
        x2 = (-b + sqrt(discriminant)) / (2 * a);
        printf("The value of the first x is %.4lf\n"
               "The value of the second x is %.4lf\n", x1, x2);
    }
    
    return 0;
}