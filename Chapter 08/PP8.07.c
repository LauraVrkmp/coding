#include <stdio.h>

#define DIMENSION 5

int main(void)
{
    int table[DIMENSION][DIMENSION];
    int i, j, temp_total;

    for (i = 0; i < DIMENSION; i++) {
        printf("Enter row %d: ", i + 1);

        for (j = 0; j < DIMENSION; j++) {
            scanf("%d", &table[i][j]);
        }
    }

    printf("Row totals:");

    for (i = 0; i < DIMENSION; i++) {
        temp_total = 0;
        for (j = 0; j < DIMENSION; j++) {
            temp_total += table[i][j];
        }
        printf(" %d", temp_total);
    }

    printf("\nColumn totals:");

    for (i = 0; i < DIMENSION; i++) {
        temp_total = 0;
        for (j = 0; j < DIMENSION; j++) {
            temp_total += table[j][i];
        }
        printf(" %d", temp_total);
    }

    printf("\n");
    
    return 0;    
}