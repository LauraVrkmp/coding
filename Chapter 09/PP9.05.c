#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void)
{   
    int size;
    
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);

    char magic_square[size][size];

    create_magic_square(size, magic_square);
    print_magic_square(size, magic_square);

    return 0;
}

void create_magic_square(int size, char magic_square[size][size])
{
    int x, y, last_x, last_y, count;
    
    for (x = 0; x < size; x++) {
        for (y = 0; y < size; y++) {
            magic_square[x][y] = 0;
        }
    }

    x = size / 2;
    y = 0;
    magic_square[x][y] = 1;

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
        
        if (magic_square[x][y] == 0) {
            magic_square[x][y] = count++;
        } else {
            if (last_y + 1 >= size)
                magic_square[x = last_x][y = 0] = count++;
            else
                magic_square[x = last_x][y = last_y + 1] = count++;
        }
    }
}

void print_magic_square(int size, char magic_square[size][size])
{
    int x, y;
    
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            printf("%4d", magic_square[x][y]);
        }
        printf("\n");
    }
}