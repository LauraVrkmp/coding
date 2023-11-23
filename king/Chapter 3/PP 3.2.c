#include <stdio.h>

int main(void)
{
    int item, m, d, y;
    float price;
    
    printf("Enter item number: ");
    scanf("%d", &item);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy) : ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("Item\t\t\tUnit\t\t\tPurchase\n\t\t\tPrice\t\t\tDate\n");
    printf("%d\t\t\t$%7.2f\t\t%.2d/%.2d/%.4d\n", item, price, m, d, y);

    return 0;
}