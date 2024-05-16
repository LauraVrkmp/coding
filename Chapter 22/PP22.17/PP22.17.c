#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 20

int main(int argc, char *argv[])
{
    FILE *input, *output;
    char number[MAX_LENGTH], formatted[MAX_LENGTH], i, j;

    if (argc != 3) {
        char *file_name = strrchr(argv[0], '\\');
        file_name++;
        fprintf(stderr, "Usage: %s file_in file_out\n", file_name);
        exit(EXIT_FAILURE);
    }

    if ((input = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    
    if ((output = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(number, sizeof(number), input) != NULL) {
        i = 0, j = 0;

        for (; number[i] != '\0'; i++) {
            if (j == 0)
                formatted[j++] = '(';
            if (j == 4) {
                formatted[j++] = ')';
                formatted[j++] = ' ';
            }
            if (j == 9)
                formatted[j++] = '-';
            if (isdigit(number[i])) {
                formatted[j++] = number[i];
            }
        }

        formatted[j] = '\0';
        strcpy(number, formatted);
        fprintf(output, "%s\n", number);
    }

    fclose(input);
    fclose(output);
    return 0;
}