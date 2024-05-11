#include <stdio.h>

int main(void)
{
    int shares;
    float commission_original, commission_rival, price, value;

    printf("Enter number of shares: ");
    scanf("%d", &shares);
    printf("Enter price per share: ");
    scanf("%f", &price);

    value = shares * price;

    // original broker
    if (value < 2500.00f)
        commission_original = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission_original = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission_original = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission_original = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission_original = 155.00f + .0011f * value;
    else
        commission_original = 255.00f + 0.0009f * value;

    if (commission_original < 39.00f)
        commission_original = 39.00f;

    // rival broker
    if (shares < 2000)
        commission_rival = 33 + 0.03 * shares;
    else
        commission_rival = 33 + 0.02 * shares;

    printf("Commission at the original broker: $%.2f\n", commission_original);
    printf("Commission at the rival broker: $%.2f\n", commission_rival);

    return 0;
}