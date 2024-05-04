#include <stdio.h>

int main(void)
{
    int number, start;

    printf("Enter number of days in month: ");
    scanf("%d", &number);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);

    for (int i = 1; i < start; i++) {
        printf("   ");
    }
    
    for (int j = 1; j <= number; j++) {
        printf("%3d", j);
        if ((start + j - 1) % 7 == 0) {
            printf("\n");
        }
    }

    return 0;
}