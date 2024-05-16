#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c, words = 0;
    bool in_word = false;

    if (argc != 2) {
        fprintf(stderr, "usage: ./a.exe file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    } else {
        while ((c = fgetc(fp)) != EOF)
            if (isspace(c))
                in_word = false;
            else if (!in_word) {
                in_word = true;
                words++;
            }
        fclose(fp);
    }

    printf("The file has %d words.\n", words);
    return 0;
}