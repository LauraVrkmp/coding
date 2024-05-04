#include <stdio.h>

int main(void)
{
    int input, octal1, octal2, octal3, octal4, octal5;

    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &input);

    octal5 = input % 8;
    octal4 = input / 8 % 8;
    octal3 = input / 8 / 8 % 8;
    octal2 = input / 8 / 8 / 8 % 8;
    octal1 = input / 8 / 8 / 8 / 8 % 8;

    printf("In octal, your number is: %d%d%d%d%d\n", octal1, octal2, octal3, octal4, octal5);

    return 0;
}