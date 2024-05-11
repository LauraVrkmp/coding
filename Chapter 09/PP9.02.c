#include <stdio.h>

float income_tax(float income);

int main(void)
{
    float income, tax;

    printf("Enter taxable income: ");
    scanf("%f", &income);

    printf("Your tax due is $%.2f", income_tax(income));

    return 0;
}

float income_tax(float income)
{
    if (income < 750)
        return income * 0.01f;
    else if (income <= 2250)
        return 7.50f + (income - 750) * 0.02f;
    else if (income <= 3750)
        return 37.50f + (income - 2250) * 0.03f;
    else if (income <= 5250)
        return 82.50f + (income - 3750) * 0.04f;
    else if (income <= 7000)
        return 142.50f + (income - 5250) * 0.05f;
    else
        return 230.00f + (income - 7000) * 0.06f;
}
