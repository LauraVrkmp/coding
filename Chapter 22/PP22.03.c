#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int i;
    FILE *fp;
    bool open_fail = false;
    char c;

    if (argc < 2) {
        printf("usage: canopen filename filename2 ...\n");
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
            open_fail = true;
        } else {
            while ((c = fgetc(fp)) != EOF) {
                fputc(c, stdout);
            }
            fputc('\n', stdout);
            fclose(fp);
        }
    }

    if (open_fail)
        exit(EXIT_FAILURE);

    exit(EXIT_SUCCESS);
}