#include <stdio.h>

int main(void)
{
    float e = 1;
    float term = 1;
    float epsilon;
    int factorial;
    int n;

    printf("Enter a positive float epsilon (<< 1): ");
    scanf("%f", &epsilon);

    for (int i = 1; term > epsilon; i++) {
        
        factorial = 1;

        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        
        e += 1.0f / factorial;
        term = 1.0f / factorial;
    }

    printf("The approximation of e is %f\n", e);

    return 0;
}