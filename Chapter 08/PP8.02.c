#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int seen[10] = {0};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;
        seen[digit] += 1;
        n /= 10;
    }

    printf("Digit:\t\t");
    for (int i = 0; i < 10; i++) {
        printf("%3d", i);
    }

    printf("\nOccurrences:\t");
    for (int i = 0; i < 10; i++) {
        printf("%3d", seen[i]);
    }

    printf("\n");

    return 0;
}