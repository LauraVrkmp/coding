#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int c;

    if (argc != 2) {
        fprintf(stderr, "usage: ./a.exe file\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fp)) != EOF) {
        fputc(toupper(c), stdout);
    }

    fclose(fp);
    return 0;
}