#include <stdio.h>

int main(void)
{
    // The number that starts causing trouble is 46341.
    // Int is stored in 32 bit.
    
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++)
        printf("%10d%10d\n", i, i * i);

    return 0;
}