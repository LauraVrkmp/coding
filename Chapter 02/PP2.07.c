#include <stdio.h>

int main(void)
{
    int dollars, twenty, ten, five, one;

    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);

    twenty = dollars / 20;
    dollars = dollars - 20 * twenty;
    ten = dollars / 10;
    dollars = dollars - 10 * ten;
    five = dollars / 5;
    dollars = dollars - 5 * five;
    one = dollars / 1;

    printf("$20 bills: %d\n", twenty);
    printf("$10 bills: %d\n", ten);
    printf(" $5 bills: %d\n", five);
    printf(" $1 bills: %d\n", one);

    return 0;
}
