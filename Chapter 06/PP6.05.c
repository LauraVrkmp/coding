#include <stdio.h>

int main(void)
{
    int input, tenth, oneth;
    
    printf("Enter a number: ");
    scanf("%d", &input);

    printf("The reversal is: ");

    do {
        printf("%d", input % 10);
        input /= 10;
    } while (input != 0);

    printf("\n");

    return 0;
}