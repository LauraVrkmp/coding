#include <stdio.h>

int main(void)
{
    float largest = 0.0f;
    float input;

    do {
        printf("Enter a number: ");
        scanf("%f", &input);

        if (input > largest) {
            largest = input;
        } 
    } while (input > 0);

    printf("\nThe largest number entered was %f\n", largest);

    return 0;
}