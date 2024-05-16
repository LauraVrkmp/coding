#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void run_length_decode(int *input, int size, FILE *output_file);

int main(int argc, char *argv[])
{
    FILE *input_file, *output_file;

    char dummy_char, *extension;
    int i, c, item_count, space_count = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: ./a.exe file\n");
        exit(EXIT_FAILURE);
    }

    if ((input_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    extension = strrchr(argv[1], '.');
    if (strcmp(extension, ".rle") != 0) {
        printf("Filename doesn't have the correct extension (.rle)\n");
        exit(EXIT_FAILURE);
    }
    *extension = '\0';

    if ((output_file = fopen(argv[1], "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(input_file)) != EOF)
        if (c == ' ')
            space_count++;
    item_count = space_count + 1;

    rewind(input_file);
    int hex_values[item_count];

    for (i = 0; i < item_count - 1; i++) {
        fscanf(input_file, "%x%c", &hex_values[i], &dummy_char);
    }
    fscanf(input_file, "%x", &hex_values[i]);

    run_length_decode(hex_values, item_count, output_file);

    fclose(input_file);
    fclose(output_file);
    return 0;
}

void run_length_decode(int *input, int size, FILE *output_file) {
    int i, j, k = input[size - 2];

    for (i = 0; i < size - 1; i += 2) {
        for (j = 0; j < input[i]; j++) {
            if (i == size - 2 && j == k - 1)
                fprintf(output_file, "%x", input[i + 1]);
            else fprintf(output_file, "%x ", input[i + 1]);
        }
    }
}