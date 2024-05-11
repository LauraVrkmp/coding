#include <stdio.h>

int main(void)
{
    int m = 2;
    int n;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while (m * m <= n) {
        printf("%d\n", m * m);
        m += 2;
    }

    return 0;
}