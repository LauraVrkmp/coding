#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hours, minutes;
    char c;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hours, &minutes, &c);

    hours = (hours == 12 ? 0 : hours);
    hours = (toupper(c) == 'P' ? 12 : 0) + hours;

    printf("Equivalent 24-hour time: %.2d:%.2d\n", hours, minutes);

    return 0;
}