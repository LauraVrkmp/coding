#include <stdio.h>

int main(void)
{
    int hours, minutes;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    printf("%d\n", hours);

    if (hours == 0)
    {
        printf("Equivalent 12-hour time: 12:%.2d AM\n", minutes);
    }
    else if (hours < 12)
    {
        printf("Equivalent 12-hour time: %d:%.2d AM\n", hours, minutes);
    }
    else if (hours == 12)
    {
        printf("Equivalent 12-hour time: %d:%.2d PM\n", hours, minutes);

    }
    else
    {
        printf("Equivalent 12-hour time: %d:%.2d PM\n", hours - 12, minutes);
    }

    return 0;
}