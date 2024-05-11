#include <stdio.h>

int main(void)
{
    int octal, hexadecimal;

    printf("Enter an octal number: ");
    scanf("%o", &octal);
    printf("The octal in decimal is %d\n", octal);

    printf("Enter a hexadecimal number: ");
    scanf("%x", &hexadecimal);
    printf("The octal in decimal is %d\n", hexadecimal);

    printf("Enter a hexadecimal number: ");
    scanf("%x", &hexadecimal);
    printf("The hexadecimal in decimal is %d\n", hexadecimal);

    return 0;
}