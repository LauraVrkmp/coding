#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

void run_length_encode(int *input, int size, FILE *outputFile);

int main(int argc, char *argv[])
{
    FILE *input_file, *output_file;

    char dummy_char;
    int i, c, item_count, space_count = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: ./a.exe file\n");
        exit(EXIT_FAILURE);
    }

    if ((input_file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char new_file_name[100];
    snprintf(new_file_name, sizeof(new_file_name), "%s.rle", argv[1]);

    if ((output_file = fopen(new_file_name, "w")) == NULL) {
        fprintf(stderr, "Can't open %s\n", new_file_name);
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

    run_length_encode(hex_values, item_count, output_file);

    fclose(input_file);
    fclose(output_file);
    return 0;
}

void run_length_encode(int *input, int size, FILE *outputFile) {
    char current = input[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (input[i] == current) {
            count++;
        } else {
            fprintf(outputFile, "%02d %02X ", count, current);
            current = input[i];
            count = 1;
        }
    }
    
    fprintf(outputFile, "%02d %02X\n", count, current);
}