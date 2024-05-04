#include <stdio.h>

int main(void)
{
    int input, tenth, oneth;
    
    printf("Enter a two-digit number: ");
    scanf("%d", &input);

    tenth = input / 10;
    oneth = input % 10;

    printf("The reversal is: %d%d\n", oneth, tenth);

    return 0;
}