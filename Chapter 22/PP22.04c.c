#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c, lines = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: ./a.exe file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    } else {
        while ((c = fgetc(fp)) != EOF)
            if (c == '\n')
                lines++;
        lines++;
        fclose(fp);
    }

    printf("The file has %d lines.\n", lines);
    return 0;
}