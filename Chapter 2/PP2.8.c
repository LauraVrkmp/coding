#include <stdio.h>

int main(void)
{
    float loan, interest_rate, monthly_payment;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float monthly_interest_percentage = interest_rate / 12 / 100;

    float first_payment = loan - monthly_payment + monthly_interest_percentage * loan;
    printf("Balance remaining after first payment: %0.2f\n", first_payment);
    float second_payment = first_payment - monthly_payment + monthly_interest_percentage * first_payment;
    printf("Balance remaining after first payment: %0.2f\n", second_payment);
    float third_payment = second_payment - monthly_payment + monthly_interest_percentage * second_payment;
    printf("Balance remaining after first payment: %0.2f\n", third_payment);

    return 0;
}