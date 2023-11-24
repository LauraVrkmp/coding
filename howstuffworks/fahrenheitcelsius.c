#include <stdio.h>
#include <stdbool.h>

int main()
{
    float a, b, c;

    printf("Enter starting point: ");
    scanf("%f", &a);

    printf("Enter ending point: ");
    scanf("%f", &b);

    printf("Enter increment value: ");
    scanf("%f", &c);

    float temp = 81;
    bool d = true;

    while (a <= b)
    {
        if ((a > temp) && d){
            printf("%6.2f degrees F = %6.2f degrees C\n",
                temp, (temp - 32.0) * 5.0 / 9.0);
            d = false;
        }
        printf("%6.2f degrees F = %6.2f degrees C\n",
            a, (a - 32.0) * 5.0 / 9.0);
        
        a = a + c;
    }
    return 0;
}