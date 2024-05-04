#include <stdio.h>

int main(void)
{
    int input1, input2, input3;
    
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &input1, &input2, &input3);

    printf("The reversal is: %d%d%d\n", input3, input2, input1);

    return 0;
}