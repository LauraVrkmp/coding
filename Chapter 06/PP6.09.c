#include <stdio.h>

int main(void)
{
    float loan, interest_rate, monthly_payment, balance;
    int payments;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);

    float monthly_interest_percentage = interest_rate / 12 / 100;

    printf("Enter the amount of payments: ");
    scanf("%d", &payments);

    balance = loan;

    for (int i = 0; i < payments; i++) {
        balance = balance - monthly_payment + monthly_interest_percentage * balance;
        printf("Balance remaining is: %0.2f\n", balance);
    }
    
    return 0;
}