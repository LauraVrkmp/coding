#include <stdio.h>
#include <math.h>

float round_nearest(float x, int n);

int main(void)
{
    float x = 3.14159;
    int n = 3;
    
    printf("x was %.5f, is now %.3f\n", x, round_nearest(x, n));
    return 0;
}

float round_nearest(float x, int n)
{
    x *= pow(10, n);
    x = nearbyint(x);
    x /= pow(10, n);
    return (float) x;
}