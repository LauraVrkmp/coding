#include <stdio.h>

int main(void)
{
    int speed;
    
    printf("Enter the wind speed (in knots): ");
    scanf("%d", &speed);

    if (speed < 1)
        printf("The corresponding description is calm.\n");
    else if (speed <= 3)
        printf("The corresponding description is light air.\n");
    else if (speed <= 27)
        printf("The corresponding description is breeze.\n");
    else if (speed <= 47)
        printf("The corresponding description is gale.\n");
    else if (speed <= 63)
        printf("The corresponding description is storm.\n");
    else
        printf("The corresponding description is hurricane.\n");
    
    return 0;
}