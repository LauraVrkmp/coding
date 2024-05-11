#include <stdio.h>

int main(void)
{
    int input, hundredth, tenth, oneth;
    
    printf("Enter a three-digit number: ");
    scanf("%d", &input);

    hundredth = input / 100;
    tenth = input / 10 % 10;
    oneth = input % 10;

    printf("The reversal is: %d%d%d\n", oneth, tenth, hundredth);

    return 0;
}