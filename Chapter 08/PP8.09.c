#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIMENSION 10

int main(void)
{
    char board[DIMENSION][DIMENSION];
    char letter = 'A';
    int m = 0, n = 0, up = 0, down = 0, left = 0, right = 0, move = 0;
    int i, j;

    for (i = 0; i < DIMENSION; i++) {
        for (j = 0; j < DIMENSION; j++) {
            board[i][j] = '.';
        }
    }

    board[m][n] = letter++;

    // up is 0, right is 1, down is 2, left is 3

    srand((unsigned) time(NULL));

    while (letter <= 'Z') {
        up = down = left = right = move = 0;

        if (m + 1 < DIMENSION && board[m + 1][n] == '.')
            right = 1;
        if (m - 1 >= 0 && board[m - 1][n] == '.')
            left = 1;
        if (n + 1 < DIMENSION && board[m][n + 1] == '.')
            up = 1;
        if (n - 1 >= 0 && board[m][n - 1] == '.')
            down = 1;

        if (up + down + left + right == 0)
            break;

        move = rand() % 4;

        switch (move) {
            case 0:
                if (up) {
                    board[m][++n] = letter++;
                    break;
                }
            case 1:
                if (right) {
                    board[++m][n] = letter++;
                    break;
                }
            case 2:
                if (down) {
                    board[m][--n] = letter++;
                    break;
                }
            case 3:
                if (left) {
                    board[--m][n] = letter++;
                    break;
                }
            default:
                break;
        }
    };

    for (i = 0; i < DIMENSION; i++) {
        for (j = 0; j < DIMENSION; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}