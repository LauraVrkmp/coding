#include <stdio.h>

int main(void)
{
    int first, second, third, fourth, max, min;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &first, &second, &third, &fourth);

    max = first;
    min = first;

    if (second > max)
        max = second;
    else if (second < min)
        min = second;
    
    if (third > max)
        max = third;
    else if (third < min)
        min = third;

    if (fourth > max)
        max = fourth;
    else if (fourth < min)
        min = fourth;

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}