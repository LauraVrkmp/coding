#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *file_in, *file_out;
    int orig_char, new_char;

    if (argc != 3) {
        fprintf(stderr, "usage: ./a.exe file_in file_out\n");
        exit(EXIT_FAILURE);
    }

    if ((file_in = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((file_out = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((orig_char = fgetc(file_in)) != EOF) {
        new_char = orig_char ^ KEY;
        fputc(new_char, file_out);
    }
    
    fclose(file_in);
    fclose(file_out);
    return 0;
}