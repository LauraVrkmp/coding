#include <stdio.h>

int main(void)
{
    int size, x, y, count, last_x, last_y;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);

    int square[size][size];

    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            square[x][y] = 0;
        }
    }

    x = size / 2;
    y = 0;
    square[x][y] = 1;

    count = 2;

    while (count <= size * size) {
        last_x = x;
        last_y = y;

        if (last_x + 1 >= size)
            x = 0;
        else
            x = last_x + 1;
        
        if (last_y - 1 < 0)
            y = size - 1;
        else
            y = last_y - 1;
        
        if (square[x][y] == 0) {
            square[x][y] = count++;
        } else {
            if (last_y + 1 >= size)
                square[x = last_x][y = 0] = count++;
            else
                square[x = last_x][y = last_y + 1] = count++;
        }
    }

    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            printf("%4d", square[x][y]);
        }
        printf("\n");
    }

    return 0;
}