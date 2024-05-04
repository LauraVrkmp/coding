#include <stdio.h>

int main(void)
{
    float e = 1;
    int factorial;
    int n;

    printf("Enter an integer n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        
        factorial = 1;

        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        
        e += 1.0f / factorial;    
    }

    printf("The approximation of e is %f\n", e);

    return 0;
}