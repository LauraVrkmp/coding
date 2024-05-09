#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};

char digits[4][MAX_DIGITS * 4];


int main(void)
{
    int position = 0;
    char c;

    clear_digits_array();

    printf("Enter a number: ");

    while ((c = getchar()) != '\n') {
        if (isdigit(c)){
            process_digit(c - '0', position);
            position += 4;
        }
    }

    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
    }
}

void process_digit(int digit, int position)
{
    for (int i = 0; i < 7; i++) {
        if (segments[digit][i]) {
            switch (i) {
                case 0:
                    digits[0][1 + position] = '_';
                    break;
                case 1:
                    digits[1][2 + position] = '|';
                    break;
                case 2:
                    digits[2][2 + position] = '|';
                    break;
                case 3:
                    digits[2][1 + position] = '_';
                    break;
                case 4:
                    digits[2][0 + position] = '|';
                    break;
                case 5:
                    digits[1][0 + position] = '|';
                    break;
                case 6:
                    digits[1][1 + position] = '_';
                    break;
            }
        }
    }
}

void print_digits_array(void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < MAX_DIGITS * 4; j++)
            printf("%c", digits[i][j]);
        printf("\n");
    }
}