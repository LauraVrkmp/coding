#include <stdio.h>

int main(void)
{
    int m, n, remainder, nom, denom;

    printf("Enter a fraction: ");
    scanf("%d/%d", &nom, &denom);

    m = nom;
    n = denom;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    nom = nom / m;
    denom = denom / m;

    printf("In lowest terms: %d/%d\n", nom, denom);

    return 0;
}